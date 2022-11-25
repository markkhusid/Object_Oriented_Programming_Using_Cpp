/*********************************************************************

  Filename:  weekend.cpp
  Chapter:   4      Implementing ADTs in the Base Language
  Section:   4.4    Unions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include  <iostream.h>

int main()
{
   enum week { sun, mon, tues, weds, thurs, fri, sat };
   union {
      int   i;
      week  w;
   };

   i = 5;
   if (w == sat || w == sun)
      cout << " It's the weekend! ";
   i = 6;
   if (w == sat || w == sun)
      cout << " It's the weekend! ";
}
