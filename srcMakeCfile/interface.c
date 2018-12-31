/***** interface.c **********************************************************
 * Description: Interface for program to generate C source files.
 * Author: Bernhard Haubold.
 * Institution: Max-Planck-Institute for Evolutionary Biology
 * Email: haubold@evolbio.mpg.de
 * License: GNU General Public License, https://www.gnu.org/licenses/gpl.html
 * Date: Fri Dec 28 09:21:04 2018
 ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "interface.h"
#include "eprintf.h"

Args *newArgs() {
  Args *args = (Args *)emalloc(sizeof(Args));
  args->err = 0;
  args->h   = 0;
  args->v   = 0;
  args->w   = 0;
  args->a   = NULL;
  args->l   = NULL;
  args->e   = NULL;
  args->d   = NULL;
  args->D   = NULL;

  return args;
}

void freeArgs(Args *args) {
  free(args);
}

Args *getArgs(int argc, char *argv[]) {
  Args *args = newArgs();
  int c;

  char *optString = "hva:e:i:l:m:d:D:w:";

  opterr = 0;
  while ((c = getopt(argc, argv, optString)) != -1) {
    switch (c) {
    case 'a': /* author      */
      args->a = optarg;
      break;
    case 'd': /* date        */
      args->d = optarg;
      break;
    case 'e': /* email        */
      args->e = optarg;
      break;
    case 'D': /* description  */
      args->D = optarg;
      break;
    case 'w': /* header width */
      args->w = atoi(optarg);
      if(args->w < 0)
	args->w *= -1;
      break;
    case 'l':
      args->l = optarg;
      break;
    case 'h':
      args->h = 1;
      break;
    case 'v':
      args->v = 1;
      break;
    case '?':
      args->err = 1;
      if(optopt == 'e' || optopt == 'l' || optopt == 'd' || optopt == 'D')
	fprintf(stderr, "Error: Option `%c` requires an argument.\n", optopt);
      else if(isprint(optopt))
	fprintf(stderr, "Error: Unknown option `%c`.\n", optopt);
      else
	fprintf(stderr, "Error: Unknown option character `\\x%x`.\n", optopt);
    default:
      args->err = 1;
      return args;
    }
  }
  args->fi = argv + optind;
  args->nf = argc - optind;
  if(args->nf < 1 && !(args->h || args->v)) {
    fprintf(stderr, "Error: Please enter at least one file name.\n");
    args->err = 1;
  }
  if(args->l) {
    if(strcmp(args->l, "gpl") == 0)
      args->l = "GNU General Public License, https://www.gnu.org/licenses/gpl.html";
    else if(strcmp(args->l, "lgpl") == 0)
      args->l = "GNU Lesser General Public License, https://www.gnu.org/licenses/lgpl.html";
  }

  return args;
}

void printUsage() {
  printf("Usage: %s [options] [fileNames]\n", progname());
  printf("Generate C-style code files\n");
  printf("Example: ./%s -a \"Ada Lovelace\" -e \"ada@byron.org\" -l gpl foo1.c foo2.c\n", progname());
  printf("Options:\n");
  printf("\t -a <STR> author\n");
  printf("\t[-d <STR> description; default: dummy string]\n");
  printf("\t[-e <STR> email; default: none]\n");
  printf("\t[-l <STR> license, gpl|lgpl|<freeText>; default: none]\n");
  printf("\t[-D <STR> date; default: automatic time stamp]\n");
  printf("\t[-w <NUM> header width; default: longest header string]\n");
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
  printf("Author: Bernhard Haubold\n");
  printf("Bugs: haubold@evolbio.mpg.de\n");
  printf("License: GNU General Public License, https://www.gnu.org/licenses/gpl.html\n");
  exit(0);
}
