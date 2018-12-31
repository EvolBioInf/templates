/***** doc.c **************************************
 * Description: 
 * Author: Bernhard Haubold, haubold@evolbio.mpg.de
 * Date: Mon Dec 17 16:03:08 2018
 **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "eprintf.h"
#include "makeCproject.h"

static void printFile(char *fileName, char *progName, char *content) {
  char *buf = (char *)emalloc(256 * sizeof(char));
  sprintf(buf, "%s/doc/%s", progName, fileName);
  FILE *fp = efopen(buf, "w");
  fprintf(fp, "%s\\ignorespaces\n", content);
  fclose(fp);
  free(buf);
}

void makeDoc(char *progName, Args *args) {
  char *buf = (char *)emalloc(256 * sizeof(char));
  char *str =
#include "doc.txt"
    ;
  sprintf(buf, "mkdir -p %s/doc", progName);
  int status = system(buf);
  if(status < 0) {
    fprintf(stderr, "ERROR in makeDoc.\n");
    exit(-1);
  }
  sprintf(buf, "%s/doc/%s.tex", progName, progName);
  FILE *fp = efopen(buf, "w");
  replaceStr(fp, str, progName);
  fclose(fp);

  str = 
#include "MakefileDoc.txt"
    ;
  sprintf(buf, "%s/doc/Makefile", progName);
  fp = efopen(buf, "w");
  replaceStr(fp, str, progName);
  fclose(fp);

  printFile("author.tex",      progName, args->a);
  printFile("email.tex",       progName, args->e);
  printFile("repo.tex",        progName, args->r);

  free(buf);
}
