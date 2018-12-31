CC=gcc
export VERSION = $(shell bash ../scripts/version.sh) 
export DATE    = $(shell bash ../scripts/date.sh) 
CFLAGS         = -DVERSION=\"$(VERSION)\" -DDATE=\"$(DATE)\" -O3 -Wall -Wshadow -pedantic -std=gnu99 -g -I../common/ -L../common/ #-pg

SRCFILES  = testProject.c interface.c
OBJFILES  = testProject.o interface.o
LIBS      = -lcommon
EXECFILE  = testProject

.PHONY : all
all : $(EXECFILE)
$(EXECFILE) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(EXECFILE) $(OBJFILES) $(LIBS)
interface.o: interface.h

clean:
	rm -f *.o *~
test:
	bash ../scripts/testProject.sh 
