/*********************************************************************

  Filename:  poker.cpp
  Chapter:   4      Implementing ADTs in the Base Language
  Section:   4.6    The aggregate Type Struct - An Example: Flushing
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//A poker calculation on flushing

#include  <iostream.h>
#include  <stdlib.h>      //for random number generation
#include  <time.h>        //for seed random number generation

enum suit {clubs, diamonds, hearts, spades};
typedef int pips;

struct card {
   suit s;
   pips p;
};

struct deck {
   card d[52];
};

pips assign_pips(int n)
{
   return (n % 13 + 1);
}

suit assign_suit(int n)
{
   return (static_cast<suit>(n / 13));
}
void assign(int n, card& c)
{
   c.s = assign_suit(n);
   c.p = assign_pips(n);
}
pips get_pip(card c)
{
   return c.p;
}

suit get_suit(card c)
{
   return c.s;
}

void print_card(card c)
{
  cout << c.p;
  switch(c.s) {
    case clubs:
       cout << "C ";
       break;
    case diamonds:
       cout << "D ";
       break;
    case hearts:
       cout << "H ";
       break;
    case spades:
       cout << "S ";
  }
}

void print_deck(deck& dk)
{
   for (int i = 0; i < 52; ++i)
      print_card(dk.d[i]);
}
void  shuffle(deck& dk)
{
   card t;

   for (int i = 0; i < 52; ++i) {
      int k = ((rand() % (52- i)));
      t = dk.d[i];
      dk.d[i] = dk.d[k];
      dk.d[k] = t; //swap two cards
   }
}

void deal(int n, int pos, card* hand, deck& dk)
{
   for (int i = pos; i < pos + n; ++i)
      hand[i - pos] = dk.d[i];
}

void  init_deck(deck& dk)
{
   for (int i = 0; i < 52; ++i)
      assign(i, dk.d[i]);
}

int main()
{
   card one_hand[9];       //max hand is 9 cards
   deck dk;
   int  i, j, k, fcnt = 0, sval[4];
   int  ndeal, nc, nhand;
   do {
      cout << "\nEnter no. cards in a hand (5-9):";
      cin  >> nc;
   } while (nc < 5 || nc > 9);
   nhand = 52 / nc;
   cout << "\nEnter no. of hands to deal: ";
   cin  >> ndeal;
   srand(time(NULL));      //seed rand() from time()
   init_deck(dk);
   print_deck(dk);
   for (k = 0; k < ndeal; k += nhand) {
      if ((nhand + k) > ndeal)
         nhand = ndeal - k;
      shuffle(dk);
      for (i = 0; i < nc * nhand; i += nc) {
         for (j = 0; j < 4; ++j)  //zero suit counts
            sval[j] = 0;
      deal(nc, i, one_hand, dk);  //deal next hand
      for (j = 0; j < nc; ++j)
         sval[one_hand[j].s]++; //increment suit count
      for (j = 0; j < 4; ++j)
         if (sval[j] >= 5)        //5 or more is flush
             fcnt++;
      }
   }
   cout << "\n\nIn " << ndeal << " ";
   cout << nc << "-card hands there were ";
   cout << fcnt << " flushes\n   ";
}
