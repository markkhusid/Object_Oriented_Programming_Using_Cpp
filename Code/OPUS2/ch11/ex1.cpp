/*********************************************************************

  Filename:  ex1.cpp
  Chapter:   11     Exceptions
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Incorrect bubble sort.
#include  <iostream.h>

void swap(int a, int b)
{
   int  temp = a;

   a = b;
   b = temp;
}

void bubble(int a[], int size)
{
   int  i, j;

   for (i = 0; i != size; ++i)
      for (j = i ; j != size; ++j)
         if (a[j] < a [j + 1])
             swap (a[j], a[j + 1]);
}

int main()
{
   int  t[10] = { 9, 4, 6, 4, 5, 9, -3, 1, 0, 12};

   bubble(t, 10);
   for (int i = 0; i < 10; ++i)
      cout << t[i] << '\t';
   cout << "\nsorted? " << endl;
}
