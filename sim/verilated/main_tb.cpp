////////////////////////////////////////////////////////////////////////////////
//
// Filename:	./main_tb.cpp
//
// Project:	VideoZip, a ZipCPU SoC supporting video functionality
//
// DO NOT EDIT THIS FILE!
// Computer Generated: This file is computer generated by AUTOFPGA. DO NOT EDIT.
// DO NOT EDIT THIS FILE!
//
// CmdLine:	../../../autofpga/trunk/sw/autofpga ../../../autofpga/trunk/sw/autofpga -o . global.txt bkram.txt buserr.txt clkcounter.txt clock.txt dlyarbiter.txt flash.txt gpio.txt icape.txt mdio.txt pic.txt pwrcount.txt rtcdate.txt rtcgps.txt spio.txt version.txt wbmouse.txt wboledbw.txt wbpmic.txt busconsole.txt zipmaster.txt gps.txt sdspi.txt
//
// Creator:	Dan Gisselquist, Ph.D.
//		Gisselquist Technology, LLC
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2017, Gisselquist Technology, LLC
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
// You should have received a copy of the GNU General Public License along
// with this program.  (It's in the $(ROOT)/doc directory.  Run make with no
// target there if the PDF file isn't present.)  If not, see
// <http://www.gnu.org/licenses/> for a copy.
//
// License:	GPL, v3, as defined and found on www.gnu.org,
//		http://www.gnu.org/licenses/gpl.html
//
//
////////////////////////////////////////////////////////////////////////////////
//
//
//
// SIM.INCLUDE
//
// Looking for string: SIM.INCLUDE
#include "verilated.h"
#include "Vmain.h"
#define	BASECLASS	Vmain

#include "design.h"
#include "regdefs.h"
#include "testb.h"
#include "sdspisim.h"
#include "uartsim.h"
#include "qspiflashsim.h"
#include "byteswap.h"
#include "dblpipecmdr.h"
#include "zipelf.h"

// Looking for string: SIM.DEFINES
#define	sd_cmd_busy	v__DOT__sdcardi__DOT__r_cmd_busy
#define	sd_clk		v__DOT__sdcardi__DOT__r_sdspi_clk
#define	sd_cmd_state	v__DOT__sdcardi__DOT__r_cmd_state
#define	sd_rsp_state	v__DOT__sdcardi__DOT__r_rsp_state
#define	sd_ll_cmd_stb	v__DOT__sdcard__DOT__ll_cmd_stb
#define	sd_ll_cmd_dat	v__DOT__sdcard__DOT__ll_cmd_dat
#define	sd_ll_z_counter	v__DOT__sdcard__DOT__lowlevel__DOT__r_z_counter
#define	sd_ll_clk_counter	v__DOT__sdcard__DOT__lowlevel__DOT__r_clk_counter
#define	sd_ll_idle	v__DOT__sdcard__DOT__lowlevel__DOT__r_idle
#define	sd_ll_state	v__DOT__sdcard__DOT__lowlevel__DOT__r_state
#define	sd_ll_byte	v__DOT__sdcard__DOT__lowlevel__DOT__r_byte
#define	sd_ll_ireg	v__DOT__sdcard__DOT__lowlevel__DOT__r_ireg
#define	sd_ll_out_stb	v__DOT__sdcard__DOT__ll_out_stb
#define	sd_ll_out_dat	v__DOT__sdcard__DOT__ll_out_dat
#define	sd_lgblklen	v__DOT__sdcard__DOT__r_lgblklen
#define	sd_fifo_rd_crc	v__DOT__sdcard__DOT__fifo_rd_crc_reg
#define	sd_cmd_crc	v__DOT__sdcard__DOT__r_cmd_crc,
#define	sd_cmd_crc_cnt	v__DOT__sdcard__DOT__r_cmd_crc_cnt
#define	sd_fifo_rd_crc_stb	v__DOT__sdcard__DOT__fifo_rd_crc_stb
#define	ll_fifo_pkt_state	v__DOT__sdcard__DOT__ll_fifo_pkt_state
#define	sd_have_data_response_token	v__DOT__sdcard__DOT__r_have_data_response_token
#define	sd_fifo_wr_crc		v__DOT__sdcard__DOT__fifo_wr_crc_reg
#define	sd_fifo_wr_crc_stb	v__DOT__sdcard__DOT__fifo_wr_crc_stb,
#define	sd_ll_fifo_wr_state	v__DOT__sdcard__DOT__ll_fifo_wr_state,
#define	sd_ll_fifo_wr_complete	v__DOT__sdcard__DOT__ll_fifo_wr_complete
#define	sd_use_fifo	v__DOT__sdcard__DOT__r_use_fifo
#define	sd_fifo_wr	v__DOT__sdcard__DOT__r_fifo_wr

