/***** interface.h ***************************************************
 * Description: DESCRIPTION
 * Author: AUTHOR
 * Institution: INSTITUTION
 * Email: EMAIL
 * License: LICENSE
 * Date: Wed Dec 26 10:19:39 2018
 *********************************************************************/
#ifndef INTERFACE
#define INTERFACE

#define DEFAULT_I 1

/* define argument container */
typedef struct args{
  char    h; /* help message?         */
  char    v; /* version message?      */
  char    e; /* error                 */
  int     i; /* iterations            */
  char **fi; /* input files           */
  int    nf; /* number of input files */
} Args;

Args *getArgs(int argc, char *argv[]);
Args *newArgs();
void freeArgs(Args *args);
void printUsage();
void printSplash(Args *args);

#endif
