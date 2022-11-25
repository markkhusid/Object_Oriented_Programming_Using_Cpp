/*********************************************************************

  Filename:  sum_arr3.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.14   Passing Arrays to Functions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Show array elements and sum of array

#include <iostream.h>

const int N = 100;

int sum(const int a[], int n) // n is the size of a[]
{
   int  i, s = 0;

   for (i = 0; i < n; ++i)
      s += a[i];
   return s;
}

int main()
{
   int   v[N], *p;      // space for a[0], ..., a[99] is allocated
   int   i, k = 14;

   for (i = 0; i < N; ++i)
      v[i] = i + i;     //init array elements

   cout << "\nSum all  is " << sum (v, N);
   cout << "\nSum 100  is " << sum (v, 100);
   cout << "\nSum 88  is " << sum (v, 88);
   cout << "\nSum 7 to 20   is " << sum (v + 7, k);
   cout << endl;
}