#define	block_ram	v__DOT__bkrami__DOT__mem
#define	PARENT	DBLPIPECMDR<BASECLASS>
#define	cpu_break 	v__DOT__swic__DOT__cpu_break
#define	cpu_cmd_halt	v__DOT__swic__DOT__cmd_halt
#define	cpu_ipc		v__DOT__swic__DOT__thecpu__DOT__ipc
#define	cpu_upc		v__DOT__swic__DOT__thecpu__DOT__r_upc
#define	cpu_gie		v__DOT__swic__DOT__thecpu__DOT__r_gie
#define	cpu_iflags	v__DOT__swic__DOT__thecpu__DOT__w_iflags
#define	cpu_uflags	v__DOT__swic__DOT__thecpu__DOT__w_uflags
#define	cpu_regs	v__DOT__swic__DOT__thecpu__DOT__regset
#define	cpu_cmd_addr	v__DOT__swic__DOT__cmd_addr
#define	cpu_bus_err	v__DOT__swic__DOT__thecpu__DOT__bus_err
#define	cpu_ibus_err	v__DOT__swic__DOT__thecpu__DOT__ibus_err_flag
#define	cpu_ubus_err	v__DOT__swic__DOT__thecpu__DOT__r_ubus_err_flag
#define	cpu_mem_rdaddr	v__DOT__swic__DOT__thecpu__DOT__domem__DOT__rdaddr
#define	cpu_mem_wraddr	v__DOT__swic__DOT__thecpu__DOT__domem__DOT__wraddr
#define	cpu_op_sim	v__DOT__swic__DOT__thecpu__DOT__op_sim
#define	cpu_op_valid	v__DOT__swic__DOT__thecpu__DOT__op_valid
#define	cpu_alu_ce	v__DOT__swic__DOT__thecpu__DOT__alu_ce
#define	cpu_new_pc	v__DOT__swic__DOT__thecpu__DOT__new_pc
#define	cpu_sim_immv	v__DOT__swic__DOT__thecpu__DOT__op_sim_immv

class	MAINTB : public PARENT {
public:
	bool	m_done;
// Looking for string: SIM.DEFNS
#ifdef	SDSPI_ACCESS
	SDSPISIM	m_sdcard;
#endif
#ifdef	GPSUART_ACCESS
	UARTSIM	*m_gpsu;
#endif
#ifdef	FLASH_ACCESS
	QSPIFLASHSIM	*m_flash;
#endif
	int	m_cpu_bombed;
	MAINTB(void) {
		m_done = false;
		// From sdcard
#ifdef	SDSPI_ACCESS
		m_sdcard.debug(false);
#endif	// SDSPI_ACCESS
		// From gpsu
#ifdef	GPSUART_ACCESS
		m_gpsu = new UARTSIM(FPGAPORT+2);
		m_gpsu->setup(0x000028b0);
#endif
		// From flash
#ifdef	FLASH_ACCESS
	m_flash = new QSPIFLASHSIM(FLASHLGLEN);
#endif
		// From zip
		m_cpu_bombed = 0;
	}

	void	reset(void) {
// Looking for string: SIM.SETRESET
		m_core->i_cpu_reset = 1;
		m_core->i_clk = 1;
		m_core->eval();
// Looking for string: SIM.CLRRESET
		m_core->i_cpu_reset = 0;
	}

	void	trace(const char *vcd_trace_file_name) {
		fprintf(stderr, "Opening TRACE(%s)\n",
				vcd_trace_file_name);
		opentrace(vcd_trace_file_name);
		m_time_ps = 0;
	}

	void	close(void) {
		m_done = true;
	}

