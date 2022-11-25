/*********************************************************************

  Filename:  gentree1.cpp
  Chapter:   9      Templates, Generic Programming and STL
  Section:   9.5    Parameterized Binary Search Tree
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Template Version of GenTree.

#include  <iostream.h>
#include  <string.h>

//A generic binary sorted tree.
template <class T>  class gen_tree;     //forward decl
template <class T>
class bnode {
private:
   friend class gen_tree<T>;
   bnode<T>*  left;
   bnode<T>*  right;
   T          data;
   int        count;
   bnode(T d, bnode<T>* l, bnode<T>* r) :
         data(d), left(l), right(r), count(1) { }
   void  print() const
      { cout << data << " : " << count << '\t'; }
};

template <class T>
class gen_tree {
public:
   gen_tree() { root = 0; }
   void  insert(T d);
   T  find(T d) const { return (find(root, d)); }
   void  print() const { print(root); }
private:
   bnode<T>*  root;
   T  find(bnode<T>* r, T d) const;
   void  print(bnode<T>* r) const;
};

template <class T>
void gen_tree<T>::insert(T d)
{
   bnode<T>*  temp = root;
   bnode<T>*  old;

   if (root == 0) {
      root = new bnode<T>(d, 0, 0);
      return;
   }
   while (temp != 0) {
      old = temp;
      if (comp(temp -> data, d) == 0) {
         (temp -> count)++;
         return;
      }
      if (comp(temp -> data, d) > 0)
         temp = temp -> left;
      else
         temp = temp -> right;
   }
   if (comp(old -> data, d) > 0)
      old -> left = new bnode<T>(d, 0, 0);
   else
      old -> right = new bnode<T>(d, 0, 0);
}

template <class T>
T gen_tree<T>::find(bnode<T>* r, T d) const
{
   if (r == 0)
      return 0;
   else if (comp(r -> data, d) ==  0)
      return (r -> data);
   else if (comp(r -> data, d) > 0)
      return (find( r -> left, d));
   else
      return (find( r -> right, d));
}

template <class T>
void gen_tree<T>::print(bnode<T> *r) const
{
   if (r != 0) {
      print( r -> left);
      r -> bnode<T>::print();
      print ( r -> right);
   }
}

template <class T>      //general case
int comp(T i, T j)
{
   if (i == j)          //assumes ==  < defined for T
      return 0;
   else
      return ( (i < j) ? -1 : 1 );
}

//specialization for const char*
int comp(const char* i, const char* j){
   return (strcmp(i, j));
}

int main()
{
   char             dat[256];
   gen_tree<char*>  t;
   char*            p;

   while (cin>>dat){
      p = new char[strlen(dat) + 1];
      strcpy(p, dat);
      t.insert(p);
   }
   t.print();
   cout << "EOF" << endl << endl;

   gen_tree<int>  i_tree;

   for (int i = 15; i > -5; --i)
      i_tree.insert(i);
   i_tree.print();
}

