/***** util.c *************************************
 * Description: 
 * Author: Bernhard Haubold, haubold@evolbio.mpg.de
 * Date: Sun Dec 23 15:46:28 2018
 **************************************************/
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "eprintf.h"
#include "makeCproject.h"

/* replaceStr replaces PROGVAR by progName in str 
 * and prints the result to the open file fp
 */
void replaceStr(FILE *fp, char *str, char *progName) {
  char *pt;
  pt = str;
  /* replace all occurrences of PROGVAR by progName */
  while((str = strstr(str, PROGVAR)) != NULL) {
    int l = str - pt;
    for(int i = 0; i < l; i++)
      fprintf(fp, "%c", pt[i]);
    fprintf(fp, "%s", progName);
    str += strlen(PROGVAR);
    pt = str;
  }
  fprintf(fp, "%s", pt);
}
