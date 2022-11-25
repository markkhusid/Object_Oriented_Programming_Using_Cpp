/*********************************************************************

  Filename:  throw1.cpp
  Chapter:   11     Exceptions
  Section:   11.4   Throwing Exceptions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

void foo()
{
   int  i;
   //will illustrate how an exception is thrown
   i = -15;
   throw i;
}

int main()
{
   try {
      foo();
   }
   catch(int n)
      { cerr << "exception caught\n " << n << endl; }
}

