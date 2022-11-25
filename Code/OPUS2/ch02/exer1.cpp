/*********************************************************************

  Filename:  exer1.cpp
  Chapter:   2      The Native Types and Statements
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//poorly written gcd function by anonymous

#include <iostream.h>

//poorly written gcd function by anonymous
int foo(int q1, int q2){int q3; while(q2){q3=q1%q2;q1=q2;q2=q3;}return
q1;}


int main()
{
   cout << foo(10,40) << endl;
   cout << foo(84, 2432) << endl;
}