	void	tick(void) {
		if (m_done)
			return;
// Looking for string: SIM.TICK
#ifdef	SDSPI_ACCESS
		m_core->i_sd_data = m_sdcard((m_core->o_sd_data&8)?1:0,
				m_core->o_sd_sck, m_core->o_sd_cmd);
		m_core->i_sd_data &= 1;
		m_core->i_sd_data |= (m_core->o_sd_data&0x0e);
		m_core->i_sd_detect = 1;
#endif	// SDSPI_ACCESS
#ifdef	GPSUART_ACCESS
		m_core->i_gpsu_rx = m_gpsu->tick(m_core->o_gpsu_tx);
#else
		m_core->i_gpsu_rx = 1;
#endif

#ifdef	FLASH_ACCESS
		m_core->i_qspi_dat = (*m_flash)(m_core->o_qspi_cs_n,
			m_core->o_qspi_sck, m_core->o_qspi_dat);
#endif
#ifdef	INCLUDE_ZIPCPU
		// ZipCPU Sim instruction support
		if ((m_core->cpu_op_sim)
			&&(m_core->cpu_op_valid)
			&&(m_core->cpu_alu_ce)
			&&(!m_core->cpu_new_pc)) {
			//
			execsim(m_core->cpu_sim_immv);
		}

		if (m_core->v__DOT__swic__DOT__cpu_break) {
			printf("\n\nBOMB : CPU BREAK RECEIVED\n");
			m_cpu_bombed++;
			dump(m_core->cpu_regs);
		} else if (m_cpu_bombed) {
			if (m_cpu_bombed++ > 12)
				m_done = true;
		}
#endif	// INCLUDE_ZIPCPU

		PARENT::tick();

		bool	writeout = false;

// Looking for string: SIM.DBGCONDITION

		if (writeout) {
// Looking for string: SIM.DEBUG
			/*
			printf(" SDSPI[%d,%d(%d),(%d)]",
				m_core->sd_cmd_busy,
				m_core->sd_clk,
				m_core->sd_cmd_state,
				m_core->sd_rsp_state);
			printf(" LL[%d,%2x->CK=%d/%2x,%s,ST=%2d,TX=%2x,RX=%2x->%d,%2x] ",
				m_core->sd_ll_cmd_stb,
				m_core->sd_ll_cmd_dat,
				m_core->sd_ll_z_counter,
				// (m_core->sd_ll_clk_counter==0)?1:0,
				m_core->sd_ll_clk_counter,
				(m_core->sd_ll_idle)?"IDLE":"    ",
				m_core->sd_ll_state,
				m_core->sd_ll_byte,
				m_core->sd_ll_ireg,
				m_core->sd_ll_out_stb,
				m_core->sd_ll_out_dat
				);
			printf(" CRC=%02x/%2d",
				m_core->sd_cmd_crc,
				m_core->sd_cmd_crc_cnt);
			printf(" SPI(%d,%d,%d/%d,%d)->?",
				m_core->o_sf_cs_n,
				m_core->o_sd_cs_n,
				m_core->o_spi_sck,
				m_core->v__DOT__sdcard_sck,
				m_core->o_spi_mosi);

			printf(" CK=%d,LN=%d",
				m_core->sd_clk,
				m_core->sd_lgblklen);


			if (m_core->sd_use_fifo){
				printf(" FIFO");
				if (m_core->sd_fifo_wr)
					printf("-WR(%04x,%d,%d,%d)",
						m_core->sd_fifo_rd_crc,
						m_core->sd_fifo_rd_crc_stb,
						m_core->sd_ll_fifo_pkt_state,
						m_core->sd_have_data_response_token);
				else
					printf("-RD(%04x,%d,%d,%d)",
						m_core->sd_fifo_wr_crc,
						m_core->sd_fifo_wr_crc_stb,
						m_core->sd_ll_fifo_wr_state,
						m_core->sd_ll_fifo_wr_complete
						);
			}
			*/

		}
// Looking for string: SIM.TICK
#ifdef	SDSPI_ACCESS
		m_core->i_sd_data = m_sdcard((m_core->o_sd_data&8)?1:0,
				m_core->o_sd_sck, m_core->o_sd_cmd);
		m_core->i_sd_data &= 1;
		m_core->i_sd_data |= (m_core->o_sd_data&0x0e);
		m_core->i_sd_detect = 1;
#endif	// SDSPI_ACCESS
#ifdef	GPSUART_ACCESS
		m_core->i_gpsu_rx = m_gpsu->tick(m_core->o_gpsu_tx);
#else
		m_core->i_gpsu_rx = 1;
#endif

#ifdef	FLASH_ACCESS
		m_core->i_qspi_dat = (*m_flash)(m_core->o_qspi_cs_n,
			m_core->o_qspi_sck, m_core->o_qspi_dat);
#endif
#ifdef	INCLUDE_ZIPCPU
		// ZipCPU Sim instruction support
		if ((m_core->cpu_op_sim)
			&&(m_core->cpu_op_valid)
			&&(m_core->cpu_alu_ce)
			&&(!m_core->cpu_new_pc)) {
			//
			execsim(m_core->cpu_sim_immv);
		}

		if (m_core->v__DOT__swic__DOT__cpu_break) {
			printf("\n\nBOMB : CPU BREAK RECEIVED\n");
			m_cpu_bombed++;
			dump(m_core->cpu_regs);
		} else if (m_cpu_bombed) {
			if (m_cpu_bombed++ > 12)
				m_done = true;
		}
#endif	// INCLUDE_ZIPCPU

	}

