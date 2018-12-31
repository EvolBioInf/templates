/***** testProject.c *************************************************
 * Description: DESCRIPTION
 * Author: AUTHOR
 * Institution: INSTITUTION
 * Email: EMAIL
 * License: LICENSE
 * Date: Wed Dec 26 10:19:39 2018
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "eprintf.h"

void scanFile(FILE *fp, Args *args) {
  for(int i = 0; i < args->i; i++)
    printf("Test output.\n");
}

int main(int argc, char *argv[]){
  FILE *fp;
  Args *args = getArgs(argc, argv);
  if(args->v)
    printSplash(args);
  if(args->h || args->e)
    printUsage();
  if(args->nf == 0) {
    fp = stdin;
    scanFile(fp, args);
  } else {
    for(int i = 0; i < args->nf; i++) {
      fp = efopen(args->fi[i], "r");
      scanFile(fp, args);
      fclose(fp);
    }
  }
  freeArgs(args);
  free(progname());
  return 0;
}

