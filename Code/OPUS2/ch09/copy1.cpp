/*********************************************************************

  Filename:  copy1.cpp
  Chapter:   9      Templates, Generic Programming and STL
  Section:   9.2    Function Templates
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//  Title: copy

#include <iostream.h>

//Template copy array function

template<class TYPE>
void copy(TYPE a[], TYPE b[], int n)
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
   int     i1[75], i2[75];
   int     i;

   for (i = 0; i < 50; ++i) { //init arrays
      f1[i] = 1.1 + i;
      f2[i] = 2.2 * i;
      c2[i] = 'A' + i/5;
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

   copy(f1, f2, 50);
   copy(c1, c2, 10);
   copy(i1, i2, 40);

//   copy(i1, f2, 50);  //  no match on compile
//   copy(c1, f2, 50); // no match on compile

   print(f1, 20);    //print initial values
   print(f2, 20);
   print(i1, 20);
   print(i2, 20);
   print(c1, 20);
   print(c2, 20);
}
