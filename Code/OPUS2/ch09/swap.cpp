/*********************************************************************

  Filename:  swap.cpp
  Chapter:   9      Templates, Generic Programming and STL
  Section:   9.2    Signature Overloading
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//  Title: swap

#include <iostream.h>
#include <complex.h>
#include <string.h>

//generic swap
template <class T>
void swap(T& x, T& y)
{
   T  temp;
   temp = x;
   x = y;
   y = temp;
}

void swap(char* s1, char* s2)
{
   int  max_len;

   max_len = (strlen(s1) >= strlen(s2)) ?
              strlen(s1) : strlen(s2);
   char* temp = new char[max_len + 1];

   strcpy(temp, s1);
   strcpy(s1, s2);
   strcpy(s2, temp);
   delete []temp;
}

int main()
{
   int      i= 0, j=1;
   char     ch1='A', ch2='B';
   complex  c1 = 1.0, c2 = 2.0;
   char*    str1 = "ABCD";
   char*    str2 = "EFGHIJK";

   cout << "\nints:     " << i     << '\t' << j;
   cout << "\nchars:    " << ch1   << '\t' << ch2;
   cout << "\ncomplex:  " << c1    << '\t' << c2;
   cout << "\nstrings:  " << str1  << '\t' << str2;

   swap(i, j);            //i j int -  okay
   swap(c1, c2);          //c1, c2 complex -okay
   swap(str1, str2);      //str1, str2 strings
   swap(ch1, ch2);        //chars - okay

   cout << "\nints:     " << i     << '\t' << j;
   cout << "\nchars:    " << ch1   << '\t' << ch2;
   cout << "\ncomplex:  " << c1    << '\t' << c2;
   cout << "\nstrings:  " << str1  << '\t' << str2;
}
