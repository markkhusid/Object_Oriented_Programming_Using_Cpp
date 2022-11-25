/*********************************************************************

  Filename:  array_tm.cpp
  Chapter:   9      Templates, Generic Programming and STL
  Section:   9.3    Class Templates
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Get storage off stack for array
//  Title: array

#include <iostream.h>

template <class T, int n>
class assign_array {
public:
   T  a[n];
};

int main()
{
   assign_array<double, 50>  x, y;

   int i;

   for (i = 0; i < 50; ++i)
      x.a[i] = i;
   for (i = 0; i < 50; ++i)
      y.a[i] = i * 2;
   for (i = 0; i < 50; ++i)
      cout << x.a[i] << "\t";
   for (i = 0; i < 50; ++i)
      cout << y.a[i] << "\t";
   x = y;                     //should work efficiently
   for (i = 0; i < 50; ++i)
      cout << x.a[i] << "\t";
}
