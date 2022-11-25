/*********************************************************************

  Filename:  stack_t2.h
  Chapter:   10     Inheritance
  Section:   10.6   Templates and Inheritance
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Stack implementation with constructor

#include <iostream.h>
#include <assert.h>

///template stack implementation
template <class TYPE>
class stack {
public:
   explicit stack(int size = 100)
      : max_len(size), top(EMPTY)
         { s = new TYPE[size]; assert (s != 0); }
   ~stack() { delete []s; }
   void  reset() { top = EMPTY; }
   void  push(TYPE c) { s[++top] = c; }
   TYPE  pop() { return s[top--]; }
   TYPE  top_of()const { return s[top]; }
   bool  empty()const { return top == EMPTY;}
   bool  full()const { return top == max_len - 1;}
private:
   enum   { EMPTY = -1 };
   TYPE*  s;
   int    max_len;
   int    top;
};


template <class T1>
void print_and_pop(T1& a, char* comment)
{
   cout << "Printing " << comment << endl;
   while (!a.empty())
      cout << a.pop() << '\t';
   cout << endl;
}



