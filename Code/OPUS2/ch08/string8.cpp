/*********************************************************************

  Filename:  string8.cpp
  Chapter:   8      Visitation: Iterators and Containers
  Section:   8.4    Friendly Classes and Iterators
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Reference counted strings.


#include "string8.h"

void word(string_iterator& it_s, char* w)
{
   while (isspace(it_s.item()) && it_s.successor())
      ;    //find non-whitespace character
   if (!isspace(it_s.item())) {
      *w = it_s.item();      //first character of word
      while (it_s.successor()&& !isspace(it_s.item()))
         *++w = it_s.item();   //successive characters
   }
   *++w = 0;                   //add '\0' terminator
}

int main()
{
   char*   str = "The wheel that squeaks the loudest\n";
   char    next[100] = {""};
   my_string  a(str), b, author("Josh Billings\n");
   string_iterator  it_a(a) ;

   b.assign(a);
   cout << a;
   cout << b;
   cout << author;
   it_a.reset();
   word(it_a, next);
   cout << next;
}
