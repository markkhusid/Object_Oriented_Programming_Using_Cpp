/*********************************************************************

  Filename:  ex18.cpp
  Chapter:   6      Object Creation and Destruction
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
// Implementation of an ADT for type set.
const unsigned long int  masks[32] = {
   0x80000000, 0x40000000, 0x20000000, 0x10000000,
   0x8000000, 0x4000000, 0x2000000, 0x1000000,
   0x800000, 0x400000, 0x200000, 0x100000,
   0x80000, 0x40000, 0x20000, 0x10000,
   0x8000, 0x4000, 0x2000, 0x1000,
   0x800, 0x400, 0x200, 0x100,
   0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1};

class set {
public:
   set(unsigned long int i) { t = i; }
   set() { t = 0x0; }
   void  u_add(int i) { t |= masks[i]; }
   void  u_sub(int i) { t  &= ~masks[i]; }
   bool  in(int i) const
      { return bool( (t  & masks[i]) != 0); }
   void  pr_mems() const;
   set  set_union(const set& v) const
      { return (set(t | v.t)); }
private:
   unsigned long int  t;
};


void set::pr_mems() const
{
   cout << "\n set members { ";
   for (int i = 0; i < 32; ++i)
      if (this -> in(i))
         cout << i << "'  ";
   cout << "}\n";
}

int main()
{
   set   s(0x555), t(0x10303021);
   set   w, y, z;

   cout << "\ns, t, w, s+3, t-31, s union t, s inter t\n";
   s.pr_mems();
   t.pr_mems();
   w.pr_mems();

   s.u_add(3);
   t.u_sub(31);

   s.pr_mems();
   t.pr_mems();

   y = t.set_union(s);
   y.pr_mems();
}
