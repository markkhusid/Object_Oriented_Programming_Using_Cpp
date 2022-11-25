/*********************************************************************

  Filename:  stl_list.cpp
  Chapter:   1      Why Object Oriented Programming in C++?
  Section:   1.7    The Standard Template Library - STL
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Using the list container.
#include <iostream>
#include <list>       //list container
#include <numeric>    //for accumulate
using namespace std;

void print(const list<double> &lst)
{ //using an iterator to traverse lst
   list<double>::const_iterator p;

   for (p = lst.begin(); p !=lst.end(); ++p)
      cout << *p << '\t';
   cout << endl;
}

int main()
{
   double w[4] = {0.9, 0.8, 88, -99.99};
   list<double> z;

   for( int i = 0; i < 4; ++i)
      z.push_front(w[i]);
   print(z);
   z.sort();
   print(z);
   cout << "sum is "
      << accumulate(z.begin(), z.end(), 0.0) << endl;
}
