/***** master.c ***********************************
 * Description: 
 * Author: Bernhard Haubold, haubold@evolbio.mpg.de
 * Date: Sun Dec 23 17:17:10 2018
 **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "eprintf.h"
#include "interface.h"
#include "makeCproject.h"

void printReadme(char *fileName, char *progName, Args *args) {
  char *buf = (char *)emalloc(256 * sizeof(char));
  sprintf(buf, "%s/%s", progName, fileName);
  FILE *fp = efopen(buf, "w");
  fprintf(fp, "# `%s`\n", progName);
  fprintf(fp, "## Author\n");
  fprintf(fp, "%s, `%s`\n", args->a, args->e);
  fprintf(fp, "## Description\n");
  fprintf(fp, "DESCRIPTION\n");
  fprintf(fp, "## Compile\n");
  fprintf(fp, "Compile the sources using `make`; the executable `%s` is now in the directory `build`\n", progName);
  fprintf(fp, "## Documentation\n");
  fprintf(fp, "The command `make doc` generates the manual `doc/%s.pdf`.\n", progName);
  fprintf(fp, "## License\n");
  fprintf(fp, "%s\n", args->l);
  free(buf);
  fclose(fp);
}

void printMakefile(char *fileName, char *progName, Args *args) {
  char *buf = (char *)emalloc(256 * sizeof(char));
  sprintf(buf, "%s/%s", progName, fileName);
  FILE *fp = efopen(buf, "w");

  fprintf(fp, "all:\n");
  fprintf(fp, "\tmake -C common\n");
  fprintf(fp, "\tmake -C src\n");
  fprintf(fp, "\tmkdir -p build\n");
  fprintf(fp, "\tcp src/%s build\n", progName);
  fprintf(fp, "test:\n");
  fprintf(fp, "\tmake -C src test\n");
  fprintf(fp, "clean:\n");
  fprintf(fp, "\tmake -C common clean\n");
  fprintf(fp, "\tmake -C src    clean\n");
  fprintf(fp, "\tmake -C doc    clean\n");
  fprintf(fp, ".PHONY:	doc\n");
  fprintf(fp, "doc:\n");
  fprintf(fp, "\tmake -C doc\n");

  fclose(fp);
}

/* initGit initializes git integration. */
void initGit(char *progName) {
  char *g =
#include "gitignore.txt"
    ;
  char *buf = (char *)emalloc(256 * sizeof(char));
  sprintf(buf, "%s/.gitignore", progName);
  FILE *fp = efopen(buf, "w");
  replaceStr(fp, g, progName);
  fclose(fp);
  sprintf(buf, "cd %s; git init; git add .; git commit -m \"Initial comit\"; git tag v0.1 -a -m \"First tag, programatically set\"", progName);
  int status = system(buf);
  if(status < 0) {
    fprintf(stderr, "ERROR[initGit]: Git initialization failed; is git installed?\n");
    exit(-1);
  }
  free(buf);
}

void makeMaster(char *progName, Args *args) {
  printReadme("README.md", progName, args);
  char *m =
#include "MakefileMaster.txt"
    ;
  char *buf = (char *)emalloc(256 * sizeof(char));
  sprintf(buf, "%s/Makefile", progName);
  FILE *fp = efopen(buf, "w");
  replaceStr(fp, m, progName);
  fclose(fp);
  free(buf);
  initGit(progName);
}
