/*********************************************************************

  Filename:  poker.cpp
  Chapter:   5      Data Hiding and Member Functions
  Section:   5.5    An Example: Revisiting Flushing
  Compiler:  Borland C++     Version 5.0       Summer 1996
  Object Oriented Programming Using C++, Edition 2   By Ira Pohl

*********************************************************************/

//A poker calculation on flushing
#include  <iostream.h>
#include  <stdlib.h>    //for random number generation
#include  <time.h>      //for random number seed

enum suit { clubs, diamonds, hearts, spades };

class pips {
public:
    void  assign(int n) { p = n % 13 + 1; }
    int   getpip() { return p; }
    void  print() {cout <<  p;}
private:
    int  p;
};


class card {
public:
    suit  s;
    pips  p;
    void  assign(int n)
       { cd = n; s = suit(n/13); p.assign(n); }
    void  pr_card();
private:
    int  cd;      //a cd is from 0 to 51
};

void card::pr_card()
{
  p.print();
  switch(s) {
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

class deck {
public:
    void  init_deck();
    void  shuffle();
    void  deal(int, int, card*);
    void  pr_deck();
private:
    card  d[52];
 };

void deck::init_deck()
{
    for (int i = 0; i < 52; ++i)
       d[i].assign(i);
}

void  deck::shuffle()
{
    for (int i = 0; i < 52; ++i) {
       int  k = i + ((rand() % (52 - i)));
       card  t = d[i];               //swap cards
       d[i] = d[k];
       d[k] = t;
    }
}

void deck::deal(int n, int pos, card* hand)
{
    for (int i = pos; i < pos + n; ++i)
       hand[i - pos] = d[i];
}


void deck::pr_deck()
{
  for (int i = 0; i < 52; ++i)
      d[i].pr_card();
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
   dk.init_deck();
   dk.pr_deck();
   for (k = 0; k < ndeal; k += nhand) {
      if ((nhand + k) > ndeal)
         nhand = ndeal - k;
      dk.shuffle();
      for (i = 0; i < nc * nhand; i += nc) {
         for (j = 0; j < 4; ++j)  //zero suit counts
            sval[j] = 0;
      dk.deal(nc, i, one_hand);  //deal next hand
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
