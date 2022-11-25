/*********************************************************************

  Filename:  string1.cpp
  Chapter:   1      Why Object Oriented Programming in C++?
  Section:   1.3    Encapsulation and Type Extensibility
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//An elementary implementation of type my_string.
//See also dyn_string for dynamic string program
#include <string.h>
#include <iostream.h>

const int  max_len = 255;

class my_string{
public:    //universal access to interface
   void assign(const char* st) 	{ strcpy(s, st); len = strlen(st); }
   int length() const { return len; }
   void print() const
      { cout << s << "\nLength: " << len << endl;}
private:   //restricted access to implementation
   char  s[max_len];
   int   len;
};


//Test of the class my_string.

int main()
{
   my_string one, two;
   char   three[40] = {"My name is Charles Babbage."};

   one.assign("My name is Alan Turing.");
   two.assign(three);
   cout << three;
   cout << "\nLength: " << strlen(three) << endl;
   //print the shorter of one and two
   if (one.length() <= two.length())
      one.print();
   else
      two.print();
}
