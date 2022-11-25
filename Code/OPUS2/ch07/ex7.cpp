/*********************************************************************

  Filename:  ex7.cpp
  Chapter:   7      Ad Hoc Polymorphism
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
#include <math.h>

class complex {
public:
   complex(double r) { real = r; imag = 0; }
   void  assign(double r, double i)
      { real = r; imag = i; }
   void  print()
      { cout << real << " + " << imag << "i "; }
   operator double()
      { return (sqrt(real * real + imag * imag));}
   friend ostream& operator<<(ostream& out, complex x);
private:
   double real, imag;
};

ostream& operator<<(ostream& out, complex x)
{
   out << x.real << " + " << x.imag << "i ";
   return out;
}

int main()
{
   complex c1(50.3);

   cout << c1;
}
