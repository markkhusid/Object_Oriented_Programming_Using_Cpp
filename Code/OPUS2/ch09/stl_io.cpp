/*********************************************************************

  Filename:  stl_io.cpp
  Section:   9.9    Iterators
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Use of  istream_iterator  and ostream_iterator.

#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
   vector<int> d(5);
   int  i, sum ;
   istream_iterator<int, ptrdiff_t> in(cin);
   ostream_iterator<int> out(cout, "\t");

   cout << "enter 5 numbers" << endl;
   sum = d[0] = *in; //input first value
   for(i = 1; i < 5; ++i) {
      d[i] = *++in; //input consecutive values
      sum += d[i];
}
   for(i = 0; i < 5; ++i)
      *out = d[i] ; //output consecutive values
   cout << " sum = " << sum << endl;     cin>> i;
}
