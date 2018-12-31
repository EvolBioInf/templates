CC=gcc
export VERSION = $(shell bash ../scripts/version.sh) 
export DATE    = $(shell bash ../scripts/date.sh) 
CFLAGS         = -DVERSION=\"$(VERSION)\" -DDATE=\"$(DATE)\" -O3 -Wall -Wshadow -pedantic -std=gnu99 -g -I../common/ -L../common/ #-pg

SRCFILES  = makeCfile.c interface.c
OBJFILES  = makeCfile.o interface.o
LIBS      = -lcommon
EXECFILE  = makeCfile

.PHONY : all
all : $(EXECFILE)
$(EXECFILE) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(EXECFILE) $(OBJFILES) $(LIBS)

clean:
	rm -f *.o *~
test:
	bash ../scripts/makeCfile.sh 
