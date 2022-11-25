/*********************************************************************

  Filename:  bellmult.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.2    Function Definition
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Repeated bell ringing.

#include  <iostream.h>
const char  BELL = '\a';
void ring(int k)
{
   int  i;

   for (i = 0; i < k; ++i)
      cout << BELL;
}
int main()
{
   int  n;

   cout << "\nInput a small positive integer:  ";
   cin >> n;
   ring(n);
}
