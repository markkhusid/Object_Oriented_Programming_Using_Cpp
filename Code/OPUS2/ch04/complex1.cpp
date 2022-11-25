/*********************************************************************

  Filename:  complex1.cpp
  Chapter:   4      Implementing ADTs in the Base Language
  Section:   4.5    Complex Numbers
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include  <iostream.h>

struct complex {
   double  real, imag;
};

void assign(complex* pc, double r, double i = 0.0)
{
   pc -> real = r;
   pc -> imag = i;
}

complex add(complex a, complex b)
{
   complex temp;

   temp.real = a.real + b.real;
   temp.imag = a.imag + b.imag;
   return temp;
}

int main()
{
   double f = 2.5;
   complex w, x, z;

   assign(&x, 5.5, -3.2);      //x = 5.5 - 3.2i
   assign(&w, f);              //w = 2.5 - 0i
   z = add(w, x);              //z = 8.0 - 3.2i

   cout << "z = " << z.real << "   " << z.imag ;
}

