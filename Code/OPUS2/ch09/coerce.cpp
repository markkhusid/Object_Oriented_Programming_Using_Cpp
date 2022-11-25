/*********************************************************************

  Filename:  coerce.cpp
  Chapter:   9      Templates, Generic Programming and STL
  Section:   9.3    Class Templates    
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

template <class T1, class T2>
bool coerce(T1& x, T2 y)
{
   if (sizeof(x) < sizeof(y))
      return false;
   x = static_cast<T1>(y);
   return true;
}

int main()
{
   int i, j;
   float  x;
   double y;
   char   ch1;


   i = 'a';   ch1 = 'b';
   cout << "\ncoerce int, ch  = ";
   cout << coerce(i, ch1);
   cout << "   i = " << i << "  ch1 = " << ch1;

   i = 'a';  ch1 = 'b';
   cout << "\ncoerce ch,  int = ";
   cout << coerce(ch1, i);
   cout << "   i = " << i << "  ch1 = " << ch1;

   x = 1.1;   y = 2.2;
   cout << "\ncoerce fl,  dbl = ";
   cout << coerce(x, y);
   cout << "   x = " << x << "  y = " << y;

   x = 1.1;  y = 2.2;
   cout << "\ncoerce dbl, fl  = ";
   cout << coerce(y, x);
   cout << "   x = " << x << "  y = " << y;
   cout << endl;   cin>> i;
}
