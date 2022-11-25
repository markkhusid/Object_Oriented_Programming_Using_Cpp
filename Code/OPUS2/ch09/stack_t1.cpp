/*********************************************************************

  Filename:  stack_t1.cpp
  Chapter:   9      Templates, Generic Programming and STL
  Section:   9.1    Template Class Stack
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Stack implementation with constructor

#include <iostream.h>
#include <assert.h>
#include <complex.h>

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


//Initializing stack of complex numbers from an array
void init(const complex c[], stack<complex>& stk, const int n)
{
   for (int i = 0; i < n; ++i)
      stk.push(c[i]);
}

template <class T1>
void print_and_pop(T1& a, char* comment)
{
   cout << "Printing " << comment << endl;
   while (!a.empty())
      cout << a.pop() << '\t';
   cout << endl;
}

//Reversing a series of char* represented strings
void reverse(char* str[], int n)
{
   stack<char*>  stk(n);

   for (int i = 0; i < n; ++i)
      stk.push(str[i]);
   for (int i = 0; i < n; ++i)
      str[i] = stk.pop();
}

main()
{
   stack<char>     stk_ch;         // 1000 char stack
   stack<char*>    stk_str(200);   // 200 char* stack
   stack<int>      stk_int(20);    // 20 int stack
   stack<complex>  stk_cmplx(5);   // 5 complex

   char* str[3] = {"Reverse", "these", "three"};
   complex cm[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

   stk_ch.push('A');
   stk_ch.push('B');
   print_and_pop(stk_ch, "char");
   stk_str.push("ABCD");
   stk_str.push("EFGH");
   print_and_pop(stk_str, "char*");
   stk_int.push(1);
   stk_int.push(2);
   print_and_pop(stk_int, "int");
   reverse(str, 2);
   cout << "Reversed 2" << endl << str[0] << str[1]
        << str[2] << endl;
   init(cm, stk_cmplx, 5);
   print_and_pop(stk_cmplx, "complex");
 }
