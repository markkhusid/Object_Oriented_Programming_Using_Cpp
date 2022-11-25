/*********************************************************************

  Filename:  vectsort.cpp
  Chapter:   8      Visitation: Iterators and Containers
  Section:   8.1    Visitation
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Vector type for iterators
#include "vector.h"

vector::iterator partition(vector::iterator from,
                           vector::iterator to);
void init_vect(vector& v, int start, int incr)
{
   for (int i = 0; i <= v.ub(); ++i) {
      v[i] = start;
      start += incr;
   }
}


//A simple numerical algorithm
int accumulate        //sum the container values
   (   vector::iterator first,   //starting location
       vector::iterator last,    //end-of-range
       int initial_val   //initial sum
    )
{
   vector::iterator   p;
   int sum = initial_val;

   for (p = first; p != last; ++p)
      sum += *p;
   return sum;
}

//QUICKSORT using an iterator
void quicksort(vector::iterator from,
               vector::iterator to)
{
   vector::iterator mid;

   if (from < to -1) {
       mid = partition(from, to);
       quicksort(from, mid);
       quicksort(mid + 1, to);
   }
}


inline void swap(int& i, int& j)
{
   int temp = i;

   i = j;
   j = temp;
}

vector::iterator partition(vector::iterator from,
                           vector::iterator to)
{
   vector::iterator front = from + 1, back = to - 1;
   int  compare = *from;

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
   if (compare > *front) {
      swap(*from, *front);
      return front;
   }
   else {
      swap(*from, *(front - 1));
      return front - 1;
   }
}


int main()
{
   vector   a(3), b(3), c(6), d(6);
   int      sum = 0;

   cout << "Enter 3 ints for vector a: ";
   cin >> a;

   init_vect(b, 1, 1);
   init_vect(c, 10, 10);
   init_vect(d, 100, -5);

   cout << "\nvector a is\n" << a;
   cout << "\nvector b is\n" << b;
   cout << "\nvector c is\n" << c;
   cout << "\nvector d is\n" << d;

   sum = accumulate(a.begin(), a.end(), 0);
   cout << "\nsum of a is " << sum;

   quicksort(d.begin(), d.end());
   cout << "\nafter sort on d is\n" << d;
}
