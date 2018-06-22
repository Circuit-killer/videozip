////////////////////////////////////////////////////////////////////////////////
//
// Filename:	./regdefs.cpp
//
// Project:	VideoZip, a ZipCPU SoC supporting video functionality
//
// DO NOT EDIT THIS FILE!
// Computer Generated: This file is computer generated by AUTOFPGA. DO NOT EDIT.
// DO NOT EDIT THIS FILE!
//
// CmdLine:	../../../autofpga/trunk/sw/autofpga ../../../autofpga/trunk/sw/autofpga -d -o . global.txt bkram.txt buserr.txt clkcounter.txt dlyarbiter.txt flash.txt gpio.txt icape.txt mdio.txt enet.txt pic.txt pwrcount.txt rtcdate.txt rtcgps.txt spio.txt version.txt wbmouse.txt wboledbw.txt wbpmic.txt wbuconsole.txt zipmaster.txt gps.txt sdspi.txt hdmi.txt xdc.txt xpander.txt sdvidram.txt genclk.txt vidarbiter.txt zipscope.txt
//
// Creator:	Dan Gisselquist, Ph.D.
//		Gisselquist Technology, LLC
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2017-2018, Gisselquist Technology, LLC
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
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include "regdefs.h"

const	REGNAME	raw_bregs[] = {
	{ R_MIC_DATA        ,	"MICD"         	},
	{ R_MIC_CTRL        ,	"MICC"         	},
	{ R_EDID_SCOPC      ,	"ESCOPC"       	},
	{ R_EDID_SCOPC      ,	"ESCOPE"       	},
	{ R_EDID_SCOPD      ,	"ESCOPD"       	},
	{ R_SCOP_HDMIIN_CTRL,	"HINSCOPC"     	},
	{ R_SCOP_HDMIIN_CTRL,	"HINSCOPE"     	},
	{ R_SCOP_HDMIIN_DATA,	"HINSCOPD"     	},
	{ R_SDSPI_SCOPC     ,	"SDSCOPC"      	},
	{ R_SDSPI_SCOPC     ,	"SDSCOPE"      	},
	{ R_SDSPI_SCOPD     ,	"SDSCOPD"      	},
	{ R_ZIPSCOPE        ,	"ZIPSCOPE"     	},
	{ R_ZIPSCOPED       ,	"ZIPSCOPED"    	},
	{ R_QSPI_EREG       ,	"QSPIE"        	},
	{ R_QSPI_CREG       ,	"QSPIC"        	},
	{ R_QSPI_SREG       ,	"QSPIS"        	},
	{ R_QSPI_IDREG      ,	"QSPII"        	},
	{ R_GPSU_SETUP      ,	"GPSSETUP"     	},
	{ R_GPSU_FIFO       ,	"GPSFIFO"      	},
	{ R_GPSU_UARTRX     ,	"GPSRX"        	},
	{ R_GPSU_UARTTX     ,	"GPSTX"        	},
	{ R_SDSPI_CTRL      ,	"SDCARD"       	},
	{ R_SDSPI_DATA      ,	"SDDATA"       	},
	{ R_SDSPI_FIFOA     ,	"SDFIFOA"      	},
	{ R_SDSPI_FIFOA     ,	"SDFIF0"       	},
	{ R_SDSPI_FIFOA     ,	"SDFIFA"       	},
	{ R_SDSPI_FIFOB     ,	"SDFIFOB"      	},
	{ R_SDSPI_FIFOB     ,	"SDFIF1"       	},
	{ R_SDSPI_FIFOB     ,	"SDFIFB"       	},
	{ R_CONSOLE_FIFO    ,	"UFIFO"        	},
	{ R_CONSOLE_UARTRX  ,	"RX"           	},
	{ R_CONSOLE_UARTTX  ,	"TX"           	},
	{ R_NET_RXCMD       ,	"RXCMD"        	},
	{ R_NET_RXCMD       ,	"NETRX"        	},
	{ R_NET_TXCMD       ,	"TXCMD"        	},
	{ R_NET_TXCMD       ,	"NETTX"        	},
	{ R_NET_MACHI       ,	"MACHI"        	},
	{ R_NET_MACLO       ,	"MACLO"        	},
	{ R_NET_RXMISS      ,	"NETMISS"      	},
	{ R_NET_RXERR       ,	"NETERR"       	},
	{ R_NET_RXCRC       ,	"NETCRCERR"    	},
	{ R_NET_TXCOL       ,	"NETCOL"       	},
	{ R_BUSERR          ,	"BUSERR"       	},
	{ R_BUSERR          ,	"BUSERR"       	},
	{ R_PIC             ,	"PIC"          	},
	{ R_PIC             ,	"PIC"          	},
	{ R_HDMI_INCLK      ,	"HCLKIN"       	},
	{ R_HDMI_INCLK      ,	"HCLKIN"       	},
	{ R_HDMI_OUTCLK     ,	"HCLKOUT"      	},
	{ R_HDMI_OUTCLK     ,	"HCLKOUT"      	},
	{ R_DATE            ,	"RTCDATE"      	},
	{ R_DATE            ,	"DATE"         	},
	{ R_DATE            ,	"RTCDATE"      	},
	{ R_DATE            ,	"DATE"         	},
	{ R_GENCLK          ,	"GENCLK"       	},
	{ R_GENCLK          ,	"GENCLK"       	},
	{ R_GENCLKFB        ,	"GENCLKFB"     	},
	{ R_GENCLKFB        ,	"GENCLKFB"     	},
	{ R_GPIO            ,	"GPIO"         	},
	{ R_GPIO            ,	"GPI"          	},
	{ R_GPIO            ,	"GPO"          	},
	{ R_GPIO            ,	"GPIO"         	},
	{ R_GPIO            ,	"GPI"          	},
	{ R_GPIO            ,	"GPO"          	},
	{ R_FRAME_OFFSET    ,	"FRAMEOFFSET"  	},
	{ R_FRAME_OFFSET    ,	"FRAMEOFFSET"  	},
	{ R_PWRCOUNT        ,	"PWRCOUNT"     	},
	{ R_PWRCOUNT        ,	"PWRCOUNT"     	},
	{ R_SPIO            ,	"SPIO"         	},
	{ R_SPIO            ,	"SPIO"         	},
	{ R_SYSCLK          ,	"SYSCLK"       	},
	{ R_SYSCLK          ,	"SYSCLK"       	},
	{ R_VERSION         ,	"VERSION"      	},
	{ R_VERSION         ,	"VERSION"      	},
	{ R_CFG_CRC         ,	"FPGACRC"      	},
	{ R_CFG_FAR         ,	"FPGAFAR"      	},
	{ R_CFG_FDRI        ,	"FPGAFDRI"     	},
	{ R_CFG_FDRO        ,	"FPGAFDRO"     	},
	{ R_CFG_CMD         ,	"FPGACMD"      	},
	{ R_CFG_CTL0        ,	"FPGACTL0"     	},
	{ R_CFG_MASK        ,	"FPGAMASK"     	},
	{ R_CFG_STAT        ,	"FPGASTAT"     	},
	{ R_CFG_LOUT        ,	"FPGALOUT"     	},
	{ R_CFG_COR0        ,	"FPGACOR0"     	},
	{ R_CFG_MFWR        ,	"FPGAMFWR"     	},
	{ R_CFG_CBC         ,	"FPGACBC"      	},
	{ R_CFG_IDCODE      ,	"FPGAIDCODE"   	},
	{ R_CFG_AXSS        ,	"FPGAAXSS"     	},
	{ R_CFG_COR1        ,	"FPGACOR1"     	},
	{ R_CFG_WBSTAR      ,	"WBSTAR"       	},
	{ R_CFG_TIMER       ,	"CFGTIMER"     	},
	{ R_CFG_BOOTSTS     ,	"BOOTSTS"      	},
	{ R_CFG_CTL1        ,	"FPGACTL1"     	},
	{ R_CFG_BSPI        ,	"FPGABSPI"     	},
	{ R_MDIO_BMCR       ,	"BMCR"         	},
	{ R_MDIO_BMSR       ,	"BMSR"         	},
	{ R_MDIO_PHYIDR1    ,	"PHYIDR1"      	},
	{ R_MDIO_PHYIDR2    ,	"PHYIDR2"      	},
	{ R_MDIO_ANAR       ,	"ANAR"         	},
	{ R_MDIO_ANLPAR     ,	"ANLPAR"       	},
	{ R_MDIO_ANER       ,	"ANER"         	},
	{ R_MDIO_ANNPTR     ,	"ANNPTR"       	},
	{ R_MDIO_ANNPRR     ,	"ANNPRR"       	},
	{ R_MDIO_GBCR       ,	"GBCR"         	},
	{ R_MDIO_GBSR       ,	"GBSR"         	},
	{ R_MDIO_MACR       ,	"MACR"         	},
	{ R_MDIO_MAADR      ,	"MAADR"        	},
	{ R_MDIO_GESR       ,	"GESR"         	},
	{ R_MDIO_PHYCR      ,	"PHYCR"        	},
	{ R_MDIO_PHYSR      ,	"PHYSR"        	},
	{ R_MDIO_INER       ,	"INER"         	},
	{ R_MDIO_INSR       ,	"INSR//"       	},
	{ R_MDIO_INSR       ,	"20-23"        	},
	{ R_MDIO_INSR       ,	"are"          	},
	{ R_MDIO_INSR       ,	"reserved"     	},
	{ R_MDIO_RXERC      ,	"RXERC//"      	},
	{ R_MDIO_RXERC      ,	"25-26"        	},
	{ R_MDIO_RXERC      ,	"are"          	},
	{ R_MDIO_RXERC      ,	"reserved"     	},
	{ R_MDIO_LDPSR      ,	"LDPSR"        	},
	{ R_MDIO_EPAGSR     ,	"EPAGSR"       	},
	{ R_MDIO_PAGSEL     ,	"PAGSEL//"     	},
	{ R_XMDIO_PC1R      ,	"XPC1R"        	},
	{ R_XMDIO_PS1R      ,	"XPS1R"        	},
	{ R_XMDIO_EEECR     ,	"XEEECR"       	},
	{ R_XMDIO_EEEWER    ,	"XEEEWER"      	},
	{ R_XMDIO_EEEAR     ,	"XEEEAR"       	},
	{ R_XMDIO_EEELPAR   ,	"XEEELPAR"     	},
	{ R_XMDIO_LACR      ,	"XLACR"        	},
	{ R_XMDIO_LCR       ,	"XLCR"         	},
	{ R_GPS_ALPHA       ,	"ALPHA"        	},
	{ R_GPS_BETA        ,	"BETA"         	},
	{ R_GPS_GAMMA       ,	"GAMMA"        	},
	{ R_GPS_STEP        ,	"STEP"         	},
	{ R_GPS_ALPHA       ,	"ALPHA"        	},
	{ R_GPS_BETA        ,	"BETA"         	},
	{ R_GPS_GAMMA       ,	"GAMMA"        	},
	{ R_GPS_STEP        ,	"STEP"         	},
	{ R_MOUSE_STAT      ,	"MSTAT"        	},
	{ R_MOUSE_RAW       ,	"MRAW"         	},
	{ R_SCRN_MOUSE      ,	"MOUSE"        	},
	{ R_SCRN_SIZE       ,	"MSIZ"         	},
	{ R_MOUSE_STAT      ,	"MSTAT"        	},
	{ R_MOUSE_RAW       ,	"MRAW"         	},
	{ R_SCRN_MOUSE      ,	"MOUSE"        	},
	{ R_SCRN_SIZE       ,	"MSIZ"         	},
	{ R_OLED_CMD        ,	"OLED"         	},
	{ R_OLED_CDATA      ,	"OLEDCA"       	},
	{ R_OLED_CDATB      ,	"OLEDCB"       	},
	{ R_OLED_DATA       ,	"ODATA"        	},
	{ R_OLED_CMD        ,	"OLED"         	},
	{ R_OLED_CDATA      ,	"OLEDCA"       	},
	{ R_OLED_CDATB      ,	"OLEDCB"       	},
	{ R_OLED_DATA       ,	"ODATA"        	},
	{ R_CLOCK           ,	"CLOCK"        	},
	{ R_CLOCK           ,	"TIMER"        	},
	{ R_TIMER           ,	"TIMER"        	},
	{ R_STOPWATCH       ,	"STOPWATCH"    	},
	{ R_CKALARM         ,	"ALARM"        	},
	{ R_CKALARM         ,	"CKALARM"      	},
	{ R_CLOCK           ,	"CLOCK"        	},
	{ R_CLOCK           ,	"TIMER"        	},
	{ R_TIMER           ,	"TIMER"        	},
	{ R_STOPWATCH       ,	"STOPWATCH"    	},
	{ R_CKALARM         ,	"ALARM"        	},
	{ R_CKALARM         ,	"CKALARM"      	},
	{ R_GPSTB_FREQ      ,	"GPSFREQ"      	},
	{ R_GPSTB_JUMP      ,	"GPSJUMP"      	},
	{ R_GPSTB_ERRHI     ,	"ERRHI"        	},
	{ R_GPSTB_ERRLO     ,	"ERRLO"        	},
	{ R_GPSTB_COUNTHI   ,	"CNTHI"        	},
	{ R_GPSTB_COUNTLO   ,	"CNTLO"        	},
	{ R_GPSTB_STEPHI    ,	"STEPHI"       	},
	{ R_GPSTB_STEPLO    ,	"STEPLO"       	},
	{ R_GPSTB_FREQ      ,	"GPSFREQ"      	},
	{ R_GPSTB_JUMP      ,	"GPSJUMP"      	},
	{ R_GPSTB_ERRHI     ,	"ERRHI"        	},
	{ R_GPSTB_ERRLO     ,	"ERRLO"        	},
	{ R_GPSTB_COUNTHI   ,	"CNTHI"        	},
	{ R_GPSTB_COUNTLO   ,	"CNTLO"        	},
	{ R_GPSTB_STEPHI    ,	"STEPHI"       	},
	{ R_GPSTB_STEPLO    ,	"STEPLO"       	},
	{ R_HIN_FRAMEADDR   ,	"HINFRAME"     	},
	{ R_HIN_ORIGIN      ,	"HINORIGIN"    	},
	{ R_HIN_MAXSZ       ,	"HINMAXSZ"     	},
	{ R_HIN_BYTESPLINE  ,	"HINBYTESPLINE"	},
	{ R_HIN_SYNC_CTRL   ,	"HINSYNCC"     	},
	{ R_HIN_SYNC_CTRL   ,	"HINDLY"       	},
	{ R_HIN_SLIP        ,	"HINSYNCM"     	},
	{ R_HIN_SLIP        ,	"HINMANUALSYNC"	},
	{ R_HIN_SLIP        ,	"HINMSYNC"     	},
	{ R_HIN_SLIP        ,	"HINSLIP"      	},
	{ R_HIN_SYNC_DATA   ,	"HINSYNCD"     	},
	{ R_HIN_SYNC_DATA   ,	"HINSYNCDATA"  	},
	{ R_HIN_SYNC_DATA   ,	"HINSYNC"      	},
	{ R_HIN_SYNCQ       ,	"HINSYNCQ"     	},
	{ R_HIN_CKWORD      ,	"HINCW"        	},
	{ R_HIN_CKWORD      ,	"HINCKWORD"    	},
	{ R_HIN_CKWORD      ,	"HINPIXCLK"    	},
	{ R_HIN_COLUMNS     ,	"HINCOLS"      	},
	{ R_HIN_ROWS        ,	"HINROWS"      	},
	{ R_HIN_HMODE       ,	"HINHMODE"     	},
	{ R_HIN_VMODE       ,	"HINVMODE"     	},
	{ R_HIN_FRAMEADDR   ,	"HINFRAME"     	},
	{ R_HIN_ORIGIN      ,	"HINORIGIN"    	},
	{ R_HIN_MAXSZ       ,	"HINMAXSZ"     	},
	{ R_HIN_BYTESPLINE  ,	"HINBYTESPLINE"	},
	{ R_HIN_SYNC_CTRL   ,	"HINSYNCC"     	},
	{ R_HIN_SYNC_CTRL   ,	"HINDLY"       	},
	{ R_HIN_SLIP        ,	"HINSYNCM"     	},
	{ R_HIN_SLIP        ,	"HINMANUALSYNC"	},
	{ R_HIN_SLIP        ,	"HINMSYNC"     	},
	{ R_HIN_SLIP        ,	"HINSLIP"      	},
	{ R_HIN_SYNC_DATA   ,	"HINSYNCD"     	},
	{ R_HIN_SYNC_DATA   ,	"HINSYNCDATA"  	},
	{ R_HIN_SYNC_DATA   ,	"HINSYNC"      	},
	{ R_HIN_SYNCQ       ,	"HINSYNCQ"     	},
	{ R_HIN_CKWORD      ,	"HINCW"        	},
	{ R_HIN_CKWORD      ,	"HINCKWORD"    	},
	{ R_HIN_CKWORD      ,	"HINPIXCLK"    	},
	{ R_HIN_COLUMNS     ,	"HINCOLS"      	},
	{ R_HIN_ROWS        ,	"HINROWS"      	},
	{ R_HIN_HMODE       ,	"HINHMODE"     	},
	{ R_HIN_VMODE       ,	"HINVMODE"     	},
	{ R_EDID_IN         ,	"EDIN"         	},
	{ R_EDID_IN         ,	"EDIN"         	},
	{ R_EDID_CMD        ,	"EDCMD"        	},
	{ R_EDID_SPD        ,	"EDSPD"        	},
	{ R_EDID_OUT        ,	"EDOUT"        	},
	{ R_EDID_CMD        ,	"EDCMD"        	},
	{ R_EDID_SPD        ,	"EDSPD"        	},
	{ R_EDID_OUT        ,	"EDOUT"        	},
	{ R_NET_RXBUF       ,	"NETRXB"       	},
	{ R_NET_TXBUF       ,	"NETTXB"       	},
	{ R_BKRAM           ,	"RAM"          	},
	{ R_FLASH           ,	"FLASH"        	},
	{ R_SDRAM           ,	"SDRAM"        	}
};

// REGSDEFS.CPP.INSERT for any bus masters
// And then from the peripherals
// And finally any master REGS.CPP.INSERT tags
#define	RAW_NREGS	(sizeof(raw_bregs)/sizeof(bregs[0]))

const	REGNAME		*bregs = raw_bregs;
const	int	NREGS = RAW_NREGS;

unsigned	addrdecode(const char *v) {
	if (isalpha(v[0])) {
		for(int i=0; i<NREGS; i++)
			if (strcasecmp(v, bregs[i].m_name)==0)
				return bregs[i].m_addr;
#ifdef	R_ZIPCTRL
		if (strcasecmp(v, "CPU")==0)
			return R_ZIPCTRL;
#endif	// R_ZIPCTRL
#ifdef	R_ZIPDATA
		if (strcasecmp(v, "CPUD")==0)
			return R_ZIPDATA;
#endif	// R_ZIPDATA
		fprintf(stderr, "Unknown register: %s\n", v);
		exit(-2);
	} else
		return strtoul(v, NULL, 0);
}

const	char *addrname(const unsigned v) {
	for(int i=0; i<NREGS; i++)
		if (bregs[i].m_addr == v)
			return bregs[i].m_name;
	return NULL;
}

