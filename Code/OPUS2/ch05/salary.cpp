/*********************************************************************

  Filename:  salary.cpp
  Chapter:   5      Data Hiding and Member Functions
  Section:   5.8    static and const Member Functions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

//Calculate salary using static members.
class salary {
public:
   void init(const int b) {b_sal = b; your_bonus = 0;}
   void  calc_bonus(const double perc)
      { your_bonus = b_sal * perc; }
   static void  reset_all(const int p)
      { all_bonus = p; }
   int  comp_tot() const
      { return (b_sal + your_bonus + all_bonus); }
private:
   int         b_sal;
   int         your_bonus;
   static int  all_bonus;     //declaration
};

//declaration and definition
int salary::all_bonus = 100;

int main()
{
   salary  w1, w2;

   w1.init(1000);
   w2.init(2000);
   w1.calc_bonus(0.2);
   w2.calc_bonus(0.15);
   salary::reset_all(400);
   cout << " w1 " << w1.comp_tot() << "   w2 "
        << w2.comp_tot() << endl;
}
