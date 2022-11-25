/*********************************************************************

  Filename:  throw2.cpp
  Chapter:   11     Exceptions
  Section:   11.4   Throwing Exceptions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
void foo()
{
   int  i, j;

   i = 14;
   j = 15;
   throw i;
}

void call_foo()
{
   int  k;

   k  = 12;
   foo();
}

int main()
{
   try {
      call_foo();  //foo exitted with i and j destroyed
   }
   catch(int n) { cout << "\ncaught it " << n << endl; }
}


