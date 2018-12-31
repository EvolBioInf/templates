/***** makeCfile.c **********************************************************
 * Description: Construct a source file for C code.
 * Author: Bernhard Haubold
 * Institution: Max-Planck-Institute for Evolutionary Biology
 * Email: haubold@evolbio.mpg.de
 * License: GNU General Public License, https://www.gnu.org/licenses/gpl.html
 * Date: Fri Dec 28 09:21:04 2018
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "common.h"
#include "interface.h"
#include "eprintf.h"

int main(int argc, char *argv[]){
  FILE *fp;
  Args *args = getArgs(argc, argv);
  setprogname2("makeCfile");
  if(args->v)
    printSplash(args);
  if(args->h || args->err)
    printUsage();
  if(!args->a) {
    fprintf(stderr, "Error: Please enter author name.\n");
    printUsage();
  }
  if(args->nf == 0) {
    fp = stdin;
    printCheader(fp, "stdin", args);
  } else {
    for(int i = 0; i < args->nf; i++) {
      if(access(args->fi[i], F_OK) == 0) {
	fprintf(stderr, "Error: %s already exists; if you'd like to replace it, please delete it first.\n", args->fi[i]);
	continue;
      }
      fp = efopen(args->fi[i], "w");
      printCheader(fp, args->fi[i], args);
      fclose(fp);
    }
  }
  freeArgs(args);
  return 0;
}

