/*********************************************************************

  Filename:  new_hdlr.cpp
  Chapter:   7      Ad Hoc Polymorphism
  Section:   7.12   Overloading new and delete
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Simple fault tolerance using _new_handler.
#include <iostream.h>
#include <new.h>
#include <stdlib.h> //for exit

void heap_exhausted()  //user defined error handling
{
   cerr << "HEAP EXHAUSTED" << endl;
   exit(1);
}

int main()
{
   set_new_handler(heap_exhausted);

   double* array;
   int times = 0;

   while (1) {
      array = new double [64000];
      cout << times++ << '\t';
   }
   array[0] = 1;
}


