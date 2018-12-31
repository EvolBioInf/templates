#ifndef INTERFACE
#define INTERFACE

/* define argument container */
typedef struct args{
  char  err; /* error?                */
  char    h; /* help message?         */
  char    v; /* version message?      */
  char   *d; /* date                  */
  char   *D; /* description           */
  char   *a; /* author                */
  char   *r; /* git repository        */
  char   *e; /* email                 */
  char   *l; /* license               */
  char **fi; /* input files           */
  int    nf; /* number of input files */
  int     w; /* header width          */
} Args;

Args *getArgs(int argc, char *argv[]);
void printUsage();
void printSplash();
void freeArgs(Args *args);

#endif
