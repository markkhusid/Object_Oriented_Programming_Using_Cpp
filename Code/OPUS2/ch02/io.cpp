/*********************************************************************

  Filename:  io.cpp
  Chapter:   2      The Native Types and Statements
  Section:   2.2    Simple I/O
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

int main()
{
   double x;
   int i;

   cout << "\nEnter a double: ";
   cin >> x;
   cout << "\nEnter a positive integer: ";
   cin >> i;
   if (i < 1)
      cerr << "error i = " << i << endl;
   cout << "i * x = " << i * x;
}
