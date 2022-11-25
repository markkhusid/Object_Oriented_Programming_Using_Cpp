/*********************************************************************

  Filename:  ex3.cpp
  Chapter:   10     Inheritance
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//generic binary search trees

#include  "ex3.h"
#include  <string.h>    //older systems use string.h

class s_tree : private gen_tree {
public:
   s_tree() { }
   void  insert(char* d) { gen_tree::insert(d); }
   char*  find(char* d) const
     { return static_cast<char*>(gen_tree::find(d)); }
   void  print() const { gen_tree::print(); }
};


void print(bnode* n)
{
   cout << static_cast<char*>(n -> data) << '\t' ;
   cout << n -> count << '\t';
}


int main()
{
   s_tree   t;
   char    dat[80], *p;

   cout << "\nEnter strings; exit "
        << "with an end-of-file" << endl;
   while ( cin >> dat ) {
      p = new char[strlen(dat) + 1];
      strcpy(p, dat);
      t.insert(p);
   }
   t.print();
   cout << "\n\n" << endl;
}
