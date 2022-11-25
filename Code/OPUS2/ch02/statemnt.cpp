/*********************************************************************

  Filename:  statemnt.cpp
  Chapter:   2      The Native Types and Statements
  Section:   2.8    Statements
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Demonstrate various statements with simple examples

#include <iostream.h>
#include <math.h>
#include <ctype.h>

main()
{
   double a, x, y, min;
   int    i, j, n, sum, temperature = 35;
   int a_grades = 0, b_grades = 0, c_grades = 2, fails = 3, score = 8;
   const  MAX = 10;
   char   c;
   double d, ratio;

   //pre and post fix increments
   cout << "\n\n*****  Pre and Post fix";
   cout << "\nJ should be 1, 1, then I should be 2 and undetermined\n";
   i = 0;
   j = ++i;
   cout << "\nJ = " << j;
   j = i++;
   cout << "\nJ = " << j << "\nI = " << i;
   i = ++i + i++;  // hazardous practice that is system dependent
   cout << "\nI = " << i;

   //if statement
   cout << "\n\n*****  If statement";
   cout << "\n Next line should have above freezing temp of 35\n";
   if (temperature >= 32)
      cout << "Above Freezing!\n";
   cout << "Fahrenheit is " << temperature << endl;

   // if else statement
   cout << "\n\n*****  If Else";
   cout << "\nNext line should have min of 20.3\n";
   x = 20.3;
   y = 30.2;
   if (x < y)
      min = x;
   else
      min = y;
   cout << "min = " << min;


   //while statement
   cout << "\n\n*****  While";
   cout << "\nSum of 55 and 11\n";
   i = 1;
   sum = 0;

   while (i <= 10) {
      sum += i;
      ++i;
   }

   cout << "\nSum = " << sum << "  I = " << i;

   //for statement
   cout << "\n\n*****  For statement";
   cout << "\nSum of 55 and 11";
    sum = 0;
   for (i = 1; i <= 10; ++i)
      sum += i;
   cout << "\nSum = " << sum << "  I = " << i;


   //do statement
   cout << "\n\n*****  Do Statement";
   cout << "\nEnter numbers as long as number > 0 and sum them\n";
   i = 0;
   sum = 0;

   do {
      sum += i;
      cin >> i;
   } while (i > 0);
   cout << "\nSum of input numbers is " << sum;


   //do while statement
   cout << "\n\n*****  Do Statement";
   cout << "\nInput numbers until a positive is input\n";
   do {
      cout << "\nEnter a positive integer: ";
      cin >> n;
   } while (n <= 0);

   // for statement with break
   cout << "\n\n*****  For statement with break";
   cout << "\nInput 10 numbers for square root but break if negative\n";

   for (i = 0; i < 10; ++i) {
      cin >> x;
      if (x < 0.0) {
         cout << "All done" << endl;
         break;        // exit loop if value is negative
      }
      cout << sqrt(x) << endl;
   }
   // break jumps to here


   //For statement with continue
   cout << "\n\n*****  For statement with continue";
   cout << "\nEnter 10 chars in one string and count non-digits\n";
   for (i = 0; i < MAX; ++i) {
      cin.get(c);
      if (isdigit(c))
         continue;
       // process other characters
      cout << "\nNon-digit encountered: " << c;   // process other characters
   // continue jumps to here
   }

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

   //Goto Statement
   cout << "\n\nGoto Statement";
   cout << "\nEnter 5 numbers for division, if 0, get error msg\n";

   n = 33;
   for (i = 0; i < 5; ++i) {
      n += i * 2;
      cin >> d;
      if (d == 0.0)
         goto error;
      else
         ratio = n / d;
      cout << "N = " << n << "  D = " << d << "   N/D = " << ratio << endl;
      continue;
      error:  cerr << "ERROR:  division by zero\n";
   }
}

