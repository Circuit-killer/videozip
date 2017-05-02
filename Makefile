################################################################################
##
## Filename:	Makefile
##
## Project:	VideoZip, a ZipCPU SoC supporting video functionality
##
## Purpose:	A master project makefile.  It tries to build all targets
##		within the project, mostly by directing subdirectory makes.
##
##
## Creator:	Dan Gisselquist, Ph.D.
##		Gisselquist Technology, LLC
##
################################################################################
##
## Copyright (C) 2015, Gisselquist Technology, LLC
##
## This program is free software (firmware): you can redistribute it and/or
## modify it under the terms of  the GNU General Public License as published
## by the Free Software Foundation, either version 3 of the License, or (at
## your option) any later version.
##
## This program is distributed in the hope that it will be useful, but WITHOUT
## ANY WARRANTY; without even the implied warranty of MERCHANTIBILITY or
## FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
## for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program.  (It's in the $(ROOT)/doc directory.  Run make with no
## target there if the PDF file isn't present.)  If not, see
## <http://www.gnu.org/licenses/> for a copy.
##
## License:	GPL, v3, as defined and found on www.gnu.org,
##		http://www.gnu.org/licenses/gpl.html
##
##
################################################################################
##
##
.PHONY: all
all:	archive datestamp autodata rtl sim sw
# all:	verilated sw bench bit
#
# Could also depend upon load, if desired, but not necessary
SIM := `find sim -name Makefile` `find sim -name "*.cpp"` `find sim -name "*.h"`
RTL   := `find rtl -name "*.v"` `find rtl -name Makefile`
NOTES := `find . -name "*.txt"` `find . -name "*.html"`
SW    := `find sw -name "*.cpp"` `find sw -name "*.c"`	\
	`find sw -name "*.h"`	`find sw -name "*.sh"`	\
	`find sw -name "*.py"`	`find sw -name "*.pl"`	\
	`find sw -name "*.png"`	`find sw -name Makefile`
DEVSW := `find sw-board -name "*.cpp"` `find sw-board -name "*.h"` \
	`find sw-board -name Makefile`
PROJ  := 
BIN  := `find xilinx -name "*.bit"`
CONSTRAINTS := nexysv.xdc
YYMMDD:=`date +%Y%m%d`

.PHONY: datestamp
datestamp:
	@bash -c 'if [ ! -e $(YYMMDD)-build.v ]; then rm -f 20??????-build.v; perl mkdatev.pl > $(YYMMDD)-build.v; rm -f rtl/builddate.v; fi'
	@bash -c 'if [ ! -e rtl/builddate.v ]; then cd rtl; cp ../$(YYMMDD)-build.v builddate.v; fi'

.PHONY: archive
archive:
	tar --transform s,^,$(YYMMDD)-video/, -chjf $(YYMMDD)-video.tjz $(BENCH) $(SW) $(RTL) $(NOTES) $(PROJ) $(BIN) $(CONSTRAINTS)

.PHONY: autodata
autodata:
	$(MAKE) --no-print-directory --directory=auto-data
	$(call copyif-changed,auto-data/toplevel.v,rtl/toplevel.v)
	$(call copyif-changed,auto-data/main.v,rtl/main.v)
	$(call copyif-changed,auto-data/regdefs.h,sw/host/regdefs.h)
	$(call copyif-changed,auto-data/regdefs.cpp,sw/host/regdefs.cpp)
	$(call copyif-changed,auto-data/board.h,sw/board/board.h)
	$(call copyif-changed,auto-data/board.ld,sw/board/board.ld)

.PHONY: verilated
verilated: datestamp autodata
	$(MAKE) --no-print-directory --directory=rtl

.PHONY: rtl
rtl: verilated

.PHONY: sim
sim: rtl
	$(MAKE) --no-print-directory --directory=sim/verilated

.PHONY: sw
sw: sw-host sw-board

.PHONY: sw-host
sw-host:
	$(MAKE) --no-print-directory --directory=sw/host

.PHONY: sw-board
sw-board:
	$(MAKE) --no-print-directory --directory=sw/board

define	copyif-changed
	@bash -c 'cmp $(1) $(2); if [[ $$? != 0 ]]; then echo "Copying $(1) to $(2)"; cp $(1) $(2); fi'
endef


# .PHONY: bit
# bit:
#	cd xilinx ; $(MAKE) --no-print-directory xula.bit

