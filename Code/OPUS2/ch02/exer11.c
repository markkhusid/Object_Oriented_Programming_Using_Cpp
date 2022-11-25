/*********************************************************************

  Filename:  exer11.c
  Chapter:   2      The Native Types and Statements
  Section:   Exercis
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

/* Count blanks, digits, letters,
   newlines,and others.
*/
#include  <stdio.h>

int main()
{
   int  blank_cnt = 0, c, digit_cnt = 0,
        letter_cnt = 0, nl_cnt = 0, other_cnt = 0;

   while ((c = getchar()) != EOF)
      if (c == ' ')
         ++blank_cnt;
      else if (c >= '0' && c <= '9')
         ++digit_cnt;
      else if (c >= 'a' && c <= 'z' || c >= 'A' &&
               c <= 'Z')
         ++letter_cnt;
      else if (c == '\n')
         ++nl_cnt;
      else
         ++other_cnt;

   printf("%10s%10s%10s%10s%10s%10s\n\n",
      "blanks", "digits", "letters", "lines",
      "others", "total");
   printf("%10d%10d%10d%10d%10d%10d\n\n",
     blank_cnt, digit_cnt, letter_cnt, nl_cnt,
     other_cnt, blank_cnt + digit_cnt + letter_cnt +
     nl_cnt + other_cnt);
}

