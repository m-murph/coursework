#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


class Deck{
    private:
        Card cards[52];
        int numCards; //number of cards left in the deck
    public:
        Deck();
        void print();
        void shuffle();
        Card dealCard();
        void fillDeck();
        void removeCard();
        int getNumCards();   
};

#endif