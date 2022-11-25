/*********************************************************************

  Filename:  vect3.cpp
  Chapter:   11     Exceptions
  Section:   11.2   Using signal.h
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

// Signal Exceptions and vect
// This program will prompt for a new size.

#include "vect3.h"

int main()
{
   vect a(-3); // should get error;

   a[0] = 0;
   a.print();
}



