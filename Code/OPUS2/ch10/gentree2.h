/*********************************************************************

  Filename:  gentree2.h
  Chapter:   10     Inheritance
  Section:   10.3   Code Reuse: A Binary Tree Class
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//generic binary search trees
#include  <iostream.h>
#include  <string.h>

typedef void*  p_gen;     //generic pointer type
int  comp(p_gen a, p_gen b);

class bnode {
private:
   friend  class gen_tree;
   bnode*  left;
   bnode*  right;
   p_gen   data;
   int     count;
   bnode(p_gen d, bnode* l, bnode* r) :
        data(d), left(l), right(r), count(1) {}
   friend void  print(bnode* n);
};

class gen_tree {
public:
   gen_tree() { root = 0; }
   void  insert(p_gen d);
   p_gen  find(p_gen d) const
      { return (find(root, d)); }
   void  print() const { print(root); }
protected:
   bnode*  root;
   p_gen  find(bnode* r, p_gen d) const;
   void  print(bnode* r) const;
};


void gen_tree::insert(p_gen d)
{
   bnode*  temp = root;
   bnode*  old;

   if (root == 0) {
      root = new bnode(d, 0, 0);
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
      old -> left = new bnode(d, 0, 0);
   else
      old -> right = new bnode(d, 0, 0);
}


p_gen gen_tree::find(bnode* r, p_gen d) const
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

void gen_tree::print(bnode* r) const
{
   if (r != 0) {
      print (r -> left);
      ::print(r);
      print (r -> right);
   }
}

int comp(p_gen i, p_gen j)
{
   return (strcmp(static_cast<char*>(i),
                  static_cast<char*>(j)) );
}




