/*********************************************************************

  Filename:  bad_cast.cpp
  Chapter:   11     Exceptions
  Section:   11.10  Standard Exceptions and their Use
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
#include <typeinfo.h>
#include <stdexception>
using namespace std;

class A {
public:
  virtual void foo(){ cout << "in A" << endl;}
};

class B:public A{
public:
  void foo(){ cout << "in B" << endl;}
};

int main()
{
   try {
      A a, *pa; B b, *pb;
      pa = &b;
      pb = dynamic_cast<B*>(pa); //succeeds
      pb -> foo();
      pa = &a;
      pb = dynamic_cast<B*>(pa); //fails and may throw bad_cast
      if (pb != 0)
         pb -> foo();
   }
   catch(...){cout << "bad cast" << endl;} //or use bad_cast
   //catch(bad_cast){ cout << "would not convert" << endl;}
}
