/*********************************************************************

  Filename:  exer21.cpp
  Chapter:   2      The Native Types and Statements
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

int main()
{
   int i, sum, j, k;

   for (sum =i = 0, j = 2, k = i + j; i < 10 || k < 15;
        ++i, ++j, ++k)
   sum += (i < j)? k : i;
   cout << sum << endl;
}

