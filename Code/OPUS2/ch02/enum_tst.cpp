/*********************************************************************

  Filename:  enum_tst.cpp
  Chapter:   2      The Native Types and Statements
  Section:   2.6    Enumeration Types
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Demonstrate use of enum

#include <iostream.h>

main()
{
   enum signal { off, on } a = on;  //a initialized to on
   enum answer { no, yes, maybe = -1 } b;
// enum negative { no, false } c;   //illegal "no" and
                                    //"false" redeclared

   enum { lazy, hazy, crazy } why;

   int  i, j = on;     //legal on is converted to 1

   a = off;               //legal
   i = a;                 //legal i becomes 0
//   b = a;                 //illegal two distinct types
   b = static_cast<answer>(a);    //legal explicit cast
   b = (a ? no : yes);    //legal enumerators type answer

   why = hazy;
   cout << "\na, b, i, j, why " << a << b << i << j << why;
}
