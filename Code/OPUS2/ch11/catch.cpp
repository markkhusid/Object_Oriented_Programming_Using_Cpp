/*********************************************************************

  Filename:  catch.cpp
  Chapter:   11     Exceptions
  Section:   9.5    Handlers
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

// See what happens as you "uncomment" the throw statements
#include  <iostream.h>
#include  <stdlib.h>

void foo()
{
   int  i, j;

   i = 14;
   j = 15;
//   throw i;
}

void call_foo()
{
   int  k;

   k  = 12;
   foo();
//   throw ("This is from call_foo");
}

void call_foo2()
{
   double  x = 1.3;
   throw (x);
}

int main()
{
   try {
      call_foo();  //foo exitted with i and j destroyed
      call_foo2();
   }
   catch (char* message)
   {
      cerr << message << endl;
      exit(1);
   }
   catch(int n) { cout << "\ncaught it " << n << endl; }
   catch( ... )      //default action to be taken
   {
      cerr << "THAT'S ALL FOLKS." << endl;
      abort();
   }
}


