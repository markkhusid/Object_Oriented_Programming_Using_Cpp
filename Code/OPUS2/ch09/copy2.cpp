/*********************************************************************

  Filename:  copy2.cpp
  Chapter:   9      Templates, Generic Programming and STL
  Section:   9.2    Function Templates
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

//Better template copy array function

template<class T1, class T2>
void copy(T1 a[], T2 b[], int n)
{
   for (int i = 0; i < n; ++i)
      a[i] = b[i];
}

template<class TYPE>
void print(TYPE a[], int n)
{
   cout << "\nNEW PRINT =";
   for (int i = 0; i < n; ++i)
      cout << a[i] << " ";
}


int main()
{
   double  f1[50], f2[50];
   char    c1[25], c2[50];
   char*   ptr1, *ptr2;
   int     i1[75], i2[75];
   int     i;

   ptr1 = new char[100];
   ptr2 = new char[100];

   for (i = 0; i < 50; ++i) { //init arrays
      f1[i] = 1.1 + i;
      f2[i] = 2.2 * i;
      c2[i] = 'A' + i/5;
      ptr1[i] = 'A' + i/10;
      ptr2[i] = 'a' + i/10;
   }

   for (i = 0; i < 25; ++i) { //init arrays
      c1[i] = 'a' + i/8;
   }

   for (i = 0; i < 75; ++i) { //init arrays
      i1[i] = 2 * i;
      i2[i] = i * i;
   }

   print(f1, 20);    //print initial values
   print(f2, 20);
   print(i1, 20);
   print(i2, 20);
   print(c1, 20);
   print(c2, 20);
   print(ptr1, 20);
   print(ptr2, 20);

   copy(f1, f2, 50);
   copy(c1, c2, 10);
   copy(i1, i2, 40);
   copy(ptr1, ptr2, 100);
   copy(i1, f2, 50);  //  now will compile
   copy(c1, f2, 50);  // now will compile

   print(f1, 20);    //print copied values
   print(f2, 20);
   print(i1, 20);
   print(i2, 20);
   print(c1, 20);
   print(c2, 20);
   print(ptr1, 20);
   print(ptr2, 20);
}
