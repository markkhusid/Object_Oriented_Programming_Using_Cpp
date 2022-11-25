/*********************************************************************

  Filename:  c_pair.cpp
  Chapter:   5      Data Hiding and Member Functions
  Section:   5.7    The this pointer
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

//The this pointer
class c_pair {
public:
   c_pair init(char b) { c2 = 1 + (c1 = b); }
   c_pair increment() { c1++; c2++; return (*this); }
   c_pair*  where_am_I() { return this; }
   void  print() { cout << c1 << c2 << '\t'; }
private:
   char  c1, c2;
};

int main()

{
   c_pair  a, b;

   a.init('A');
   a.print();
   cout << " is at " << a.where_am_I() << endl;
   b.init('B');
   b.print();
   cout << " is at " << b.where_am_I() << endl;
   b.increment().print();
}
