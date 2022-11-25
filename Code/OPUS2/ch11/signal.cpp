/*********************************************************************

  Filename:  signal.cpp
  Chapter:   11     Exceptions
  Section:   11.2   Using signal.h
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Interrupts handled using signal.h.
#include <signal.h>
#include <time.h>
#include <iostream.h>
#include <stdlib.h>

void cntrl_c_handler(int sig);

inline double clk_psec()
{
   return static_cast<double>(clock())/CLOCKS_PER_SEC;
}

int main()
{
   int i = 0, j;

   cout << "COUNT TO J MILLION, Enter j: ";
   cin >> j;
   j *= 1000000;
   signal(SIGINT, cntrl_c_handler);
   cout << clk_psec() << " start time\n";
   while (1) {
      ++i;
         if (i > j) {
            cout << clk_psec() << " end loop\n";
            cout << " HIT " << j/1000000
              << "  MILLION" << endl;
         raise(SIGINT);
         cout << "\nEnter j: ";
         cin >> j;
         j *= 1000000;
         i = 0;
         cout << clk_psec() << " start loop\n";
      }
   }
}

void cntrl_c_handler(int sig)
{
   char  c;

   cout << "INTERRUPT";
   cout << "\ntype y to continue: ";
   cin >> c;
   if (c == 'y')
       signal(SIGINT, cntrl_c_handler);
   else
       exit(0);
}