	bool	load(uint32_t addr, const char *buf, uint32_t len) {
		uint32_t	start, offset, wlen, base, naddr;

		base  = 0x01000000;
		naddr = 0x00400000;

		if ((addr >= base)&&(addr < base + naddr)) {
			// If the start access is in flash
			start = (addr > base) ? (addr-base) : 0;
			offset = (start + base) - addr;
			wlen = (len-offset > naddr - start)
				? (naddr - start) : len - offset;
#ifdef	FLASH_ACCESS
			// FROM flash.SIM.LOAD
			m_flash->load(start, &buf[offset], wlen);
			// AUTOFPGA::Now clean up anything else
			// Was there more to write than we wrote?
			if (addr + len > base + naddr)
				return load(base + naddr, &buf[offset+wlen], len-wlen);
			return true;
#else	// FLASH_ACCESS
			return false;
#endif	// FLASH_ACCESS
		}

		base  = 0x00100000;
		naddr = 0x00040000;

		if ((addr >= base)&&(addr < base + naddr)) {
			// If the start access is in bkram
			start = (addr > base) ? (addr-base) : 0;
			offset = (start + base) - addr;
			wlen = (len-offset > naddr - start)
				? (naddr - start) : len - offset;
#ifdef	BKRAM_ACCESS
			// FROM bkram.SIM.LOAD
			start = start & (-4);
			wlen = (wlen+3)&(-4);

			// Need to byte swap data to get it into the memory
			char	*bswapd = new char[len+8];
			memcpy(bswapd, &buf[offset], wlen);
			byteswapbuf(len>>2, (uint32_t *)bswapd);
			memcpy(&m_core->block_ram[start], bswapd, wlen);
			delete	bswapd;
			// AUTOFPGA::Now clean up anything else
			// Was there more to write than we wrote?
			if (addr + len > base + naddr)
				return load(base + naddr, &buf[offset+wlen], len-wlen);
			return true;
#else	// BKRAM_ACCESS
			return false;
#endif	// BKRAM_ACCESS
		}

		return false;
	}

// Looking for string: SIM.METHODS
#ifdef	SDSPI_ACCESS
	void	setsdcard(const char *fn) {
		m_sdcard.load(fn);
	}
#endif

	void	loadelf(const char *elfname) {
		ELFSECTION	**secpp, *secp;
		uint32_t	entry;

		elfread(elfname, entry, secpp);

		for(int s=0; secpp[s]->m_len; s++) {
			secp = secpp[s];

			load(secp->m_start, secp->m_data, secp->m_len);
		}
	}


	bool	gie(void) {
		return (m_core->cpu_gie);
	}

