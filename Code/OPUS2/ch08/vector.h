/*********************************************************************

  Filename:  vector.h
  Chapter:   8      Visitation: Iterators and Containers
  Section:   8.1    Visitation
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Vector type in new style for iteration

#include <iostream.h>
#include <assert.h>

class vector{
public:
   typedef int* iterator;     //pointer type vector::int*
   explicit vector(int n = 1);
   vector(const vector& v);
   vector(const int a[], int n);
   ~vector() { delete []bp; }
   iterator begin()const { return bp; }
   iterator end()const { return bp + size; }
   int  ub()const {return size - 1;} //upper bound
   int& operator[](int i);           //range checked
   vector& operator=(const vector& v);
   friend ostream& operator<<(ostream& out, const vector& v);
   friend istream& operator>>(istream& in, vector& v);
private:
   iterator bp;                   //base pointer
   int size;                      //number of elements
};

vector::vector(int n)
{
   assert(n > 0);
   size = n;
   bp = new int[size];
   assert(bp);
}

vector::vector(const int a[], int n)
{
   assert(n > 0);
   size = n;
   bp = new int[size];
   assert(bp);
   for (int i = 0; i < size; ++i)
      bp[i] = a[i];
}

vector::vector(const vector& v)
{
   assert(v.size);
   size = v.size;
   bp = new int[size];
   assert(bp);
   for (int i = 0; i < size; ++i)
      bp[i] = v.bp[i];
}


int& vector::operator [](int i)
{
   assert (i >= 0 && i < size);
   return (bp[i]);
}

vector& vector::operator =(const vector& v)
{
   int s = (size < v.size) ? size : v.size;

   assert (v.size == size);
   for (int i = 0; i < s; ++i)
      bp[i] = v.bp[i];
   return (*this);
}


ostream& operator<<(ostream& out, const vector& v)
{
   vector::iterator p;

   for (p = v.begin(); p != v.end(); ++p)
      out << *p << '\t';
   out << endl;
   return out;
}

istream& operator>>(istream& in, vector& v)
{
   vector::iterator p;

   for (p = v.begin(); p != v.end(); ++p)
   in >> *p;
   return in;
}


