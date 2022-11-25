/*********************************************************************

  Filename:  union.cpp
  Chapter:   4      Implementing ADTs in the Base Language
  Section:   4.4    Unions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include  <iostream.h>

union int_dbl {
   int     i;
   double  x;
} n = {0};          //i member is init to zero

int main ()
{
   n.i  = 7;           // int value 7 is stored in n

   cout << n.i << " is integer. ";
   cout << n.x << " is double - machine dependent.";
   cout << endl;

   n.x  = 7.0;         // double value 7.0 is stored in n
   cout << n.i << " is integer. ";
   cout << n.x << " is double - machine dependent.";
   cout << endl;
}
