/*********************************************************************

  Filename:  complex2.cpp
  Chapter:   5      Data Hiding and Member Functions
  Section:   5.3    Classes
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Show complex number in both struct and class representations

#include <iostream.h>

//Implement as a struct (default is public)

struct complex {
 public:
    void  assign(double r, double i);
    void  print()
       { cout << real << " + " << imag << "i "; }
 private:
    double  real, imag;
};

inline void complex::assign(double r, double i = 0.0)
{
    real = r;
    imag = i;
}


//Make public and private explicit in class
class complex_c1 {
 public://need to know style- our preference
    void assign(double r, double i);
    void  print()
       { cout << real << " + " << imag << "i ";}
 private:
    double  real, imag;
 };

inline void complex_c1::assign(double r, double i = 0.0)
 {
    real = r;
    imag = i;
 }

//Implement as a class (default is private)
class complex_c2 { //old private-implicit style
    double  real, imag;
 public:
    void  assign(double r, double i);
    void  print()
       { cout << real << " + " << imag << "i "; }
};

void complex_c2::assign(double r, double i = 0.0)
{
   real = r;
   imag = i;
}

main()
{
   complex     a;
   complex_c1  b;
   complex_c2  c;

   a.assign(1.1, 2.2);
   b.assign(3.3, 4.4);
   c.assign(5.5, 6.6);

   cout << "\nComplex from struct definition: ";
   a.print();
   cout << "\nComplex from class definition: ";
   b.print();
   cout << "\nComplex from explicit class definition: ";
   c.print();
}