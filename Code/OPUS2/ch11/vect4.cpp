/*********************************************************************

  Filename:  vect4.cpp
  Chapter:   11     Exceptions
  Section:   11.3   C++ Exceptions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

// Signal Exceptions and vect
// This program will prompt for a new size.

#include "vect4.h"
#include <stdlib.h>   //for abort

void g (int m)
{
  try {
      vect  a(m), b(m);
  }
  catch(int m)
  {
     cerr << "SIZE ERROR " << m << endl;
     g(10);      //retry g with legal size
  }
  catch(const char* error)
  {
     cerr << error << endl;
     abort();
  }
}


int main()
{
   int n = -5;   // to produce error

   g(n);
}






