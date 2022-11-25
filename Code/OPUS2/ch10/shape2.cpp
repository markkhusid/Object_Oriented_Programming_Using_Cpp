/*********************************************************************

  Filename:  shape2.cpp
  Chapter:   10     Inheritance
  Section:   10.4   Virtual Functions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//shape hierarchy and virtual area() calculation

#include <iostream.h>

const double PI = 3.14159;

class shape {
public:
   virtual double  area() const { return 0; }
   //virtual double area is default behavior
   virtual char* get_name() = 0;
protected:
   double  x, y;
};

class rectangle : public shape {
public:
   rectangle(double h, double w): height(h), width(w) {}
   double  area() const { return (height * width); }
   char* get_name() { return (" RECTANGLE "); }
private:
   double  height, width;
};

class circle : public shape {
public:
   circle(double r): radius(r) {}
   double  area() const { return (PI * radius * radius);}
   char* get_name() { return (" CIRCLE "); }
private:
   double   radius;
};

int main()
{
   shape*     ptr_shape;
   rectangle  rec(4.1, 5.2);
   circle     cir(6.1);

   cout << "\nThis program uses hierarchies for shapes\n";

   ptr_shape = &rec;
   cout << endl << ptr_shape -> get_name();
   cout << "  area = " << ptr_shape -> area();

   ptr_shape = &cir;
   cout << endl << ptr_shape -> get_name();
   cout << "  area = " << ptr_shape -> area();
}
