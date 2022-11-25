/*********************************************************************

  Filename:  genstack.h
  Chapter:   8      Visitation: Iterators and Containers
  Section:   8.5    Genericity with void*
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//generic stack implementation:genstack.h
#include <assert.h>
typedef void* generic_ptr;

class stack {
public:
   explicit stack(int size = 1000): max_len(size), top(EMPTY)
      { s = new generic_ptr[size]; assert(s != 0);}
   ~stack() { delete [] s; }
   void reset() { top = EMPTY; }
   void push(generic_ptr c) { s[++top] = c; }
   generic_ptr pop() { return s[top--]; }
   generic_ptr top_of() { return s[top]; }
   bool empty()const { return top == EMPTY; }
   bool full()const { return top == max_len - 1; }
private:
   enum  { EMPTY = -1};
   generic_ptr* s;
   int   max_len;
   int   top;
};

