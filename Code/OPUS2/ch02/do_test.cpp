/*********************************************************************

  Filename:  do_test.cpp
  Section:   9.6    The Do Statement
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Demonstrate do statements with simple examples

#include <iostream.h>

main()
{

   int n;

   //while statement
   //do statement
   cout << "\n\n*****  Do Statement";
   do {
      cout << "\nEnter a positive integer: ";
      cin >> n;
   } while (n <= 0);

   cout << "\nPositive numbers is " << n;
}
