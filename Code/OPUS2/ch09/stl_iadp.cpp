/*********************************************************************

  Filename:  stl_iadp.cpp
  Section:   9.9    STL Iterator Adaptors
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Use of as ostream_iterator iterator.

#include <iostream>
#include <vector>
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
   int     data[3] = { 9, 10, 11};
   vector<int> d(data, data + 3);
   vector<int>::reverse_iterator p = d.rbegin();

   print(d.begin(), d.end(), "Original");
   print(p, d.rend(), "Reverse");
}



