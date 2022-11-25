/*********************************************************************

  Filename:  ch_stac1.cpp
  Chapter:   4      Implementing ADTs in the Base Language
  Section:   4.3    An Example Stack
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Test of ch_stack by reversing a string.
#include  "ch_stac1.h"
#include  <iostream.h>

int main()
{
   ch_stack  s;
   char   str[40] = {"My name is Betty Dolsberry!"};
   int    i = 0;

   cout << str << endl;        //print the string
   reset(&s);
   while (str[i] && !full(&s)) //push onto stack
      push(&s, str[i++]);
   while (!empty(&s))          //print the reverse
      cout << pop(&s);
   cout << endl;
}
