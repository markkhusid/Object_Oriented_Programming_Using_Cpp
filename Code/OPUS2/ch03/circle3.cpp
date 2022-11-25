/*********************************************************************

  Filename:  circle3.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.8.3  Storage Class extern
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//This file works in conjunction with cir_main.cpp

const double  pi = 3.14159;       //local to circle.c

double circle(double radius)
{
   return (pi * radius * radius);
}
