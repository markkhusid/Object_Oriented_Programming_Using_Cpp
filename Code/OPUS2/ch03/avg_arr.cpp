/*********************************************************************

  Filename:  avg_arr.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.6    Overloading Functions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

//Average the values in an array.

double avg_arr(const int a[], int size)
{
   int  sum = 0;

   for (int i = 0; i < size; ++i)
      sum += a[i];       //performs int arithmetic
   return (static_cast<double>(sum) / size);
}

double avg_arr(const double a[], int size)
{
   double  sum = 0.0;

   for (int i = 0; i < size; ++i)
      sum += a[i];       //performs double arithmetic
   return (sum / size);
}

int main()
{
   int     w[5] = { 1, 2, 3, 4, 5 };
   double  x[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

   cout << avg_arr(w, 5) << " int average" << endl;
   cout << avg_arr(x, 5) << " double average" << endl;
}
