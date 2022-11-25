/*********************************************************************

  Filename:  stat_tst.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.8.4  Storage Class static
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Static variable to show number of times function is called

#include <iostream.h>

int f()
{
   static int  called = 0;

   ++called;
   return called;
}

main()
{
   int call_times;

   for (int i = 0; i < 5; ++i)
      call_times = f();
   cout << "\nThe function is called " << call_times << " times\n";
}