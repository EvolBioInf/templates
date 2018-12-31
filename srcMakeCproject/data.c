/***** data.c *************************************
 * Description: 
 * Author: Bernhard Haubold, haubold@evolbio.mpg.de
 * Date: Mon Dec 17 15:41:07 2018
 **************************************************/
#include <stdlib.h>
#include "eprintf.h"
#include "makeCproject.h"

void makeData(char *prog) {
  char *s = emalloc(256 * sizeof(char));
  sprintf(s, "mkdir -p %s/data", prog);
  int status = system(s);
  if(status < 0) {
    fprintf(stderr, "Error in makeData.\n");
    exit(-1);
  }
  sprintf(s, "%s/data/%s.out", prog, prog);
  FILE *fp = fopen(s, "w");
  fprintf(fp, TESTOUT);
  fclose(fp);
  free(s);
}
