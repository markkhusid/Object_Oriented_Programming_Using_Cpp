/*********************************************************************

  Filename:  switch_t.cpp
  Section:   2.8    The Switch Statement
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Demonstrate switch statements with simple examples

#include <iostream.h>

main()
{
   int a_grades = 0, b_grades = 0, c_grades = 2, fails = 3, score = 8;
   double d, ratio;


   //Switch statement
   cout << "\n\n***** Switch statement";
   cout << "\nA, B, C, D  = 0, 1, 2, 3\n";

   // add one b_grade for print purposes

   switch (score){
   case 9: case 10:
      ++a_grades; break;
   case 8:
      ++b_grades; break;
   case 7:
      ++c_grades; break;
   default:
      ++fails;
   }
   cout << "\nA grades = " << a_grades;
   cout << "\nB grades = " << b_grades;
   cout << "\nC grades = " << c_grades;
   cout << "\nFails = " << fails;
}
