/*********************************************************************

  Filename:  namespac.cpp
  Section:   3.9    Namespaces
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
namespace LMPout {
   int  n;
   namespace LMPin {
      int  sq(){ return n * n; } //LMPout::n
      void  pr_my_logo();
   }
   void  LMPin::pr_my_logo()
      { cout << "LMPinc" << endl; }
}

int main()
{
   LMPout::LMPin::pr_my_logo();
   using LMPout::LMPin;
   LMPout::n = 8;
   LMPout::n++;
   cout << "\nsquare is " << LMPin::sq() << endl;
   LMPin::pr_my_logo();
}
