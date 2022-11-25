/*********************************************************************

  Filename:  string4.cpp
  Chapter:   1      Why Object Oriented Programming in C++?
  Section:   1.5    Overloading
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Overloading the operator+.

#include<string.h>
#include<iostream.h>
#include <assert.h>

//Overloading the operator+.
class my_string {
public:
   my_string() { len = 0; s = new char[1]; }
   explicit my_string(int n){ s = new char[n + 1]; len = n; }
   void  assign(const char* st);
   int  length() const { return len; }
   void  print() const
      { cout << s << "\nLength: " << len << endl; }
   my_string& operator=(const my_string& a);
   friend my_string& operator+
      (const my_string& a, const my_string& b);
private:
   char* s;
   int   len;
};

//overload +
my_string& operator+
      (const my_string& a, const my_string& b)
{
   my_string* temp = new my_string(a.len + b.len);

   strcpy(temp->s, a.s);
   strcat(temp->s, b.s);
   return *temp;
}

//overloaded assignment
my_string& my_string::operator=(const my_string& str)
{
   if (this != &str) {    //check for assign to self
      delete []s;     //retrieve old string
      len = str.len;
      s = new char[len + 1];
      assert (s != 0);
      strcpy(s, str.s);
   }
   return (*this);
}

void my_string::assign(const char* str)
{
   delete [] s;
   len = strlen(str);
   s = new char[len + 1];
   strcpy(s, str);
}


void print(const char* c)    //file scope print
{
   cout << c << "\nLength: " << strlen(c) << endl;
}

int main()
{
   my_string one, two, both;
   char   three[40] = {"My name is Charles Babbage."};

   one.assign("My name is Alan Turing.");
   two.assign(three);
   print(three);      //file scope print called
                      //Print shorter of one and two
   if (one.length() <= two.length())
      one.print();    //member function print called
   else
      two.print();
   both = one + two;  //plus overloaded as concatenate
   both.print();
}

