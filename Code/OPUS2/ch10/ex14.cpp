/*********************************************************************

  Filename:  ex14.cpp
  Chapter:   10     Inheritance
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Override v. Overload

#include  <iostream.h>

class B {
public:
   B(int j = 0) : i(j) {}
   virtual void  print() const
      { cout << " i = " << i << endl; }
   void  print(char *s) const
      { cout << s << i << endl; }
private:
   int i;
};

class D : public B {
public:
   D(int j = 0) : B(5), i(j) {}
   void  print() const
      { cout << " i = " << i << endl; }
   int  print(char *s) const
      { cout << s << i << endl; return i; }
private:
   int  i;
};

int main()
{
   B  b1, b2(10), *pb;
   D  d1, d2(10), *pd = &d2;

   b1.print(); b2.print(); d1.print(); d2.print();
   b1.print("b1.i = "); b2.print("b2.i = ");
   d1.print("d1.i = "); d2.print("d2.i = ");
   pb = pd;
   pb -> print(); pb -> print("d2.i = ");
   pd -> print(); pd -> print("d2.i = ");
}
