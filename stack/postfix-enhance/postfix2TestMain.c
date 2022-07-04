#include "postfix2.h"
#include "stack3.h"
#include "utility.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // use 'getopt'

int main(int argc, char** argv)
{
  extern char *optarg;
  int c, err = 0;
  char *filename;
  static char usage[] = "usage: %s [-b filename]\n";

  while ((c = getopt(argc, argv, "b:")) != -1)
  {
    switch(c)
    {
      case 'b':
        /* expr1:
         * infix expression: a+b*c+(d*e+f)*g
         * postfix expression: abc*+de*f+g*+
         * expr2:
         * infix expression: (a+b)/c*d-e
         * postfix expression: ab+c/d*e-
         * expr3:
         * infix expression: 2^3^2
         * postfix expression: 232^^
         */
        filename = optarg;
        printf("infix expression: ");
        printFile(filename);
        printf("original postifx expression: ");
        // infixTopostfix(filename);
        printf("postfix_enhance expression: ");
        infixTopostfix_enhance(filename); 
        break;
      case '?':
        err = 1;
        break;
    }
  }
  if (err)
  {
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }
  exit(0);  
}
