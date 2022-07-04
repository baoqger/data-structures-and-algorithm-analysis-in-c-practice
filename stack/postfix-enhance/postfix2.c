#include "postfix2.h"

/* The algorithm used is called "Shunting-yard" algorithm
 * see more: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
 * Operator precedence assumed (from highest to lowest):
 *  () 
 *  ^
 *  *, /
 *  +, -
 */

void infixTopostfix_enhance(char *filename) {
    int maxElements = 20;
    Stack s = createStack(maxElements);
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "can't open %s\n", filename);
        exit(1);
    }
    int c;
    while((c=getc(fp)) != EOF) {
        if(isalpha(c) || isdigit(c)) {
            putchar(c);
        } else {
            switch(c) {
                case ' ':
                case '\n':
                    break;
                case '-':
                case '+':
                case '/':
                case '*':
                case '(':
                    while(!isEmpty(s) && 
                          top(s) != '(' && 
                          precedence(c) <= precedence(top(s))
                    ) {
                        putchar(topAndPop(s));                                           
                    }
                    push(c, s);
                    break;
                case '^':
                    push(c, s);
                    break;
                case ')':
                    while(top(s) != '(') {
                        putchar(topAndPop(s));
                    }
                    pop(s); // remove '()'
                    break;
                default:
                    fprintf(stderr, "invalid operator %c %d \n", c, c);
                    exit(1);
            }
        }
    }
    while(!isEmpty(s)){
        putchar(topAndPop(s));
    }
    disposeStack(s);
    printf("\n");
}

void
infixTopostfix(char* filename)
{
  int maxElements = 20;
  Stack s = createStack(maxElements);
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "can't open %s\n", filename);
    exit(1);
  }
  int c;
  while((c=getc(fp)) != EOF)
  {
    /* printf("character c read: "); */
    /* putc(c, stdout); */
    /* printf("\n"); */
    if(isalpha(c) || isdigit(c))
    {
      putchar(c);
    }
    else
    {
      switch(c)
      {
        case ' ':
          break;
        // '-+'优先级最低，除了'('都可以出战
        case '-':
        case '+':
          while(!isEmpty(s) && top(s) != '(')
          {
            putchar(topAndPop(s));
          }
          push(c, s);
          break;
        case '/':
        case '*':
          if (top(s) == '+' ||
              top(s) == '-' ||
              top(s) == '(' ||
              isEmpty(s))
          {
            push(c, s);
          }
          else
          { // 此处为什么不用考虑 "-+"?
            while (top(s) != '(' && !isEmpty(s))
            {
              putchar(topAndPop(s));
            }
            push(c, s);
          }
          break;
        case '(':
          push('(', s);    
          break;
        case ')':
          while(top(s) != '(')
          {
            putchar(topAndPop(s));
          }
          pop(s); //remove '('
          break;
        case '^':
          push('^', s); // by assumption, there is no operator has higher precedence than '^', so we push directly
          break;
        default:
          fprintf(stderr, "Invalid operator %c in expression\n", c);
          exit(1);
      }
    }
  }
  while(!isEmpty(s))
  {
    putchar(topAndPop(s));
  }
  disposeStack(s);
  printf("\n");
}


int precedence(char c) {
    switch(c) {
        case '-':
        case '+':
                return 0;
        case '/':
        case '*':
                return 1;
        case '^':
                return 2;
        case '(':
        case ')':
                return 3;
        default:
                return -1;
    }    
}
