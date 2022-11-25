/*********************************************************************

  Filename:  m_to_k.cpp
  Chapter:   2      The Native Types and Statements
  Section:   2.5    The Traditional Conversions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Miles are converted to kilometers.
#include  <iostream.h>
const double  m_to_k = 1.609;   //conversion constant

inline double  mi_to_km(int miles)
{
    return (miles * m_to_k);
}

int main()
{
   int  miles;
   double kilometers;

   do {
      cout << "\nEnter distance in miles: ";
      cin >> miles;
      kilometers = mi_to_km(miles);
      cout << "\nThis is approximately "
           <<  static_cast<int>(kilometers)
           << "km."<< endl;
   } while (miles > 0);
}

