/*********************************************************************

  Filename:  str_func.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.17   The char* Convention
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//string function implementations

#include <iostream.h>

//string function implementations

size_t strlen(const char* s)
{
   int i;
   for (i = 0; s[i]; ++i)
      ;
   return i;
}

int strcmp(const char* s1, const char* s2)
{
   int i;
   for(i=0; s1[i] && s2[i] && (s1[i]==s2[i]); ++i)
      ;
   return (s1[i] - s2[i]);
}

char* strcpy(char* s1, const char* s2)
{
   int i;
   for (i = 0; s1[i] = s2[i]; ++i)
      ;
   return s1;
}


main()
{
   char c1[30], c2[30];

   char*  s = "c++"; // s[0] = 'c', s[1] = '+',
                    //s[2] = '+', s[3] = '0';
   cout << "\nString s is " << s << " and its length is " << strlen(s);
   strcpy(c1, "This is new c1 string");
   cout << "\nString c1 is " << c1;
   strcpy(c2, c1);
   cout << "\nString c2 is " << c2;
   cout << "\nCompare c1, c2 gives " << strcmp(c1, c2);
   cout << "\nCompare c1, s  gives " << strcmp(c1, s);
   cout << "\nCompare s, c1  gives " << strcmp(s, c1) << endl;
}
