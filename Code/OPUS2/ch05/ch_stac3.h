/*********************************************************************

  Filename:  ch_stac3.h
  Chapter:   5      Data Hiding and Member Functions
  Section:   5.2    Access: private and public
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//A simple implementation of type ch_stack.

struct ch_stack {
 public:
    void  reset() { top = EMPTY; }
    void  push(char c) { top++; s[top] = c; }
    char  pop() { return s[top--]; }
    char  top_of()  { return s[top]; }
    bool  empty()  { return (top == EMPTY);}
    bool  full()  { return (top == FULL); }
 private:
    enum {max_len = 100, EMPTY = -1, FULL = max_len-1};
    char  s[max_len];
    int   top;
 };


