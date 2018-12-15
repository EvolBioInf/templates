/***** makeCproject.c *****************************
 * Description: 
 * Author: Bernhard Haubold, haubold@evolbio.mpg.de
 * Date: Sat Dec 15 18:14:30 2018
 **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "eprintf.h"

void scanFile(FILE *fp, Args *args){
  printf("hello, world\n");
}

int main(int argc, char *argv[]){
  int i;
  char *version;
  Args *args;
  FILE *fp;

  setprogname2("makeCproject");
  args = getArgs(argc, argv);
  if(args->v)
    printSplash(version);
  if(args->h || args->e)
    printUsage(version);
  if(args->numInputFiles == 0){
    fp = stdin;
    char *t =
#include "txt.txt"
      ;
    printf("%s\n", t);
    fclose(fp);
  }else{
    for(i=0;i<args->numInputFiles;i++){
      fp = efopen(args->inputFiles[i],"r");
      char *t =
#include "txt.txt"
	;
      printf("%s\n", t);
      fclose(fp);
    }
  }
  free(args);
  free(progname());
  return 0;
}

