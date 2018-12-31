/***** makeCproject.c *****************************
 * Description: 
 * Author: Bernhard Haubold, haubold@evolbio.mpg.de
 * Date: Sat Dec 15 18:14:30 2018
 **************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "interface.h"
#include "eprintf.h"
#include "makeCproject.h"

/* makeProject generates the direcory p with subdirectories
 *   common, data, doc, scripts, and src
 */
void makeProject(char *p, Args *args) {
  makeData(p);
  makeDoc(p, args);
  makeScripts(p);
  makeCommon(p);
  makeSrc(p, args);
  makeMaster(p, args);
}

int main(int argc, char *argv[]){
  Args *args;

  setprogname2("makeCproject");
  args = getArgs(argc, argv);

  if(args->v)
    printSplash();
  if(args->h || args->err)
    printUsage();
  if(!args->a) {
    fprintf(stderr, "Error: Please enter author name.\n");
    printUsage();
  }
  for(int i = 0; i < args->nf; i++) {
    if(access(args->fi[i], F_OK) == 0) {
      fprintf(stderr, "Error: %s already exists; please delete it first, if you'd like to overwrite it.\n", args->fi[i]);
      continue;
    }
    makeProject(args->fi[i], args);
  }
  free(args);
  free(progname());
  return 0;
}