	void dump(const uint32_t *regp) {
		uint32_t	uccv, iccv;
		fflush(stderr);
		fflush(stdout);
		printf("ZIPM--DUMP: ");
		if (gie())
			printf("Interrupts-enabled\n");
		else
			printf("Supervisor mode\n");
		printf("\n");

		iccv = m_core->cpu_iflags;
		uccv = m_core->cpu_uflags;

		printf("sR0 : %08x ", regp[0]);
		printf("sR1 : %08x ", regp[1]);
		printf("sR2 : %08x ", regp[2]);
		printf("sR3 : %08x\n",regp[3]);
		printf("sR4 : %08x ", regp[4]);
		printf("sR5 : %08x ", regp[5]);
		printf("sR6 : %08x ", regp[6]);
		printf("sR7 : %08x\n",regp[7]);
		printf("sR8 : %08x ", regp[8]);
		printf("sR9 : %08x ", regp[9]);
		printf("sR10: %08x ", regp[10]);
		printf("sR11: %08x\n",regp[11]);
		printf("sR12: %08x ", regp[12]);
		printf("sSP : %08x ", regp[13]);
		printf("sCC : %08x ", iccv);
		printf("sPC : %08x\n",regp[15]);

		printf("\n");

		printf("uR0 : %08x ", regp[16]);
		printf("uR1 : %08x ", regp[17]);
		printf("uR2 : %08x ", regp[18]);
		printf("uR3 : %08x\n",regp[19]);
		printf("uR4 : %08x ", regp[20]);
		printf("uR5 : %08x ", regp[21]);
		printf("uR6 : %08x ", regp[22]);
		printf("uR7 : %08x\n",regp[23]);
		printf("uR8 : %08x ", regp[24]);
		printf("uR9 : %08x ", regp[25]);
		printf("uR10: %08x ", regp[26]);
		printf("uR11: %08x\n",regp[27]);
		printf("uR12: %08x ", regp[28]);
		printf("uSP : %08x ", regp[29]);
		printf("uCC : %08x ", uccv);
		printf("uPC : %08x\n",regp[31]);
		printf("\n");
		fflush(stderr);
		fflush(stdout);
	}


	void	execsim(const uint32_t imm) {
		uint32_t	*regp = m_core->cpu_regs;
		int		rbase;
		rbase = (gie())?16:0;

		fflush(stdout);
		if ((imm & 0x03fffff)==0)
			return;
		// fprintf(stderr, "SIM-INSN(0x%08x)\n", imm);
		if ((imm & 0x0fffff)==0x00100) {
			// SIM Exit(0)
			close();
			exit(0);
		} else if ((imm & 0x0ffff0)==0x00310) {
			// SIM Exit(User-Reg)
			int	rcode;
			rcode = regp[(imm&0x0f)+16] & 0x0ff;
			close();
			exit(rcode);
		} else if ((imm & 0x0ffff0)==0x00300) {
			// SIM Exit(Reg)
			int	rcode;
			rcode = regp[(imm&0x0f)+rbase] & 0x0ff;
			close();
			exit(rcode);
		} else if ((imm & 0x0fff00)==0x00100) {
			// SIM Exit(Imm)
			int	rcode;
			rcode = imm & 0x0ff;
			close();
			exit(rcode);
		} else if ((imm & 0x0fffff)==0x002ff) {
			// Full/unconditional dump
			printf("SIM-DUMP\n");
			dump(regp);
		} else if ((imm & 0x0ffff0)==0x00200) {
			// Dump a register
			int rid = (imm&0x0f)+rbase;
			printf("%8lu @%08x R[%2d] = 0x%08x\n", m_time_ps/1000,
			m_core->cpu_ipc, rid, regp[rid]);
		} else if ((imm & 0x0ffff0)==0x00210) {
			// Dump a user register
			int rid = (imm&0x0f);
			printf("%8lu @%08x uR[%2d] = 0x%08x\n", m_time_ps/1000,
				m_core->cpu_ipc,
				rid, regp[rid+16]);
		} else if ((imm & 0x0ffff0)==0x00230) {
			// SOUT[User Reg]
			int rid = (imm&0x0f)+16;
			printf("%c", regp[rid]&0x0ff);
		} else if ((imm & 0x0fffe0)==0x00220) {
			// SOUT[User Reg]
			int rid = (imm&0x0f)+rbase;
			printf("%c", regp[rid]&0x0ff);
		} else if ((imm & 0x0fff00)==0x00400) {
			// SOUT[Imm]
			printf("%c", imm&0x0ff);
		} else { // if ((insn & 0x0f7c00000)==0x77800000)
			uint32_t	immv = imm & 0x03fffff;
			// Simm instruction that we dont recognize
			// if (imm)
			// printf("SIM 0x%08x\n", immv);
			printf("SIM 0x%08x (ipc = %08x, upc = %08x)\n", immv,
				m_core->cpu_ipc,
				m_core->cpu_upc);
		} fflush(stdout);
	}

	bool	done(void) { return m_done; }

};

