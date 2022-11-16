#ifndef HAND_H
#define HAND_H
#include "card.h"
#include "deck.h"
#include <iostream>
using namespace std;




class Hand{
    private:
        Card* cards;
        int numCards; //number of cards in each hand
    public:
        Hand();
        void printHand();
        int getNumCards();
        Card getCard(int i);
        void deleteCard(int i);
        void addToHand(Card card);

        //big 3
        ~Hand();
        Hand(const Hand& old_obj);
        Hand& operator=(const Hand& old_obj);
};

#endif