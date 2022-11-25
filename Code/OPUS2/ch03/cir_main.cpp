/*********************************************************************

  Filename:  cir_main.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.8.3  Storage Class extern
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//This file works in conjunction with circle3.cpp

#include  <iostream.h>

double circle(double);  //function is automatically extern

int main()
{
   double  x;

   x = 3.5;
   cout << endl;
   cout << circle(x) << "is area of circle of radius "
        << x;
}

