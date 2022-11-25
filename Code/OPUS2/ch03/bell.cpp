/*********************************************************************

  Filename:  bell.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.1    Functions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

// ring my bell using '\a' literal  for the alarm.

#include  <iostream.h>

const char  BELL = '\a';

void ring()
{
   cout << BELL ;
}

int main()
{
   ring();
}
