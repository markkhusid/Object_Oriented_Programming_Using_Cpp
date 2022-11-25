/*********************************************************************

  Filename:  how_many.cpp
  Chapter:   5      Data Hiding and Member Functions
  Section:   5.4    Class Scope
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Scope resultion operator use
#include <iostream.h>

int N = 10; //max size of array to work with
int  count = 0;        //external variable

void how_many(double w[], double x, int& count)
{
    for (int i = 0; i < N; ++i)
       count += (w[i] == x);
    ++ ::count;         //keep track of calls
}

int main()
{
   const int N = 10;
   count = 0;        //local count variable to increment
   double val_check = 1.1;  //first search on 1.1
   double array[N] = {1.1, 2.2, 1.1, 4.4, 5.5};  //init 1st five values

   cout << "\nInitial counts:   local: " << count << "  global: " << ::count;
   how_many(array, val_check, count);
   how_many(array, 2.2, count);
   cout << "\nNew counts:       local: " << count << "  global: " << ::count;
}