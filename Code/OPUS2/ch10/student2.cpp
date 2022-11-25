/*********************************************************************

  Filename:  student2.cpp
  Chapter:   10     Inheritance
  Section:   10.1   A Derived Type
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include "student2.h"

int main()
{
   student  s("Mae Pohl", 100, 3.425, student::fresh),
                   *ps = &s;
   grad_student  gs("Morris Pohl", 200, 3.2564,
       student::grad, grad_student::ta, "Pharmacy",
       "Retail Pharmacies"), *pgs;
   ps -> print();          //student::print
   ps = pgs = &gs;
   pgs -> print();         //grad_student::print
   ps ->print();           //student::print
}

