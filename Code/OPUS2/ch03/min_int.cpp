/*********************************************************************

  Filename:  min_int.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.3    The return Statement
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Find the minimum of two ints.
#include  <iostream.h>

int min(int x, int y)
{
   if (x < y)
      return x;
   else
      return y;
}

int main()
{
   int  j, k, m;

   cout << "Input two integers:  ";
   cin >> j >> k;
   m = min(j, k);
   cout << '\n' << m << " is the minimum of " << j
        << " and " << k << endl;
}
