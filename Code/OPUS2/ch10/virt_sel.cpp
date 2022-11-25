/*********************************************************************

  Filename:  virt_sel.cpp
  Chapter:   10     Inheritance
  Section:   10.4   Virtual Functions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//virtual function selection.

#include  <iostream.h>

class B {
public:
   int  i;
   virtual void  print_i() const
      { cout << i << " inside B" << endl; }
};

class D : public B {
public:
    //virtual as well
   void  print_i() const
      { cout << i << " inside D" << endl; }
};

int main()
{
    B   b;
    B*  pb = &b;              //points at a B object
    D   f;

    f.i = 1 + (b.i = 1);
    pb -> print_i();          //call B::print_i()
    pb = &f;                  //points at a D object
    pb -> print_i();          //call D::print_i()
}
