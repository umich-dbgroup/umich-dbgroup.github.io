# --------------------------------------------------------------------------- #
# Dave Richerby's wonderful LaTeX makefile                                    #
# --------------------------------------------------------------------------- #

# This makefile is in the public domain.  Do whatever you want with it
# but be aware that it is provided ``as is'' without any express or
# implied warranty.
#
# Please mail comments or suggestions to davidr@chiark.greenend.org.uk
#
# Examples of usage:
#   ``make foo.ps'':    compile foo.tex to PostScript
#   ``make foo'':       compile foo.tex to PostScript and view it
#   ``make foo.ps.gz'': compile foo.tex to PostScript and compress it
#
# Warning: don't cut and paste this file from your browser as it will
# probably convert all the tabs to spaces.  The make program needs
# them to be tabs.
#
# Changes:
#
# 2000-10-18: Added PDF output (thanks to chrisw@chiark.greenend.org.uk)
# 2000-10-12: Original version


#
# Set this to your PostScript viewer
#
#VIEWER=gsview32
VIEWER=xdvi

#
# If you want a default action, put it here.  E.g. ``default: foo.ps''
# will cause make to produce foo.ps when run without arguments
#
default: broken

#
# If you have any documents which include other files, list them here, e.g.
#
#   sample.dvi: sample.tex diagram.eps
#
# If you need to continue onto a second line, end the first with a '\'
# character
#


# --------------------------------------------------------------------------- #
# You shouldn't need to change anything below this point unless you're        #
# extending the functionality of the makefile.                                #
# --------------------------------------------------------------------------- #

clean:
	rm -f *.log *.dvi *.ps *.toc *.aux *.eepic *.bak

%.dvi: %.tex 
	@echo
	@echo \*
	@echo \* Compiling $<
	@echo \*
	latex  $<
	bibtex $*
	@while ( grep "Rerun to get cross-references"                   \
			$(subst .tex,.log,$<) >/dev/null ); do          \
		echo '** Re-running LaTeX **';                          \
		latex $<;                                               \
	done

%.ps: %.dvi 
	@echo
	@echo \*
	@echo \* Converting $< to PostScript
	@echo \*
	dvips -o $@ $<

%.pdf: %.dvi
	@echo
	@echo \*
	@echo \* Converting $< to PDF
	@echo \*
	dvips -o - -Ppdf $< | ps2pdf - $@

%: %.ps
	@echo
	@echo \*
	@echo \* Spawning viewer for $<
	@echo \*
	$(VIEWER) $<

%.gz: %
	@echo
	@echo \*
	@echo \* Compressing $<
	@echo \*
	gzip $<

%.eps: %.obj
	@echo
	@echo \*
	@echo \* Producing Encapsulated PostScript for $<
	@echo \*
	tgif -print -eps -color $<

%.eepic: %.fig
	@echo
	@echo \*
	@echo \* Producing EEPIC for $<
	@echo \*
	fig2dev -L eepic $< $@

# Stop GNU make from overzealous deletion of intermediate files
.PRECIOUS: %.ps %.dvi %.eps






