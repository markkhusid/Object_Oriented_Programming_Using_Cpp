/*********************************************************************

  Filename:  vect3.h
  Chapter:   C      Appendix C - Language Guide
  Section:   C.16   Inheritance
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include  <iostream.h>
#include  <assert.h>

class vect {
public:
   vect() { size = 10; p = new int[size]; }
   explicit vect(int n);
   vect(const vect& v);
   vect(const int a[], int n);  //initialize by array
   ~vect() { delete []p; }
   int  ub() const { return (size - 1); }  //upper bound
   vect& operator=(const vect& v);  //overload assignment
   int&  operator[](int i) ;         //range checked
   vect operator+(const vect& v);
 	friend ostream& operator <<(ostream& out, const vect& v);
protected:
   int*  p;
   int   size;
   friend vect mpy(const vect& v, const matrix& m);
};

vect::vect(int n) : size(n)
{
   assert(n > 0);
   p = new int[size];
   assert(p != 0);
}

vect::vect(const int a[], int n) : size(n)
{
   assert(n > 0);
   p = new int[size];
   assert(p != 0);
   for (int i = 0; i < size; ++i)
      p[i] = a[i];
}

vect::vect(const vect& v) : size(v.size)
{
   p = new int[size];
   assert(p != 0);
   for (int i = 0; i < size; ++i)
      p[i] = v.p[i];
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

//overloaded output operator
ostream& operator <<(ostream& out, const vect& v)
{
	for (int i = 0; i <= (v.size-1); ++i)
		out << v.p[i] << '\t';
	return (out << endl);
}



vect vect::operator+(const vect& v)
{
   assert(size == v.size);
   vect  sum(size);
   for (int i = 0; i < size; ++i)
      sum.p[i] = p[i] + v.p[i];
   return sum;
}


