/***** interface.c ***************************************************
 * Description: DESCRIPTION
 * Author: AUTHOR
 * Institution: INSTITUTION
 * Email: EMAIL
 * License: LICENSE
 * Date: Wed Dec 26 10:19:39 2018
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "interface.h"
#include "eprintf.h"

Args *newArgs() {
  Args *args = (Args *)emalloc(sizeof(Args));
  args->h = 0;
  args->v = 0;
  args->e = 0;
  args->i = DEFAULT_I;
  return args;
}

void freeArgs(Args *args) {
  free(args);
}

Args *getArgs(int argc, char *argv[]) {
  int c;
  char *optString = "hvi:";

  Args *args = newArgs();
  c = getopt(argc, argv, optString);
  while(c != -1) {
    switch(c) {
    case 'i':                           /* iterations                 */
      args->i = atoi(optarg);
      break;
    case '?':                           /* fall-through is intentional */
    case 'h':                           /* print help                  */
      args->h = 1;
      break;
    case 'v':                           /* print version               */
      args->v = 1;
      break;
    default:
      printf("# unknown argument: %c\n",c);
      args->e = 1;
      return args;
    }
    c = getopt(argc, argv, optString);
  }
  args->fi = argv + optind;
  args->nf = argc - optind;

  return args;
}

void printUsage() {
  printf("Usage: %s [options] [inputFiles]\n", progname());
  printf("<DESCRIPTION>\n");
  printf("Example: ./%s \n", progname());
  printf("Options:\n");
  printf("\t[-i <NUM> iterations; default: %d]\n", DEFAULT_I);
  printf("\t[-h print this help message and exit]\n");
  printf("\t[-v print version & program information and exit]\n");
  exit(0);
}

void printSplash(Args *args) {
  printf("%s ", progname());
  int l = strlen(VERSION);
  for(int i = 0; i < l - 1; i++)
    printf("%c", VERSION[i]);
  printf(", %s\n", DATE);
  printf("Author: AUTHOR\n");
  printf("License: LICENSE\n");
  printf("Bugs: EMAIL\n");
  exit(0);
}
