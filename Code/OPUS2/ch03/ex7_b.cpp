/*********************************************************************

  Filename:  ex7_b.cpp
  Chapter:   3      Functions and Pointers
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//This file is not the solution to the exericse
//it contains the base code for it

//This file works in conjunction with ex7_A.cpp

#include  <iostream.h>

int foo(int i)
{
   return (i * 5);
}
int  goo(int i);  // imported from file A.c

int main()
{
   cout << "foo(5) = " << foo(5) << endl;
   cout << "goo(5) = " << goo(5) << endl;
}
