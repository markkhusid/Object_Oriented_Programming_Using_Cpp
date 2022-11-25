/*********************************************************************

  Filename:  ex6.cpp
  Chapter:   3      Functions and Pointers
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include  <iostream.h>

int foo(int n)
{
   static int  count = 0;

   ++count;
   if ( n <= 1) {
      cout << " count = " << count << endl;
      return n;
   }
   else
      foo(n / 3);
}

int main()
{
   foo(21);
   foo(27);
   foo(243);
}
