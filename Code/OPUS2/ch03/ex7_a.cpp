/*********************************************************************

  Filename:  ex7_a.cpp
  Chapter:   3      Functions and Pointers
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//This file is not the solution to the exericse
//it contains the base code for it

//This file works in conjunction with ex7_B.cpp


static int  foo(int i)
{
   return (i * 3);
}

int  goo(int i)
{
   return (i * foo(i));
}
