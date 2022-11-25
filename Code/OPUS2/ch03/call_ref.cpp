/*********************************************************************

  Filename:  call_ref.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.10   Pointer Types
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

//Pointer-based call-by-reference.
void  order(int*, int*);

int main()
{
   int  i = 7, j = 3;

   cout << i << '\t' << j << endl;  // 7  3 is printed
   order(&i, &j);
   cout << i << '\t' << j << endl;  // 3  7 is printed
}

void order(int* p, int* q)
{
   int  temp;

   if (*p > *q) {
      temp = *p;
      *p = *q;
      *q = temp;
   }
}
