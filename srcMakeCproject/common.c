/***** common.c ***********************************
 * Description: 
 * Author: Bernhard Haubold, haubold@evolbio.mpg.de
 * Date: Sun Dec 23 14:57:49 2018
 **************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "eprintf.h"

static void printFile(char *text, char *fileName, char *progName) {
  char *buf = (char *)emalloc(256 * sizeof(char));
  sprintf(buf, "%s/common/%s", progName, fileName);
  FILE *fp = efopen(buf, "w");
  fprintf(fp, "%s", text);
  fclose(fp);
  free(buf);
}

void makeCommon(char *progName) {
  char *buf = (char *)emalloc(256 * sizeof(char));
  char *c =
#include "eprintfC.txt"
    ;
  char *h =
#include "eprintfH.txt"
    ;
  char *m =
#include "MakefileCommon.txt"
    ;
  sprintf(buf, "mkdir -p %s/common", progName);
  int status = system(buf);
  free(buf);
  if(status < 0) {
    fprintf(stderr, "ERROR in makeCommon.\n");
    exit(-1);
  }

  printFile(c, "eprintf.c", progName);
  printFile(h, "eprintf.h", progName);
  printFile(m, "Makefile",  progName);
}
