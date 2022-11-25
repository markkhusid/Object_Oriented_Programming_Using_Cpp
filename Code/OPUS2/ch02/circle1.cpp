/*********************************************************************

  Filename:  circle1.cpp
  Chapter:   2      The Native Types and Statements
  Section:   2.4    Simple Types - Initialization
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

//This program works with circle2.cpp

//Compute the area of a circle.
extern const double  PI;  //declared but not defined
int main()
{
   double  radius = 5.5;  //declared,defined,init
   double  area;          //declared, defined, uninit

   cout << "Circle's Area is "
        << (PI * radius * radius);
}

