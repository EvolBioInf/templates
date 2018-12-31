CC=gcc
export VERSION = $(shell bash ../scripts/version.sh) # Keep single trailing blank
export DATE    = $(shell bash ../scripts/date.sh) #    Keep single trailing blank
CFLAGS         = -DVERSION=\"$(VERSION)\" -DDATE=\"$(DATE)\" -O3 -Wall -Wshadow -pedantic -std=gnu99 -g -I../common/ -L../common/ #-pg

SRCFILES  = makeCproject.c interface.c data.c doc.c scripts.c common.c src.c util.c master.c
OBJFILES  = makeCproject.o interface.o data.o doc.o scripts.o common.o src.o util.o master.o
LIBS      = -lcommon
EXECFILE  = makeCproject
DIRECTORY = makeCproject

.PHONY : all
all:	include $(EXECFILE)
$(EXECFILE): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(EXECFILE) $(OBJFILES) $(LIBS)
eprintf.o: eprintf.h
include:
#	doc	
	sed -f ../scripts/format.sed ../data/doc.tex        > ../common/doc.txt
	sed -f ../scripts/format.sed ../data/MakefileDoc    > ../common/MakefileDoc.txt
#	scripts
	sed -f ../scripts/format.sed ../data/date.sh        > ../common/date.txt
	sed -f ../scripts/format.sed ../data/format.sed     > ../common/format.txt
	sed -f ../scripts/format.sed ../data/version.sh     > ../common/version.txt
	sed -f ../scripts/format.sed ../data/test.sh        > ../common/test.txt
#	common
	sed -f ../scripts/format.sed ../data/eprintf.c      > ../common/eprintfC.txt
	sed -f ../scripts/format.sed ../data/eprintf.h      > ../common/eprintfH.txt
	sed -f ../scripts/format.sed ../data/MakefileCommon > ../common/MakefileCommon.txt
#	src
	sed -f ../scripts/format.sed ../data/main.c         > ../common/main.txt
	sed -f ../scripts/format.sed ../data/interface.c    > ../common/interfaceC.txt
	sed -f ../scripts/format.sed ../data/interface.h    > ../common/interfaceH.txt
	sed -f ../scripts/format.sed ../data/MakefileSrc    > ../common/MakefileSrc.txt
	sed -f ../scripts/format.sed ../data/valgrind.sh    > ../common/valgrind.txt
#	master
	sed -f ../scripts/format.sed ../data/MakefileMaster > ../common/MakefileMaster.txt
	sed -f ../scripts/format.sed ../data/gitignore      > ../common/gitignore.txt
clean:
	rm -f *.o *~; rm ../common/*.txt
test:
	bash ../scripts/$(EXECFILE).sh 
tar:
	mkdir $(DIRECTORY)_$(VERSION)
	cp -rf $(SRCFILES) *.h  README.md Makefile ../doc/makeCproject.pdf $(DIRECTORY)_$(VERSION)
	tar cvzfh $(EXECFILE)_$(VERSION).tgz $(DIRECTORY)_$(VERSION)
	mv $(EXECFILE)_$(VERSION).tgz ../
	/bin/rm -r $(DIRECTORY)_$(VERSION)

