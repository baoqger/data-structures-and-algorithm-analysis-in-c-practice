#include "stack3.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MAW 3.20.a Write a program to convert
 * an infix expression which includes '(',
 * ')', '+', '-', '*', and '/' to postfix.
 * 
 * MAW 3.20.b Add the exponentiation operator to your
 * repertoire.
 */
void infixTopostfix(char*);
int precedence(char);
void infixTopostfix_enhance(char*);    
