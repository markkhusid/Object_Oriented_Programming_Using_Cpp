/*********************************************************************

  Filename:  memcopy.cpp
  Chapter:   8      Visitation: Iterators and Containers
  Section:   8.5    Genericity with void
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <stddef.h>      //define size_t
#include <iostream.h>

void* memcpy(void* to, const void* from,
             size_t n_bytes)
{
   const char* f= reinterpret_cast<const char*>(from);
   char *t = reinterpret_cast<char*>(to);

   for (int i = 0; i < n_bytes; ++i)
       t[i] = f[i];
   return to;
}

int main()
{
   char v[4];
   int  w  = 0x00424344;

   memcpy(v, &w, 4);       //polymorphic interface
   cout << w << " == " << v;
}
