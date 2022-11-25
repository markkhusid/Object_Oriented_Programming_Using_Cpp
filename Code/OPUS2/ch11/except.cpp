/*********************************************************************

  Filename:  except.cpp
  Chapter:   11     Exceptions
  Section:   11.10  Standard Exceptions and their Use
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
#include <except.h> //contains xalloc and xmsg In the ANSI standard library

// Enter a billion to force exception

int main()
{
   int *p, n;

   try {
      while (true) {
         cout << "enter allocation request:" << endl;
         cin >> n;
         p = new int[n];
      }
   }
   catch(xalloc x ){cout << "xalloc caught" << endl;}
   catch(...){cout << "default catch\n" << endl;}
}
