TAG     := $(shell git describe | sed 's/-.*//')
DATE    := $(shell git log -1 --format=%ai $(TAG) | sed 's/-/ /g' | awk '{printf "\\\\DTMdisplaydate{%s}{%s}{%s}{-1}\n", $$1, $$2, $$3}')
VERSION := $(shell git describe | sed 's/^[vV]//; s/-.*//')
PROG    := templates
all:
	echo $(VERSION) > version.tex
	echo $(DATE)    > date.tex
	latex  $(PROG)
	# bibtex $(PROG)
	# latex  $(PROG)
	latex  $(PROG)
	dvipdf $(PROG)
clean:	
	rm -f $(PROG).pdf *.log *.bbl *.blg *.dvi
