/*********************************************************************

  Filename:  ex9.cpp
  Chapter:   3      Functions and Pointers
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

// Print command line arguments rightmost first.


#include  <iostream.h>

int main(int argc, char **argv)
{
   for (--argc; argc >= 0; --argc)
      cout << argv[argc] << endl;
}
