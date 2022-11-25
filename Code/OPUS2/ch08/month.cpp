/*********************************************************************

  Filename:  month.cpp
  Chapter:   8      Visitation: Iterators and Containers
  Section:   8.5    Genericity with void*
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
#include "genstack.h"

char* months[12] = { "january", "february", "march",
     "april", "may", "june", "july", "august",
     "september", "october", "november", "december"};

int main()
{
    stack a;
    int i;

    for (i = 0; i < 12; ++i)
       a.push(months[i]);
    for (i = 0; i < 12; ++i)
       cout << reinterpret_cast<char*>(a.pop())
            << endl;
}
