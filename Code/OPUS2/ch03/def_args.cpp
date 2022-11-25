/*********************************************************************

  Filename:  def_args.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.5    Default Arguments
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Default arguments

#include <iostream.h>

//Raise n to the k power

int sqr_or_power(int n, int k = 2)   //k = 2 is default
{
   if (k == 2)
      return (n * n);
   else
      return (sqr_or_power(n, k - 1) * n);
}

int main()
{
   int i;

   i = 3;
   cout << "\nThis program outputs 8 squared and 8 cubed\n";
   cout << sqr_or_power(i + 5) << "   "  << sqr_or_power(i + 5, 3) << endl;
}
