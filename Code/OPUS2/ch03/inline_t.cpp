/*********************************************************************

  Filename:  inline_t.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.7    Inlining
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Inline functions

#include <iostream.h>
#include <math.h>


#define  SQR(X)  ((X) * (X))
#define  CUBE(X)  (SQR(X)*(X))
#define  ABS(X)   (((X) < 0)? -(X) : X)

inline double cube(double x)
{
   return (x * x * x);
}

main()
{
   cout << "\nThis checks equavalence on inline and #define\n";
   double y, t = 30.0;

   y = SQR(t + 8) - CUBE(t - 8);
   cout << sqrt(ABS(y));

   cout << " is the same as ";
   y = ((t+8) * (t+8)) - ((((t-8)) * (t-8)) * (t-8));
   cout << sqrt((((y) < 0)? -(y) : y));
}
