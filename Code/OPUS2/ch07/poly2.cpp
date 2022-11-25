/*********************************************************************

  Filename:  poly2.cpp
  Chapter:   7      Ad Hoc Polymorphism
  Section:   7.9    Type and Language Expectations
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//A polynomial represented as a singly linked list

#include <assert.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

struct term {
   int        exponent;
   double     coefficient;
   term*      next;
   term(int e, double c, term* n = 0):exponent(e), coefficient(c), next(n){}
   void print(){ cout << coefficient << "x^" << exponent << " ";}
};


//Polynomials with overloaded arithmetic operators
class polynomial {
public:
   polynomial();
   polynomial(const polynomial& p);
   polynomial(int size, double coef[], int expon[]);
   ~polynomial() { release(); }
   void print() const;
   double operator()(double x) const;  //evaluate P(x)
   polynomial& operator=(const polynomial& a);
   friend polynomial& operator+(const polynomial& a,
                                const polynomial& b);
   friend polynomial& operator-(const polynomial& a,
                                const polynomial& b);
   friend polynomial& operator*(const polynomial& a,
                                const polynomial& b);
   friend polynomial& operator/(const polynomial& a,
                                const polynomial& b);
   friend polynomial& operator-(const polynomial& a);
   friend polynomial& operator+=(const polynomial& a,
                                 const polynomial& b);
   friend bool operator==(const polynomial& a,
                             const polynomial& b);
   friend bool operator!=(const polynomial& a,
                             const polynomial& b);
private:
   term*   h;
   int     degree;
   void    prepend(term*  t);
   void    add_term(term*& a, term*& b);
   void    release();
   void    rest_of(term* rest);
   void    reverse();
};

inline void advance(term*& t) { assert(t != 0); t = t -> next; }
inline void polynomial::prepend(term*  t) { t -> next = h; h = t; }

void polynomial::reverse()  //in place
{
   term*  pred, *succ, *elem;

   if (h && (succ = h -> next)) {
      pred = 0;
      elem = h;
      while (succ) {
	 elem -> next = pred;
	 pred = elem;
	 elem = succ;
	 advance(succ);
      }
      h = elem;
      h -> next = pred;
   }
}

void polynomial::release()
{
   term* temp = h;

   if (h) {  h = h -> next; delete temp; release(); }


}


void polynomial::print() const
{
   term* temp = h;

   if (h == 0) { cout << "0\n"; return; }
   while (temp){ temp -> print(); temp = temp -> next; }
   cout << endl;
}

//assumes ordering is correct expon[i] < expon[i+1]
polynomial::polynomial(int size, double coef[], int expon[])
{
   term* temp = new term(expon[0], coef[0]);

   h = 0;
   prepend(temp);     //create initial term
   for (int i = 1; i < size; ++i) {
       assert(expon[i - 1] < expon[i]);
       temp = new term(expon[i], coef[i]);
       prepend(temp); //add term
   }
   degree = h -> exponent;
}

polynomial::polynomial(const polynomial& p) : degree(p.degree)
{
   term* elem = p.h, *temp;

   h = 0;
   while (elem) {   //term by term copying
      temp = new term(elem -> exponent, elem -> coefficient);
      prepend(temp);
      advance(elem);
   }
   reverse();
}

void polynomial::add_term(term*& a, term*& b)
{
   term*  c;

   if (a -> exponent != b -> exponent) {
      if (a -> exponent > b -> exponent) { //add a
	       c = new term(a -> exponent, a -> coefficient) ;
	       advance(a);
      }
      else { //add b
	       c = new term(b -> exponent, b -> coefficient) ;
	       advance(b);
      }
      prepend(c);
   }
   else { //check on cancellation
      if (a -> coefficient + b -> coefficient != 0) {
	       c = new term(a -> exponent, a -> coefficient + b -> coefficient) ;
	       prepend(c);
      }
      advance(a); advance(b);
   }
}

void polynomial::rest_of(term* rest)
{
   term* temp = h;

   while (rest) {
      temp  = new term(rest -> exponent, rest -> coefficient);
      prepend(temp);
      advance(rest);
   }
}


polynomial& polynomial::operator=(const polynomial& a)
{
   if (h != a.h) {   //avoid a = a case
      release();        //garbage collect old value
      polynomial* temp = new polynomial(a);
      h = temp -> h;
      degree = temp -> degree;
   }
   return *this;
}


main()
{
   double coef[4] = {1, 2, 3, 4};
   double coef2[4] = {-1,-2, -3, -4};
   double coef3[4] = {7, 3, -4, 7};
   int    expo[4] = {0, 4, 14, 45};
   int    expo2[4] = { 5, 6, 14, 45};

   polynomial p(4, coef2, expo),
              q(4, coef,  expo),
              r(4, coef3, expo2);

   cout << "P(x) = ";
   p.print();
   cout << "Q(x) = ";
   q.print();
   cout << "R(x) = ";
   r.print();
   r = q;
   cout << "R(x) = ";
   r.print();
}

