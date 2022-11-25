/*********************************************************************

  Filename:  student2.h
  Chapter:   10     Inheritance
  Section:   10.1   A Derived Type
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
#include <string.h>
class student {
public:
   enum year { fresh, soph, junior, senior, grad };
   student(char* nm, int id, double g, year x);
   void  print() const;
 protected:
   int     student_id;
   double  gpa;
   year    y;
   char  name[30];
};

class grad_student : public student {
public:
   enum support { ta, ra, fellowship, other };
   grad_student( char* nm, int id, double g,
        year x, support t, char* d, char* th);
   void  print() const;
protected:
   support  s;
   char     dept[10];
   char     thesis[80];
};

student::student(char* nm, int id, double g,year x)
   :student_id(id), gpa(g), y(x)
{
   strcpy(name, nm);
}

grad_student::grad_student (char* nm, int id, double g, year x,
    support t, char* d, char* th):student(nm, id, g, x), s(t)
{
   strcpy(dept, d);
   strcpy(thesis, th);
}

void student::print() const
{
   cout << name << " , " << student_id
        << " , " << y << " , " << gpa << endl;
}

void grad_student::print() const
{
   student::print(); //base class info is printed
   cout << dept << " , " << s << '\n'
        << thesis << endl;
}


