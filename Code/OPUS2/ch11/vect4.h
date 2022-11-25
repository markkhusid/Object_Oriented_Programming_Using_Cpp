/*********************************************************************

  Filename:  vect4.h
  Chapter:   11     Exceptions
  Section:   11.3   C++ Exceptions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

// Vector with raised exceptions
// Based on vect in chapter 7


#include <iostream.h>
#include <assert.h>     //for assertions

class vect {
public:
   explicit vect(int n);
   ~vect() { delete []p; }
   int  ub() const { return (size - 1); }  //upper bound
   vect& operator=(const vect& v);  //overload assignment
   void print() const;
   int&  operator[](int i) ;         //range checked
   vect operator+(const vect& v);
private:
   int*  p;
   int   size;
};

vect::vect(int n): size(n)
{
   if (n < 1) //precondition assertion
      throw (n);
   p = new int[n];
   if (p == 0)     //postcondition assertion
      throw ("FREE STORE EXHAUSTED");
}


int& vect::operator[](int i)
{
   assert(i >= 0 && i < size);
   return p[i];
}

vect& vect::operator=(const vect& v)
{
   int s = (size < v.size) ? size : v.size;

   if (v.size != size)
      cerr << "copying different size arrays "
           << size << " and " << v.size << endl;
   for (int i = 0; i < s; ++i)
      p[i] = v.p[i];
   return (*this);
}


void vect::print() const
{
   for (int i = 0; i <= (size-1); ++i)
      cout << p[i] << "\t";
   cout << endl;
}

vect vect::operator+(const vect& v)
{
   assert(size == v.size);
   vect  sum(size);
   for (int i = 0; i < size; ++i)
      sum.p[i] = p[i] + v.p[i];
   return sum;
}


