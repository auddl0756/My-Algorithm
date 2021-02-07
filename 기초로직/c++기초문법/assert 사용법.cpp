/* assert example */
#include <stdio.h>      /* printf */
#include <assert.h>     /* assert */

//Evaluate assertion
//If the argument expression of this macro with functional form compares equal to zero (i.e., the expression is false), 
//a message is written to the standard error device and abort is called, terminating the program execution.


void print_number(int* myInt) {
  assert (myInt!=NULL);
  printf ("%d\n",*myInt);
}

int main ()
{
  int a=10;
  int * b = NULL;
  int * c = NULL;

  b=&a;

  print_number (b);
  print_number (c);

  return 0;
}
