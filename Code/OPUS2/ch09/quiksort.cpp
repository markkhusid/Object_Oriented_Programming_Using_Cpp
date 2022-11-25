/*********************************************************************

  Filename:  quiksort.cpp
  Chapter:   9      Templates, Generic Programming and STL
  Section:   9.5    Parameterizing quicksort()
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
#include <assert.h>
#include "vect_it.h"

//QUICKSORT using an vector class

template<class T>
void swap(T& i, T& j)
{
   T temp = i;
   i = j;
   j = temp;
}

template<class T>
void quicksort(T* from, T* to)
{
   T* mid;

   if (from < to - 1) {
      mid = partition(from, to);
      quicksort(from, mid);
      quicksort(mid + 1, to);
   }
}

template<class T>
T* partition(T* from, T* to)
{
   T* front = from;
   T* back = to - 1;
   T  compare;

   compare = *front;      //comparison element
   ++front;               //advance to next element
   while (front < back) {
      //search forward for out of order element
      while ((front < back) &&(compare > *front))
               ++front;
      //search backward for out of order element
      while ((front < back) &&(compare <= *back))
               --back;
      swap(*front, *back);
   }
   //insert  mid position comparison element
   if (compare >= *front) {
      swap(*from, *front);
      return (front);
   }
   else {
      swap(*from, *(front - 1));
      return (front - 1);
   }
}

main()
{
   vector<int> v(8);
   vector<int>::iterator p;

   v[0] = -6; v[1] = -7; v[2] = -8; v[3] = -9;
   v[4] = -6; v[5] = -7; v[6] = -8; v[7] = -9;


   for (p = v.begin() ; p != v.end(); ++p)
      cout << *p << '\t';
   cout << endl;
   quicksort(v.begin(), v.end() );
   for (p = v.begin() ; p != v.end(); ++p)
      cout << *p << '\t';
   cout << endl;
}
