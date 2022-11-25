/*********************************************************************

  Filename:  dynarray.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.19   Free Store Operators New and Delete
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Use of new to dynamically allocate an array.

#include  <iostream.h>
#include  <assert.h>

double avg_arr(const int a[], int size)
{
   int  sum = 0;
   for (int i = 0; i < size; ++i)
      sum += a[i];
   return static_cast<double>(sum)/size;
}

int main()
{
   int*  data;
   int   size;

   for (int n_loop = 0; n_loop < 5; ++n_loop)
   {
      cout << "\nEnter array size: ";
      cin >> size;
      assert(size > 0);
      data = new int[size]; //allocate array
      assert(data != 0);
      for (int j = 0; j < size; ++j)
         cin >> data[j];
      cout << " average is "
           << avg_arr(data, size) << endl;
      delete []data;        //deallocate array
   }
}
