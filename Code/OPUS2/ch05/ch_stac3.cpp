/*********************************************************************

  Filename:  ch_stac3.cpp
  Chapter:   5      Data Hiding and Member Functions
  Section:   5.2    Access: private and public
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Test of ch_stack by reversing a string.
//Uses member functions
#include  "ch_stac3.h"
#include  <iostream.h>

//Reverse a string with a ch_stack.
 int main()
 {
    ch_stack  s;
    char   str[40] = {"My name is Don Knuth!"};
    int    i = 0;

    cout << str << endl;
    s.reset();     //s.top = EMPTY; would be illegal
    while (str[i] && !s.full())
       s.push(str[i++]);
    while (!s.empty())   //print the reverse
       cout << s.pop();
    cout << endl;
}
