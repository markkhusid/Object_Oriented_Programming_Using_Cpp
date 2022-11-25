/*********************************************************************

  Filename:  ex7.cpp
  Chapter:   8      Visitation: Iterators and Containers
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Reference counted strings.


#include "string8.h"

void swap(my_string x, my_string y)
{
   my_string temp;

   temp = x;
   x = y;
   y = temp;
}

int main()
{
   my_string  b("dont try me "), c(" try me");

   cout << b << c << endl;
   swap(b, c);
   cout << b << c << endl;
}
