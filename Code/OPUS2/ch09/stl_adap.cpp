/*********************************************************************

  Filename:  stl_adap.cpp
  Section:   9.12   STL Function Adaptors
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Use of as ostream_iterator iterator.

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

template <class ForwIter>
void print(ForwIter first, ForwIter last,
           const char* title)
{
   cout << title << endl;
   while ( first != last)
		      cout << *first++ << '\t';
   cout << endl;
}

int main()
{
   int data[3] = { 9, 10, 11};

   print(data, data + 3, "Original values");
   transform(data, data + 3, data,
             bind2nd(times<int>(), 2));
   print(data, data + 3, "New values");
}

