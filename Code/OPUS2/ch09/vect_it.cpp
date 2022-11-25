/*********************************************************************

  Filename:  vect_it.cpp
  Chapter:   9      Templates, Generic Programming and STL
  Section:   9.4    Parameterizing the Class vect
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Template based safe array type

#include <iostream.h>
#include "vect_it.h"

int main()
{
   vector<double> v(5);
   vector<double>::iterator p ;
   int i = 0;

   for (p = v.begin() ; p != v.end(); ++p)
      *p = 1.5 + i++;

   do {
      --p;
      cout << *p << " , ";
   } while (p != v.begin());
   cout << endl;
}
