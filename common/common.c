/***** common.c *************************************************************
 * Description: Code common to the "templates" package.
 * Author: Bernhard Haubold
 * License: GNU General Public License, https://www.gnu.org/licenses/gpl.html
 * Date: Mon Dec 31 16:22:45 2018
 ****************************************************************************/
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "eprintf.h"
#include "common.h"

void printCheader(FILE *fp, char *fn, Args *args) {
  int hw, l2;
  char *email = NULL;
  char *license = NULL;

  int l1 = fprintf(fp, "/***** %s ", fn);
  char *date = (char *)emalloc(256 * sizeof(char));
  if(!args->D) {
    time_t t  = time(&t);
    char *time = ctime(&t);
    char *p = strchr(time, '\n');
    *p = '\0';
    l2 = sprintf(date, " * Date: %s", time);
  } else
    l2 = sprintf(date, " * Date: %s", args->D);
  char *author = (char *)emalloc(256 * sizeof(char));
  int l3 = sprintf(author, " * Author: %s", args->a);
  if(l3 > l2) l2 = l3;
  char *description = (char *)emalloc(256 * sizeof(char));
  if(args->d) {
    l3 = sprintf(description, " * Description: %s", args->d);
  } else {
    l3 = sprintf(description, " * Description: <Description>");
  }
  if(l3 > l2) l2 = l3;
  if(args->e) {
    email = (char *)emalloc(256 * sizeof(char));
    l3 = sprintf(email, " * Email: %s", args->e);
    if(l3 > l2) l2 = l3;
  }
  if(args->l) {
    license = (char *)emalloc(256 * sizeof(char));
    l3 = sprintf(license, " * License: %s", args->l);
    if(l3 > l2) l2 = l3;
  }
  if(args->w)
    hw = args->w;
  else if(l2 > l1)
    hw = l2;
  else
    hw = 70;

  for(int i = 0; i < hw - l1; i++)
    fprintf(fp, "*");
  fprintf(fp, "\n");
  fprintf(fp, "%s\n", description);
  free(description);
  fprintf(fp, "%s\n", author);
  free(author);
  if(email) {
    fprintf(fp, "%s\n", email);
    free(email);
  }
  if(license) {
    fprintf(fp, "%s\n", license);
    free(license);
  }
  fprintf(fp, "%s\n", date);
  free(date);
  fprintf(fp, " ");
  if(hw <= 1)
    hw++;
  for(int i = 1; i < hw; i++)
    fprintf(fp,"*");
  fprintf(fp,"/\n");
}
