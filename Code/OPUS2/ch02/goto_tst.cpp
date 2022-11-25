/*********************************************************************

  Filename:  goto_tst.cpp
  Section:   2.8    The goto Statement
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Demonstrate goto statements with simple examples

#include <iostream.h>

main()
{
   int    i, n;
   double d, ratio;


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

