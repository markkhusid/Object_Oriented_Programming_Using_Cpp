/*********************************************************************

  Filename:  set.cpp
  Chapter:   4      Implementing ADTs in the Base Language
  Section:   4.7    Bit Fields
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Set represented as bits.

#include  <iostream.h>

struct word {
unsigned w0:1,w1:1,w2:1, w3:1, w4:1, w5:1, w6:1, w7:1,
   w8:1, w9:1,w10:1,w11:1, w12:1, w13:1, w14:1, w15:1,
  w16:1,w17:1,w18:1,w19:1, w20:1, w21:1, w22:1, w23:1,
  w24:1,w25:1,w26:1,w27:1, w28:1, w29:1, w30:1, w31:1;
};

union set {
   word      m;
   unsigned  u;
};

int main()
{
   set  x, y;

   x.u = 0x0f100f10;
   y.u = 0x01a1a0a1;
   x.u = x.u | y.u;  //set union
   cout << "element 9 ="
        << ((x.m.w9)? "true" : "false") << endl;
}
