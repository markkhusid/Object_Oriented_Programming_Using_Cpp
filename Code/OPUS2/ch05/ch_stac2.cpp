/*********************************************************************

  Filename:  ch_stac2.cpp
  Chapter:   5      Data Hiding and Member Functions
  Section:   5.1    Member Functions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Test of ch_stack by reversing a string.
//Uses member functions
#include  "ch_stac2.h"
#include  <iostream.h>

int main()
{
   ch_stack  s;
   char   str[40] = {"My name is Betty Dolsberry!"};
   int    i = 0;

   cout << str << endl;        //print the string
   s.reset();
   while (str[i] && !s.full()) //push onto stack
      s.push(str[i++]);

   while (!s.empty())          //print the reverse
      cout << s.pop();
   cout << endl;
}
