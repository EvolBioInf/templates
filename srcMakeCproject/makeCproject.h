/***** makeCproject.h *****************************
 * Description: 
 * Author: Bernhard Haubold, haubold@evolbio.mpg.de
 * Date: Mon Dec 17 16:17:55 2018
 **************************************************/
#ifndef MAKECPROJECT
#define MAKECPROJECT

#include "interface.h"

#define TESTOUT "Test output.\n"
#define PROGVAR "PROGNAME"
#define HEADER_WIDTH 70

/* data.c */
void makeData(char *prog);
/* doc.c */
void makeDoc(char *prog, Args *args);
/* scripts.c */
void makeScripts(char *progName);
/* common.c */
void makeCommon(char *progName);
/* src.c */
void makeSrc(char *progName, Args *args);
/* util.c */
void printHeader(FILE *fp, char *na, Args *args);
void replaceStr(FILE *fp, char *str, char *progName);
/* master.c */
void makeMaster(char *progName, Args *args);

#endif
