/*********************************************************************

  Filename:  sum_arr2.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.13   The Relationship Between Arrays and Pointers
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Show array elements and sum of array

#include <iostream.h>

const int N = 100;

int main()
{
   int   a[N], *p;      // space for a[0], ..., a[99] is allocated
   int   i, sum;

   for (i = 0; i < N; ++i)
      a[i] = i + i;     //init array elements

   cout << "\nAddress of pointer via a is " << a;
   cout << "\nAddress of pointer via &a[0] is " << &a[0];
   cout << "\nElement 1 via a + 1 is " << (a + 1);
   cout << "\nElement 1 via &a[1] is " << (&a[1]);

   sum = 0;
   for (p = a; p < &a[N]; ++p)
      sum += *p;
   cout << "\nSum via *p addition is " << sum;

   sum = 0;
   for (i = 0; i < N; ++i)
      sum += a[i];
   cout << "\nSum via a[i] addition is " << sum;

   sum = 0;
   for (i = 0; i < N; ++i)
      sum += *(a + i);
   cout << "\nSum via *(a + i) addition is " << sum;

   cout << endl;
}
