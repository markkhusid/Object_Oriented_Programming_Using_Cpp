/*********************************************************************

  Filename:  stack_t2.cpp
  Chapter:   10     Inheritance
  Section:   10.6   Templates and Inheritance
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Stack implementation with constructor

#include <iostream.h>
#include "stack_t2.h"

class safe_char_stack : public stack<char> {
public:
   // test push and pop
   void  push(char c)
     { assert (!full()); stack<char>::push(c); }
   char  pop()
     {assert (!empty()); return (stack<char>::pop());}
};

//Reversing a series of char* represented strings
void reverse(char* str[], int n)
{
   stack<char*>  stk(n);

   for (int i = 0; i < n; ++i)
      stk.push(str[i]);
   for (int i = 0; i < n; ++i)
      str[i] = stk.pop();
}


int main()
{
   stack<char>     stk_ch;         // 1000 char stack
   stack<char*>    stk_str(200);   // 200 char* stack

   char* str[3] = {"Reverse", "these", "three"};

   stk_ch.push('A');
   stk_ch.push('B');
   print_and_pop(stk_ch, "char");
   stk_str.push("ABCD");
   stk_str.push("EFGH");
   print_and_pop(stk_str, "char*");
   reverse(str, 2);
   cout << "Reversed 2" << endl << str[0] << str[1]
        << str[2] << endl;
}
