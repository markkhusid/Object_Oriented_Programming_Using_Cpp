/*********************************************************************

  Filename:  gcd.cpp
  Chapter:   2      The Native Types and Statements
  Section:   2.3    Program Structure
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Greatest common divisor program.
#include  <iostream.h>
#include  <assert.h>

int gcd(int m, int n)      //function definition
{                          //block
   int  r;                 //declaration of remainder

   while (n != 0) {        //not equal
      r = m % n;           //modulo operator
      m = n;               //assignment
      n = r;
   }                       //end while loop
   return m;               //exit gcd with value m
}

int main()
{
   int  x, y, g;

   cout << "\nPROGRAM Gcd C++";
   do {
      cout << "\nEnter two integers: ";
      cin >> x >> y;
      assert(x * y != 0); //precondition on gcd
      cout << "\nGCD(" << x << ", " << y << ") = "
           << (g = gcd(x, y)) << endl;
      assert(x % g == 0 && y % g ==0);//postcondition
   } while (x != y);

}

