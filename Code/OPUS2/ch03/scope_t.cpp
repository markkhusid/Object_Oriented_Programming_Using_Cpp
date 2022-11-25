/*********************************************************************

  Filename:  scope_t.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.8    Scope and Storage Class
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Scope Demonstration

#include <iostream.h>

//C++ but not C

int max(int c[], int size)
{
   cout << "array size is " << size << endl;
   int  comp = c[0];             //declaration of comp
   for (int i = 1; i < size; ++i)  //declaration of i
      if (c[i] > comp)
         comp = c[i];
   return comp;
}

int main()
{
   const size = 7;   //array of size 7
   int arr[size] = {3, 5, 6, 2, 9, 5, 4}; //allocate and init array

   cout << "\nThis program prints inner and outer block values, 2, 7, 3\n";

   {
   int  a = 2;               // outer block a
   cout << a << endl;        // prints 2
   {                         // enter inner block
      int  a = 7;            // inner block a
      cout << a << endl;     // prints 7
   }                         // exit inner block
   cout << ++a << endl;      // 3 is printed
}

   cout << "\nMax of array should be 9.   It is " << max(arr, size) << endl;
 }
