/*********************************************************************

  Filename:  stl_fucn.cpp
  Section:   9.11   STL  Functions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Use of as ostream_iterator iterator.

#include <iostream>
#include <numeric>
using namespace std;

int main()
{
   double v1[3] = {1.0, 2.5, 4.6}, sum;

   sum = accumulate(v1, v1 + 3, 0.0, minus<int>());
   cout << "sum = " << sum << endl;     //sum = -7
}

