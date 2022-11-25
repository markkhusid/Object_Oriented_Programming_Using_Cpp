/*********************************************************************

  Filename:  list2.h
  Chapter:   8      Visitation: Iterators and Containers
  Section:   8.6    List and List Iterator
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

#include <iostream.h>
#include <assert.h>

class list {
public:
   struct listelem;  //forward declarations
   class iterator;
   friend iterator;
   list():h(0), t(0) {}//construct the empty list
   list(size_t n_elements,  char c);
   list(const list& x);
   list(iterator b, iterator e);
   ~list() { release(); }
   iterator begin()const { return h; }
   iterator end()const {return t;}
   void push_front(char c);
   void pop_front();
   char& front(){return h -> data;}
   char& back() {return t -> data;}
 	bool empty()const{ return h == 0;}
   void release();
   friend ostream& operator<<(ostream& out, list& x);
private:
   listelem* h, *t;     //head  and tail
   struct listelem      //list cell
   {
      char  data;
      listelem* next, *prev;
      listelem(char c, listelem* n, listelem* p)
            :data(c), next(n), prev(p){}
   	};
   //scoped within class list
   class iterator{
   public:
      iterator(listelem* p = 0):ptr(p){}
      iterator operator++();
      iterator operator--();
      iterator operator++(int);
      iterator operator--(int);
      listelem* operator->(){return ptr;};
      char& operator*(){return ptr -> data;}
      operator listelem*(){return ptr;} //conversion
   private:
      listelem* ptr;//current listelem or 0
   };
};

list::list(size_t n_elements,  char c)
{
   assert(n_elements > 0);
   h = t = 0;
   for(size_t i = 0; i < n_elements; ++i)
      push_front(c);
}

list::list(const list& x)
{
   list::iterator r = x.begin();
   h = t = 0; //needed for empty list
   while (r != 0)
      push_front(*r++);
}

void list::release()
{
  while (h != 0)
     pop_front();
}


ostream& operator<<(ostream& out, list& x)
{
   list::iterator p = x.begin(); //gets x.h

   out << "list = (";
   while (p != 0) {
      out << *p  << ","; //gets a char&
      ++p; //advances iterator using next
   }
   cout << ")\n";
   return out;
}

void list::push_front(char c)
{
   listelem* temp = new listelem(c, h, 0);

   if (h != 0) {    //was a nonempty list
      h -> prev = temp;
      h = temp;
   }
   else             //was an empty list
      h = t = temp;
}


list::iterator iterator::operator++()
{
   assert(ptr != 0);
   ptr = ptr -> next;
   return *this;
}

list::iterator  iterator::operator++(int)
{
   assert(ptr != 0);
   iterator temp = *this;
   ptr = ptr -> next;
   return temp;
}
