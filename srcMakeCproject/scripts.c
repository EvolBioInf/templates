/***** scripts.c **********************************
 * Description: 
 * Author: Bernhard Haubold, haubold@evolbio.mpg.de
 * Date: Sun Dec 23 09:29:50 2018
 **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "eprintf.h"
#include "makeCproject.h"

static void printFile(char *text, char *fileName, char *progName) {
  char *buf = (char *)emalloc(256 * sizeof(char));
  sprintf(buf, "%s/scripts/%s", progName, fileName);
  FILE *fp = efopen(buf, "w");
  replaceStr(fp, text, progName);
  fclose(fp);
  free(buf);
}

void makeScripts(char *progName) {
  char *buf = (char *)emalloc(256 * sizeof(char));
  char *d =
#include "date.txt"
    ;
  char *f =
#include "format.txt"
    ;
  char *v =
#include "version.txt"
    ;
  char *t = 
#include "test.txt"
    ;
  sprintf(buf, "mkdir -p %s/scripts", progName);
  int status = system(buf);
  if(status < 0) {
    fprintf(stderr, "ERROR in makeScripts.\n");
    exit(-1);
  }

  printFile(d, "date.sh",    progName);
  printFile(f, "format.sed", progName);
  printFile(v, "version.sh", progName);
  sprintf(buf, "%s.sh", progName);
  printFile(t, buf,          progName);

  free(buf);
}
