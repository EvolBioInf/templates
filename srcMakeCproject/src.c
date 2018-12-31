/***** src.c **************************************
 * Description: 
 * Author: Bernhard Haubold, haubold@evolbio.mpg.de
 * Date: Sun Dec 23 15:11:11 2018
 **************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "eprintf.h"
#include "interface.h"
#include "makeCproject.h"
#include "common.h"

void printPrintSplash(FILE *fp, Args *args) {
  fprintf(fp, "\nvoid printSplash(Args *args) {\n");
  fprintf(fp, "  printf(\"%%s \", progname());\n");
  fprintf(fp, "  int l = strlen(VERSION);\n");
  fprintf(fp, "  for(int i = 0; i < l - 1; i++)\n");
  fprintf(fp, "    printf(\"%%c\", VERSION[i]);\n");
  fprintf(fp, "  printf(\", %%s\\n\", DATE);\n");
  fprintf(fp, "  printf(\"Author: %s\\n\");\n", args->a);
  if(args->l)
    fprintf(fp, "  printf(\"License: %s\\n\");\n", args->l);
  if(args->e)
    fprintf(fp, "  printf(\"Bugs: %s\\n\");\n", args->e);
  fprintf(fp, "  exit(0);\n");
  fprintf(fp, "}\n");
}

static void printFile(char *text, char *fileName, char *progName, Args *args, int pps) {
  char *buf = (char *)emalloc(256 * sizeof(char));
  sprintf(buf, "%s/src/%s", progName, fileName);
  FILE *fp = efopen(buf, "w");
  if(args)
    printCheader(fp, fileName, args);
  replaceStr(fp, text, progName);
  if(pps)
    printPrintSplash(fp, args);
  fclose(fp);
  free(buf);
}

void makeSrc(char *progName, Args *args) {
  char *buf = (char *)emalloc(256 * sizeof(char));
  char *m =
#include "main.txt"
    ;
  char *c =
#include "interfaceC.txt"
    ;
  char *h =
#include "interfaceH.txt"
    ;
  char *k =
#include "MakefileSrc.txt"
    ;
  char *v =
#include "valgrind.txt"
    ;
  sprintf(buf, "mkdir -p %s/src", progName);
  int status = system(buf);
  if(status < 0) {
    fprintf(stderr, "ERROR in makeSrc.\n");
    exit(-1);
  }

  sprintf(buf, "%s.c",        progName);
  printFile(m, buf,           progName, args, 0);
  printFile(c, "interface.c", progName, args, 1);
  printFile(h, "interface.h", progName, args, 0);
  printFile(k, "Makefile",    progName, NULL, 0);
  printFile(v, "valgrind.sh", progName, NULL, 0);

  free(buf);
}

