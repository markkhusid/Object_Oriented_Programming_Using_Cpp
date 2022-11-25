/*********************************************************************

  Filename:  clock.cpp
  Chapter:   7      Ad Hoc Polymorphism
  Section:   7.6    Unary, Binary Overloading
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Clock to show overloading


#include <iostream.h>

class clock {
public:
   clock(unsigned long i);   //constructor and conversion
   void  print() const;      //formatted printout
   void  tick();             //add one second
   clock operator++(){ tick(); return *this; }
   void reset (const clock& c);
   friend clock operator +(clock c1, clock c2);
   clock operator -(clock c);
   friend clock operator *(unsigned long m, clock c);
   friend clock operator *(clock c, unsigned long m);
private:
   unsigned long  tot_secs, secs, mins, hours, days;
};

inline clock::clock(unsigned long i)
{
   tot_secs = i;
   secs = tot_secs % 60;
   mins = (tot_secs / 60) % 60;
   hours = (tot_secs / 3600) % 24;
   days = tot_secs / 86400;
}

void clock::tick()
{
   clock  temp = clock(++tot_secs);

   secs = temp.secs;
   mins = temp.mins;
   hours = temp.hours;
   days = temp.days;
}

void clock::reset(const clock& c)
{
   tot_secs = c.tot_secs;
   secs = c.secs;
   mins = c.mins;
   hours = c.hours;
   days = c.days;
}

clock operator+(clock c1, clock c2)
{
   return (c1.tot_secs + c2.tot_secs);
}

clock clock::operator-(clock c)
{
   return (tot_secs - c.tot_secs);
}


clock operator*(unsigned long m, clock c)
{
   return (m * c.tot_secs);
}

clock operator*(clock c, unsigned long m)
{
   return (m * c.tot_secs);
}

void clock::print() const
{
   cout << days << " d :" << hours << " h :"
        << mins << " m :" << secs << " s" << endl;
}

//Clock and overloaded operators

int main()
{
   clock  t1(59), t2(172799); //172799 = 2 days - 1 sec
   clock t3(0);
   clock c1(900), c2(400);

   cout << "initial times are" << endl;
   t1.print();
   t2.print();
   ++t1;  ++t2;
   cout << "after one second times are" << endl;
   t1.print();
   t2.print();
   cout << "\nt1 + t2   t1 * 5    6 * t1 * 5     6 * t1 * 5 - t2\n";
   t3 = t1 + t2;
   t3.print();
   t3 = t1 * 5;
   t3.print();
   t3 = 6 * t3;
   t3.print();
   t3 = t3 - t1;
   t3.print();
   c1.reset(c2);
   c2.reset(100);
   cout << "\nc1 and c2\n";
   c1.print();
   c2.print();
}

