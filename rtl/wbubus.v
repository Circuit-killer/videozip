////////////////////////////////////////////////////////////////////////////////
//
// Filename:	wbubus.v
//
// Project:	FPGA library
//
// Purpose:	This is the top level file for the entire JTAG-USB to Wishbone
//		bus conversion.  (It's also the place to start debugging, should
//	things not go as planned.)  Bytes come into this routine, bytes go out,
//	and the wishbone bus (external to this routine) is commanded in between.
//
//
//
// Creator:	Dan Gisselquist, Ph.D.
//		Gisselquist Technology, LLC
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2015-2016, Gisselquist Technology, LLC
//
// This program is free software (firmware): you can redistribute it and/or
// modify it under the terms of  the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTIBILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// License:	GPL, v3, as defined and found on www.gnu.org,
//		http://www.gnu.org/licenses/gpl.html
//
//
////////////////////////////////////////////////////////////////////////////////
//
//
`default_nettype	none
//
`define	HAS_CONSOLE_PORT
module	wbubus(i_clk, i_rx_stb, i_rx_data, 
		o_wb_cyc, o_wb_stb, o_wb_we, o_wb_addr, o_wb_data,
		i_wb_ack, i_wb_stall, i_wb_err, i_wb_data,
		i_interrupt,
		o_tx_stb, o_tx_data, i_tx_busy,
`ifdef	HAS_CONSOLE_PORT
		i_console_stb, i_console_data, o_console_busy,
		o_console_stb, o_console_data,
`endif
		o_dbg);
	parameter	LGWATCHDOG=19;
	input	wire		i_clk;
	input	wire		i_rx_stb;
	input	wire	[7:0]	i_rx_data;
	output	wire		o_wb_cyc, o_wb_stb, o_wb_we;
	output	wire	[31:0]	o_wb_addr, o_wb_data;
	input	wire		i_wb_ack, i_wb_stall, i_wb_err;
	input	wire	[31:0]	i_wb_data;
	input	wire		i_interrupt;
	output	wire		o_tx_stb;
	output	wire	[7:0]	o_tx_data;
	input	wire		i_tx_busy;
	//
`ifdef	HAS_CONSOLE_PORT
	input	wire		i_console_stb;
	input	wire	[6:0]	i_console_data;
	output	wire		o_console_busy;
	//
	output	reg		o_console_stb;
	output	reg	[6:0]	o_console_data;
`endif
	//
	output	wire		o_dbg;




	always @(posedge i_clk)
		o_console_stb <= (i_console_stb)&&(i_rx_data[7] == 1'b0);
	always @(posedge i_clk)
		o_console_data <= i_rx_data[6:0];



	reg		r_wdt_reset;

	// Decode ASCII input requests into WB bus cycle requests
	wire		in_stb;
	wire	[35:0]	in_word;
	wbuinput	getinput(i_clk, (i_rx_stb)&&(i_rx_data[7]), { 1'b0, i_rx_data[6:0] }, in_stb, in_word);

	wire	w_bus_busy, fifo_in_stb, exec_stb, w_bus_reset;
	wire	[35:0]	fifo_in_word, exec_word;
// `define	NO_INPUT_FIFO
`ifdef	NO_INPUT_FIFO
	assign	fifo_in_stb = in_stb;
	assign	fifo_in_word = in_word;
	assign	w_bus_reset = 1'b0;
`else
	wire		ififo_empty_n, ififo_err;
	assign	fifo_in_stb = (~w_bus_busy)&&(ififo_empty_n);
	assign	w_bus_reset = r_wdt_reset;
	wbufifo	#(36,6) padififo(i_clk, w_bus_reset,
				in_stb, in_word, fifo_in_stb, fifo_in_word,
				ififo_empty_n, ififo_err);
`endif

	// Take requests in, Run the bus, send results out
	// This only works if no requests come in while requests
	// are pending.
	wbuexec	runwb(i_clk, r_wdt_reset, fifo_in_stb, fifo_in_word, w_bus_busy,
		o_wb_cyc, o_wb_stb, o_wb_we, o_wb_addr, o_wb_data,
		i_wb_ack, i_wb_stall, i_wb_err, i_wb_data,
		exec_stb, exec_word);

	reg		ps_full;
	reg	[7:0]	ps_data;
	wire		wbu_tx_stb;
	wire	[7:0]	wbu_tx_data;

	wire		ofifo_err;
	// wire	[30:0]	out_dbg;
	wbuoutput	wroutput(i_clk, w_bus_reset,
			exec_stb, exec_word,
			o_wb_cyc, i_interrupt, exec_stb,
			wbu_tx_stb, wbu_tx_data, ps_full, ofifo_err);

	// Let's now arbitrate between the two outputs
	initial	ps_full = 1'b0;
	always @(posedge i_clk)
		if (!ps_full)
		begin
			if (wbu_tx_stb)
			begin
				ps_full <= 1'b1;
				ps_data <= { 1'b1, wbu_tx_data[6:0] };
			end else if (i_console_stb)
			begin
				ps_full <= 1'b1;
				ps_data <= { 1'b0, i_console_data[6:0] };
			end
		end else if (!i_tx_busy)
			ps_full <= 1'b0;

	assign	o_tx_stb = ps_full;
	assign	o_tx_data = ps_data;
	assign	o_console_busy = (wbu_tx_stb)||(ps_full);

	// Add in a watchdog timer to the bus
	reg	[(LGWATCHDOG-1):0]	r_wdt_timer;
	initial	r_wdt_reset = 1'b0;
	initial	r_wdt_timer = 0;
	always @(posedge i_clk)
		if ((~o_wb_cyc)||(i_wb_ack))
		begin
			r_wdt_timer <= 0;
			r_wdt_reset <= 1'b0;
		end else if (&r_wdt_timer)
		begin
			r_wdt_reset <= 1'b1;
			r_wdt_timer <= 0;
		end else begin
			r_wdt_timer <= r_wdt_timer+{{(LGWATCHDOG-1){1'b0}},1'b1};
			r_wdt_reset <= 1'b0;
		end

	assign	o_dbg = w_bus_reset;

endmodule

