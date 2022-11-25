/*********************************************************************

  Filename:  ex1.cpp
  Chapter:   3      Functions and Pointers
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//This has only the base code for exercise 1 and not the answer

#include <iostream.h>

bool streq(const char* s1, const char* s2)
{
   while ( *s1 != 0 && *s2 != 0)
      if ( *s1++ != *s2++)
         return false;
   return (*s1 == *s2);
}

char* strcpy(char* s1, const char* s2)
{
   for (int i = 0; s1[i] = s2[i]; ++i)
       ;
   return(s1);
}

int main()
{
   char  c1[30];
   char* s1 = "C++";

   strcpy(c1, "This is new c1 string");
   cout << "\nString c1 is " << c1;
   cout << "\nString s1 is " << s1;
   cout << "\nCompare c1, s1 gives " << streq(c1, s1);
   cout << "\nCompare s1, c1 gives " << streq(s1, c1);
   cout << "\nCompare c1, c1 gives " << streq(c1, c1) << endl;
}
