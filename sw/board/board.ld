/*******************************************************************************
*
* Filename:	./board.ld
*
* Project:	VideoZip, a ZipCPU SoC supporting video functionality
*
* DO NOT EDIT THIS FILE!
* Computer Generated: This file is computer generated by AUTOFPGA. DO NOT EDIT.
* DO NOT EDIT THIS FILE!
*
* CmdLine:	../../../autofpga/trunk/sw/autofpga ../../../autofpga/trunk/sw/autofpga -o . global.txt bkram.txt buserr.txt clkcounter.txt dlyarbiter.txt flash.txt gpio.txt icape.txt mdio.txt pic.txt pwrcount.txt rtcdate.txt rtcgps.txt spio.txt version.txt wbmouse.txt wboledbw.txt wbpmic.txt wbuconsole.txt zipmaster.txt gps.txt sdspi.txt hdmi.txt xdc.txt xpander.txt sdvidram.txt genclk.txt vidarbiter.txt
*
* Creator:	Dan Gisselquist, Ph.D.
*		Gisselquist Technology, LLC
*
/*******************************************************************************
*
* Copyright (C) 2017, Gisselquist Technology, LLC
*
* This program is free software (firmware): you can redistribute it and/or
* modify it under the terms of  the GNU General Public License as published
* by the Free Software Foundation, either version 3 of the License, or (at
* your option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTIBILITY or
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
* for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program.  (It's in the $(ROOT)/doc directory.  Run make with no
* target there if the PDF file isn't present.)  If not, see
* <http://www.gnu.org/licenses/> for a copy.
*
* License:	GPL, v3, as defined and found on www.gnu.org,
*		http://www.gnu.org/licenses/gpl.html
*
*
/*******************************************************************************
*
*
*/
ENTRY(_start)

MEMORY
{
	   bkram(wx) : ORIGIN = 0x1a000000, LENGTH = 0x00100000
	   flash(rx) : ORIGIN = 0x1c000000, LENGTH = 0x01000000
	   sdram(wx) : ORIGIN = 0x20000000, LENGTH = 0x20000000
}

_bkram    = ORIGIN(bkram);
_flash    = ORIGIN(flash);
_sdram    = ORIGIN(sdram);
SECTIONS
{
	.rocode 0x1c400000 : ALIGN(4) {
		_boot_address = .;
		*(.start) *(.boot)
	} > flash
	_kernel_image_start = . ;
	_kernel_image_end = . ;
	_ram_image_start = . ;
	.ramcode : ALIGN_WITH_INPUT {
		*(.kernel)
		*(.text.startup)
		*(.text*)
		*(.rodata*) *(.strings)
		*(.data) *(COMMON)
		}> sdram AT> flash
	_ram_image_end = . ;
	.bss : ALIGN_WITH_INPUT {
		*(.bss)
		_bss_image_end = . ;
		} > sdram
	_top_of_heap = .;
}
