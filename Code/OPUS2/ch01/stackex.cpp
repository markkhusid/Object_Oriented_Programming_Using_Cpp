/*********************************************************************

  Filename:  stackex.cpp
  Chapter:   1      Why Object Oriented Programming in C++?
  Section:   1.11   Exceptions
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//template stack implementation

#include <iostream.h>


class stack {
public:
   explicit stack(int n);
   ~stack() { delete []p; }
   void  reset() { top = EMPTY; }
   void  push(char c) { p[++top] = c; }
   char  pop() { return p[top--]; }
   char  top_of() { return p[top]; }
   bool  empty() { return (top == EMPTY); }
   bool  full() { return (top == max_len - 1); }
private:
   enum   {EMPTY = -1};
   char*  p;
   int    max_len;
   int    top;
};



//stack constructor with exceptions
stack::stack(int n)
{
   if (n < 1)
      throw (n);        //want a positive value
   p = new char[n];     //create a stack of characters
   if (p == 0)          //new returns 0 when it fails
      throw ("FREE STORE EXHAUSTED");
   top = EMPTY;
   max_len = n;
}



main()
{
	 int n = 15;
	 try {
      stack  a(5);
      stack  b(n);        //if n is negative or 0, then give error

      char ch =  'A';

      while (!a.full())
         a.push(ch++);
      cout << "\na stack is ";
      while (!a.empty())
         cout << a.pop() << '\t';

      //  int n = 10;     //this should run ok
      int n = -10;        //should give an error

      ch = 'a';
      while (!b.full())
         b.push(ch++);

       cout << "\nb stack is ";
      while (!b.empty())
         cout << b.pop() << '\t';

      } catch (int n) { cout << "\nWrong size = " << n ; } //an incorrect size
        catch (char*) { cout << "\nOut of memory" ;}  //couldn't get it
}
