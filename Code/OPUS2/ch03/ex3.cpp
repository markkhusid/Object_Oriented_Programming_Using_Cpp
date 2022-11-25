/*********************************************************************

  Filename:  ex3.cpp
  Chapter:   3      Functions and Pointers
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//This file is not the solution to the problem, but contains the
//code in the initial problem statement

//string function implementations

#include <iostream.h>

// iterative string length
size_t strlen(const char *s)
{
   size_t  len = 0;

   while (*s != '\0') {      // string terminator
      ++len;                 // increment length
      ++s;                   // advance pointer
   }
   return len;
}

int main()
{
   char* s = "C++";

   cout << "\nString s is " << s << " and its length is " << strlen(s);
}
