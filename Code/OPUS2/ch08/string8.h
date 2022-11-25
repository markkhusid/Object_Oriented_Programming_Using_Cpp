/*********************************************************************

  Filename:  string8.h
  Chapter:   8      Visitation: Iterators and Containers
  Section:   8.4    Friendly Classes and Iterators
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Reference counted strings.

#include <string.h>
#include <iostream.h>
#include <ctype.h>

class str_obj {
private:
   friend class my_string;
   friend class string_iterator;
   friend ostream&
      operator<<(ostream& out, const my_string& str);
   int  len, ref_cnt;
   char* s;
   str_obj():len(0), ref_cnt(1) { s = new char[1];}
   str_obj(int n):len(n), ref_cnt(1)
      { s = new char[n + 1]; }
   str_obj(const char* p):ref_cnt(1)
      { len = strlen(p); s = new char[len + 1];
        strcpy(s, p); }
   ~str_obj() { delete [] s; }
};


class my_string {
public:
   my_string() { st = new str_obj; }
   my_string(int n) { st = new str_obj(n); }
   my_string(const char* p) { st = new str_obj(p); }
   my_string(const my_string& str)
      { st = str.st; st -> ref_cnt++; }
   ~my_string();
   void assign(const my_string& str);
   void print() const { cout << st -> s ; }
   my_string& operator=(my_string& str)
       { assign(str); return str; }
   friend class string_iterator;
   friend ostream&
      operator<<(ostream& out, const my_string& str);
private:
   str_obj* st;
};


//A friend function of class string.
//This is a typical method for overloading << "put to".
//Since ostream_var <<  type_var  is the required syntax,
//a member function of class string is not possible.
ostream& operator<<(ostream& out,const my_string& str)
{
   out << str.st -> s;
   return out;
}



void my_string::assign(const my_string& str)
{
   if (str.st -> s != st -> s) {
      if ( --st -> ref_cnt == 0)
	    delete st;
      st = str.st;
      st -> ref_cnt++;
   }
}

my_string:: ~my_string()
{
   if (--st -> ref_cnt == 0)
     delete st;
}

class string_iterator {
public:
   string_iterator(my_string& s)
            :cur_ind(0),ptr_s(&s){}
   bool successor();
   char& item()
      { return ((ptr_s -> st -> s)[cur_ind]); }
   void reset(int n = 0) { cur_ind = n; }
   int position() { return cur_ind; }
private:
   my_string* ptr_s;
   int cur_ind;
};


bool string_iterator::successor()
{
   if (cur_ind >= ptr_s -> st -> len - 1)
      return false;
   else {
      ++cur_ind;
      return true;
   }
}

