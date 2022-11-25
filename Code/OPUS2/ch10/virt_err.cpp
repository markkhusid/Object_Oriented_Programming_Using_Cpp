/*********************************************************************

  Filename:  virt_err.cpp
  Chapter:   10     Inheritance
  Section:   10.4   Virtual Functions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

// Virtual function selection
// This program demonstrates errors and does not compile

#include  <iostream.h>

class B {
public:
   virtual void foo(int);
   virtual void foo(double);
};

class D : public B {
public:
   void foo(int);
};

int main()
{
   D d;
   B b, *pb = &d;

   b.foo(9);        //selects B::foo(int);
   b.foo(9.5);      //selects B::foo(double);
   d.foo(9);        //selects D::foo(int);
   d.foo(9.5);      //selects D::foo(int);
   pb -> foo(9);    //selects D::foo(int);
   pb -> foo(9.5);  //selects B::foo(double);
}

