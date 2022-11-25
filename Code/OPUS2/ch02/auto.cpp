/*********************************************************************

  Filename:  auto.cpp
  Section:   2.8    Assignment and Expressions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Demonstrate auto increment and decrement with simple examples

#include <iostream.h>

int main()
{
   int    i, j;

   //pre and post fix increments
   cout << "\n\n*****  Pre and Post fix";
   cout << "\nJ should be 1, 1, then I should be 2 and undetermined\n";
   i = 0;
   j = ++i;
   cout << "\nJ = " << j;
   j = i++;
   cout << "\nJ = " << j << "\nI = " << i;
   i = ++i + i++;  // hazardous practice that is system dependent
   cout << "\nI = " << i;
}
