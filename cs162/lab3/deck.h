#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <iostream>
using namespace std;


class Deck{
private:
    Card cards[52];
    int numCards; //number of cards left in the deck 
public:
    Deck();
    void fillDeck();
    void shuffle();
    void print();
    void printSuit(int i);
    
};




#endif
