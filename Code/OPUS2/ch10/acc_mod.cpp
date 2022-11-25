/*********************************************************************

  Filename:  acc_mod.cpp
  Chapter:   10     Inheritance
  Section:   10.10  Pragmatics
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Access modification

// This code does not compile
// It demonstrates access errors

class B {
public:
   int  k;
protected:
   int  j, n;
private:
   int  i;
};

class D : public B {
public:
   int  m;
   B::n;  //illegal protected access cant be broadened
private:
   B::j;  //otherwise default is protected
};

int main()
{
   D testD;
   B testB;
}
