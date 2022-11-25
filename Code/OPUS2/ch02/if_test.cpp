/*********************************************************************

  Filename:  if_test.cpp
  Section:   2.8    The if and if-else statments
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Demonstrate if statements with simple examples

#include <iostream.h>

main()
{
   int    temperature = 35, x = 3, y = 1, min;

   //if statement
   cout << "\n\n*****  If statement";
   cout << "\n Next line should have above freezing temp of 35\n";
   if (temperature >= 32)
      cout << "Above Freezing!\n";
   cout << "Fahrenheit is " << temperature << endl;

   // if else statement
   cout << "\n\n*****  If Else\n";
   if (x < y)
     min = x;
   else
     min = y;
    cout << "min = " << min;
}
