/*********************************************************************

  Filename:  twod.cpp
  Chapter:   5      Data Hiding and Member Functions
  Section:   5.9    Container and Item Access
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

// Dynamic arrays in two dimensions.

class twod {
public:
   bool allocate(int r, int s);//pseudo- constructor
   void deallocate();          //pseudo- destructor
   double& element_lval(int i, int j) const
      { return base[i][j]; }
   double  element_rval(int i, int j) const
      { return base[i][j]; }
   int     r_size() const { return row_size; }
   int     c_size() const { return column_size; }
private:
   double**  base;
   int       row_size, column_size;
};

bool twod::allocate(int r, int s)
{
   base = new double*[s];
   if (base == 0)  //allocation failed
      return false;
   for (int i = 0; i < s; ++i) {
      base[i] = new double[r];
      if (base[i] == 0)  //allocation failed
         return false;
   }
   row_size = r;
   column_size = s;
   return true;
}

void twod::deallocate()
{
   for (int i = 0; i < column_size; ++i)
      delete [] base[i];
   delete [] base;
   row_size = 0;
   column_size = 0;
}

double find_max(const twod& m)
{
   int    i, j;
   double max = m.element_rval(0,0);
    for (i = 0; i < m.c_size(); ++i)
      for (j = 0; j < m.r_size(); ++j)
         if (m.element_rval(i, j) > max)
            max = m.element_rval(i, j);
   return max;
}

void init(const twod& m)
{
   int    i, j, base = 1;


   for (i = 0; i < m.c_size(); ++i)
       for (j = 0; j < m.r_size(); ++j)
          m.element_lval(i, j) = (i + base++) * (j + base++);
}

void print(const twod& m)
{
   int    i, j;

   cout << endl;
   for (i = 0; i < m.c_size(); ++i)  {
      for (j = 0; j < m.r_size(); ++j)
          cout << m.element_rval(i, j) << '\t';
       cout << endl;
  }
}

void transpose(twod& m)
{
   int    i, j;
   double temp;

    for (i = 0; i < m.c_size() - 1 ; ++i)
       for (j = i + 1; j < m.r_size(); ++j) {
          temp = m.element_lval(i, j);
          m.element_lval(i, j) = m.element_lval(j, i);
          m.element_lval(j, i) = temp;
       }
}

int main()
{
   twod m;
   m.allocate(5, 10);

   m.element_lval(1, 1) = 5;    //store 5 in m.base[1][1]
   cout << (m.element_rval(1, 1) ==  m.element_lval(1, 1));
         //okay 5 == 5
   init(m);
   print(m);
   cout << "\nMax is " << find_max(m) << endl;
   transpose(m);  // this doesn't appear to work
   print(m);

}
