/*********************************************************************

  Filename:  strcptr.cpp
  Chapter:   8      Visitation: Iterators and Containers
  Section:   8.7    Pointer Operators and Smart Pointers
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

// Overloading the structure pointer operator.

#include <iostream.h>

enum boolean { false, true};

class triple {
private:
   int      i, j, k;
public:
   triple(int a, int b, int c) { i = a; j = b; k = c; }
   void print() { cout << "\ni = " << i
		       << ", j = " << j << ", k = " << k; }
};

triple   unauthor(0, 0, 0);

class t_ptr {
private:
   boolean  access;
   triple*  ptr;
public:
   t_ptr(boolean f, triple* p) { access = f; ptr = p; }
   triple*  operator ->() ;
};

triple* t_ptr::operator ->()
{
   if (access)
      return (ptr);
   else {
      cout << "\nunauthorized access";
      return (&unauthor);
   }
}

main()
{
   triple  a(1, 2, 3), b(4, 5, 6);
   t_ptr ta(false, &a), tb(true, &b);
   ta -> print();   //access denied
   tb -> print();   //access granted
}