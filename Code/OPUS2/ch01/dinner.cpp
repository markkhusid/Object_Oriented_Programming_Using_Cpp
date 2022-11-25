/*********************************************************************

  Filename:  dinner.cpp
  Chapter:   1      Why Object Oriented Programming in C++?
  Section:   1.2    An Example C++ Program
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Hello world in C++

//Hello world in C++
#include <iostream.h>  //IO library
#include <string>    //string type
using namespace std; //standard library's namespace

inline void pr_message(string s = "Hello world!")
{    cout << s << endl;}

int main()
{
   pr_message();
   pr_message("Laura Pohl");
   pr_message("It is dinner time.");
}
