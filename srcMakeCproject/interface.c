/***** interface.c ************************************************
 * Description: Routine for gathering arguments from the command
 *              line.
 * Author: Bernhard Haubold, haubold@evolbio.mpg.de
 * Date: Sun Jun 20 13:12:10 2004.
 *****************************************************************/
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
  args->r   = NULL;
  return args;
}

Args *getArgs(int argc, char *argv[]){
  Args *args = newArgs();
  int c;

  char *optString = "hva:e:i:l:m:d:D:w:r:";

  opterr = 0;
  while ((c = getopt(argc, argv, optString)) != -1) {
    switch (c) {
    case 'a': /* author         */
      args->a = optarg;
      break;
    case 'd': /* date           */
      args->d = optarg;
      break;
    case 'e': /* email          */
      args->e = optarg;
      break;
    case 'D': /* description    */
      args->D = optarg;
      break;
    case 'r': /* git repository */
      args->r = optarg;
      break;
    case 'w': /* header width   */
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

void printUsage(){
  printf("Usage: %s [options] [prog]\n", progname());
  printf("Generate the directory structure for C projects\n");
  printf("Example: ./%s -a \"Charles Babbage\" -e \"charles@babbage.org\" -l gpl proj1 proj2\n", progname());
  printf("Options:\n");
  printf("\t -a <STR> author\n");
  printf("\t[-d <STR> description; default: dummy string]\n");
  printf("\t[-e <STR> email; default: none]\n");
  printf("\t[-l <STR> license, gpl|lgpl|<freeText>; default: none]\n");
  printf("\t[-D <STR> date; default: automatic time stamp]\n");
  printf("\t[-r <STR> git repository; default: dummy string]\n");
  printf("\t[-w <NUM> header width; default: longest header string]\n");
  printf("\t[-h print this help message and exit]\n");
  printf("\t[-v print version & program information and exit]\n");
  exit(0);
}

void printSplash(){
  printf("%s ", progname());
  int l = strlen(VERSION);
  for(int i = 0; i < l - 1; i++)
    printf("%c", VERSION[i]);
  printf(", %s\n", DATE);
  printf("Written by Bernhard Haubold.\n");
  printf("Distributed under the GNU General Public License.\n");
  printf("Please send bug reports to haubold@evolbio.mpg.de\n");
  exit(0);
}

