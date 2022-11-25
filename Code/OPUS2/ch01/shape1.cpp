/*********************************************************************

  Filename:  shape1.cpp
  Chapter:   1      Why Object Oriented Programming in C++?
  Section:   1.9    Polymorphism
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//shape hierarchy and virtual area() calculation
//shape is an abstract base class#include <iostream.h>

#include <iostream.h>


//shape is an abstract base class.
class shape {
public:
	virtual double area() = 0;   //pure virtual function
	virtual char* get_name() = 0;
};

class rectangle : public shape {
public:
   rectangle(double h, double w) : height(h), width(w){}
	double area() {return (height * width);}  //override
	char* get_name() { return (" RECTANGLE "); }
	private:
   double height, width;
};

class circle : public shape {
public:
	circle(double r) : radius(r) { }
	double area() {return(3.14159 * radius * radius);}
	char* get_name() { return (" CIRCLE "); }
private:
   double radius;
};


class square : public rectangle {
public:
	square(double h) : rectangle(h,h) { }
	double area() { return (rectangle::area()); }
	char* get_name() { return (" SQUARE "); }
};


int main()
{
   shape*     ptr_shape;
   rectangle  rec(4.1, 5.2);
   square     sq(5.1);
   circle     cir(6.1);

   cout << "\nThis program uses hierarchies for shapes\n";

   ptr_shape = &rec;
	cout << endl << ptr_shape -> get_name();

   cout << "  area = " << ptr_shape -> area();

   ptr_shape = &cir;
   cout << endl << ptr_shape -> get_name();
   cout << "  area = " << ptr_shape -> area();

   ptr_shape = &sq;
   cout << endl << ptr_shape -> get_name();
   cout << "  area = " << ptr_shape -> area();
}
