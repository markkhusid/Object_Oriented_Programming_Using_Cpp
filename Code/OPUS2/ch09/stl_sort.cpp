/*********************************************************************

  Filename:  stl_sort.cpp
  Section:   9.10   STL  Sorting Algorithms
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5;

int main()
{
   int    d[N], i, *e = d + N;

   for (i = 0; i < N; ++i)
      d[i] = rand();
   sort(d, e);
   for (i = 0; i < N; ++i)
      cout << d[i] << '\t';
}
