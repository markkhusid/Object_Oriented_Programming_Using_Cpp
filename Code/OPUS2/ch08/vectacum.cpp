/*********************************************************************

  Filename:  vectacum.cpp
  Chapter:   8      Visitation: Iterators and Containers
  Section:   8.1    Visitation
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Vector type for iterators
#include "vector.h"


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



int main()
{
   vector   a(3), b(3), c(6), d(6);
   int      i, j, sum = 0;

   cout << "Enter 3 ints for vector a: ";
   cin >> a;

   init_vect(b, 1, 1);
   init_vect(c, 10, 10);
   init_vect(d, 100, 1);

   cout << "\nvector a is\n" << a;
   cout << "\nvector b is\n" << b;
   cout << "\nvector c is\n" << c;
   cout << "\nvector d is\n" << d;

   a = b;
   cout << "\nvector a should be same as b\n" << a;
   i = accumulate(a.begin(), a.end(), 0);
   cout << "\nsum of a is " << i;

}
