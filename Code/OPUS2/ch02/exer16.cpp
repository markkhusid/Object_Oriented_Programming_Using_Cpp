/*********************************************************************

  Filename:  exer16.cpp
  Chapter:   2      The Native Types and Statements
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
#include <limits>
using namespace std;

int main()
{
   numeric_limits<double> dbl_typ;
   cout << "double limits are: " <<  dbl_typ.min() << " , "
       << dbl_typ.max() << endl;
}
