/*********************************************************************

  Filename:  ex11.cpp
  Chapter:   3      Functions and Pointers
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

// Print command line arguments rightmost first.


#include  <stdio.h>

/* Works in ANSI C */
int main()
{

   int  a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   int i;

   for (i = 0; i < 10; ++i)
      if (a[i] != i[a])
        printf("Not the same at index %d : %d != %d\n",
            i, a[i], i[a]);
}
