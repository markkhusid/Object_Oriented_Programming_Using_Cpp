/*********************************************************************

  Filename:  exer8.cpp
  Chapter:   2      The Native Types and Statements
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

// compute roots of a quadratic a * x * x + b * x + c

#include <iostream.h>
#include <math.h>

main()
{
   double a = 1.0, b, c, discr, sq_disc, root1, root2;
   cout << "\nEnter sets of numbers for quadratic until 0 is entered\n";

   while (a != 0.0) {
      cout <<" \nEnter 3 floating point numbers for quadratic solution: ";
     cin >> a >> b >> c;
     discr = b * b - 4 * a * c;
     if ((discr > 0) && (sq_disc = sqrt(discr))) {
        root1 = (-b + sq_disc) / (2 * a);
        root2 = (-b - sq_disc) / (2 * a);
     }
     else if (discr < 0) {       //complex roots
         cout << "\nComplex root not implemented\n";
      }
      else
         root1 = root2 = -b / (2 * a);
      cout << "\n a = " << a << "  b = " << b << "  c = " << c;
      cout << "  Root 1 = " << root1 << "   Root 2 = " << root2 << endl;
   }
}
