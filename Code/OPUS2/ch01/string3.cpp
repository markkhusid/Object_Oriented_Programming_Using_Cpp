/*********************************************************************

  Filename:  string3.cpp
  Chapter:   1      Why Object Oriented Programming in C++?
  Section:   1.5    Overloading
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Overloading  print.

#include<string.h>
#include<iostream.h>
#include <assert.h>

const int  max_len = 255;

//Implementing dynamically allocated my_strings.

class my_string {
public:
   //constructor
   explicit my_string(int n) { s = new char[n + 1]; len = n; }
   my_string() { len = 0; s = new char[1]; }
   my_string(const char* p);
   ~my_string() { delete []s; }      //destructor
   void  assign(const char* st);
   int  length() const { return len; }
   void  print() const
      { cout << s << "\nLength: " << len << endl; }
   void  print(int n) const
      { for (int i = 0; i < n; ++i)
           cout << s << endl; }
private:
   char*  s;
   int    len;
};

my_string::my_string(const char* p)
{
   len = strlen(p);
   s = new char[len + 1];
   strcpy(s, p);
}

void my_string::assign(const char* str)
{
   delete [] s;
   len = strlen(str);
   s = new char[len + 1];
   strcpy(s, str);
}


int main()
{
	my_string  a, b(40), c("I came by bus.");
	char*      str = "I came on foot.";
	my_string  d(str);

	a.assign("This is the default length");
	b.assign("This is a string whose max length is 40");
	cout << "\na is: ";
	a.print();
   b.print(2);  //printed twice
   c.print(-1); //not printed at all
}
