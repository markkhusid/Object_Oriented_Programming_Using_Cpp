/*********************************************************************

  Filename:  student1.cpp
  Chapter:   1      Why Object Oriented Programming in C++?
  Section:   1.8    Inheritance
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
#include <string.h>

enum support { ta, ra, fellowship, other };
enum year { fresh, soph, junior, senior, grad };

class student {
public:
   student(char* nm, int id, double g, year x);
   void  print() const;
private:
   int     student_id;
   double  gpa;
   year    y;
   char    name[30];
};

class grad_student : public student {
public:
   grad_student(char* nm, int id, double g,
                year x, support t, char* d, char* th);
   void print() const;
private:
   support  s;
   char     dept[10];
   char     thesis[80];
};

student::student(char* nm, int id, double g, year x)
		:student_id(id), gpa(g), y(x)
{
   strcpy(name, nm);
}

grad_student::grad_student(
   char* nm, int id, double g, year x,
   support t, char* d, char* th)
   :student(nm, id, g, x), s(t)
{
   strcpy(dept, d);
   strcpy(thesis, th);
}

void student::print() const
{
   cout << '\n' << name << " , " << student_id << " , "
	<< y  << " , " << gpa << endl;
}

void grad_student::print() const
{
   student::print();
   cout << dept << " , " << s << '\n' << thesis << endl;
}

//Test pointer conversion rules.

int main()
{
   student        s("Mae Pohl", 100, 3.425, fresh), *ps = &s;
   grad_student   gs("Morris Pohl", 200, 3.2564, grad, ta, "Pharmacy",
		    "Retail Pharmacies"), *pgs;

   ps -> print();
   ps = pgs = &gs;
   ps -> print();
   pgs -> print();    //grad_student::print
}
