/*********************************************************************

  Filename:  tstack.cpp
  Chapter:   1      Why Object Oriented Programming in C++?
  Section:   1.6    Templates and Generic Programming
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>

//template stack implementation


//template stack implementation
template <class TYPE>
class stack {
public:
   explicit stack(int size = 1000) : max_len(size)
      { s = new TYPE[size]; top = EMPTY; }
   ~stack() { delete []s; }
   void  reset() { top = EMPTY; }
   void  push(TYPE c) { s[++top] = c; }
   TYPE  pop() { return s[top--]; }
   TYPE  top_of() { return s[top]; }
   bool  empty() { return (top == EMPTY); }
   bool  full() {return (top == max_len-1);}
private:
   enum   {EMPTY = -1};
   TYPE*  s;
   int    max_len;
   int    top;
};

//Reversing a series of char* represented strings
void reverse(char* str[], int n)
{
   stack<char*>  stk(n);      //this stack holds char*

   for (int i = 0; i < n; ++i)
      stk.push(str[i]);
   for (int i = 0; i < n; ++i)
      str[i] = stk.pop();
}

int main()
{
   stack<char>  typea(100);    //size only
   stack<char>  typeb;          //no size
   char reverseline[200];
   char a [30] = {"My name is Laura Pohl!\n"};
   char b [40] = {"My name is Debra Dolsberry!\n"};
   stack <char*> str_stk;
   stack<int>  int_stk;

	int  i = 0;

   typea.reset();
   while (a[i])
      if (!typea.full())
         typea.push(a[i++]);

   i = 0;
   while (!typea.empty())
      reverseline[i++] = typea.pop();
   reverseline[i] = '\0';
   cout << reverseline;

   i = 0;
   while (b[i])
      if (!typeb.full())
         typeb.push(b[i++]);

   i = 0;
   while (!typeb.empty())
      reverseline[i++] = typeb.pop();
   reverseline[i] = '\0';
   cout << reverseline;
   i = 0;

   int_stk.push(9);
   cout << "\nint stack is " << int_stk.pop() << endl;

   str_stk.push("A string");
   while (!str_stk.empty())
      cout << str_stk.pop();
}
