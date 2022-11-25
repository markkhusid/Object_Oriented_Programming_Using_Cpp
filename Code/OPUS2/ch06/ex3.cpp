/*********************************************************************

  Filename:  ex3.cpp
  Chapter:   6      Object Creation and Destruction
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Constructors and destructors invoked
#include  <iostream.h>

class A {
public:
   A(int n) : xx(n)
     { cout << "A(int " << n << ") called" << endl;}
   A(double y) : xx(y + 0.5)
     { cout << "A(fl " << y << ") called" << endl; }
   ~A()
     { cout << "~A() with A::xx = " << xx << endl; }
private:
   int  xx;
};

int main()
{
   cout << "enter main\n";
   int    x = 14;
   float  y = 17.3;
   A      z(11), zz(11.5), zzz(0);

   cout << "\nOBJECT ALLOCATION LAYOUT\n";
   cout << "\nx is at " << &x;
   cout << "\ny is at " << &y;
   cout << "\nz is at " << &z;
   cout << "\nzz is at " << &zz;
   cout << "\nzzz is at " << &zzz;
   cout << "\n_____________________________\n";
   zzz = A(x);
   zzz = A(y);
   cout << "exit main" << endl;
}

