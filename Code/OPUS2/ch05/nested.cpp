/*********************************************************************

  Filename:  nested.cpp
  Chapter:   5      Data Hiding and Member Functions
  Section:   5.4    Class Scope
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

// Note that Y cannot get at X::c directly; it can declare a class
// of type X, then access type.X::c
// in this example X t goes out of scope at function end


char  c;                 //external scope  ::c

class X {               //outer class declaration  X::
public:
   X() : c('B') {}      // init c to B for X class
   class Y {            //inner class declaration  X::Y::
   public:
      Y() : c('C') {};     // init c to C for Y class
      void foo(char e) {X t; ::c = t.X::c = c = e;}
      friend ostream& operator<<(ostream& out, Y yc);
   private:
      char  c;       //X::Y::c
   };
   friend class X::Y; //needed for access to X::c
   friend ostream& operator<<(ostream& out, X xc);
private:
   char  c;          //X::c
};


ostream& operator<<(ostream& out, X xc)
{
   return (out << "  X::c = " << xc.c << "  ");
}


ostream& operator<<(ostream& out, Y yc)
{
   return (out << "  Y::c = " << yc.c << "  ");
}

int main()
{
   X xclass;
   X::Y yclass;

   c = 'A';      // external to 'A'
   cout << c << xclass << yclass << endl;
   yclass.foo('D');   // set Y::c and ::c to D
   cout << c << xclass << yclass << endl;
}


