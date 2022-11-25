/*********************************************************************

  Filename:  min_dbl.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.3    The return Statement
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

// minimum finding.

#include <iostream.h>

double min(double x, double y)
{
   if (x < y)
      return x;
   else
      return y;
}

int main()
{
   double   j, k, m;

   cout << "\nInput two doubles:  ";
   cin >> j >> k;
   m = min(j, k);
   cout << m << " is the minimum of " << j << " and " << k << endl;
}