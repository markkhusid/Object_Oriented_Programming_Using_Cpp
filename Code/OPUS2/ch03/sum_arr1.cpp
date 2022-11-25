/*********************************************************************

  Filename:  sum_arr1.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.12   Arrays and Pointers
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Simple array processing.
#include  <iostream.h>
const int  SIZE = 5;

int main()
{
   int  a[SIZE];     //get space for a[0],·····,a[4]
   int  i, sum = 0;

   for (i = 0; i < SIZE; ++i) {
      a[i] = i * i;
      cout << "a[" << i << "] = " << a[i] << "   ";
      sum += a[i];
   }
   cout << "\nsum = " << sum << endl;
}
