/*********************************************************************

  Filename:  add3.cpp
  Chapter:   3      Functions and Pointers
  Section:   3.4    Function Prototypes
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//Add three ints -illustrating function prototypes.

#include  <iostream.h>

int  add3(int, int, int);
double  average(int);
int main()
{
   int  score_1, score_2, score_3, sum;

   cout << "\nEnter 3 scores: ";
   cin >> score_1 >> score_2 >> score_3;
   sum = add3(score_1, score_2, score_3);
   cout << "\nTheir sum is " << sum;
   cout << "\nTheir average is " << average(sum);
   sum = add3(1.5 * score_1, score_2, 0.5 * score_3);
   cout << "\nThe weighted sum is " << sum << ".";
   cout << "\nTheir weighted average is "
        << average(sum) << "." << endl;
}

int add3(int a, int b, int c)
{
   return (a + b + c);
}

double average(int s)
{
   return (s / 3.0);
}
