//p
#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "deck.h"
#include "hand.h"
#include <iostream>
using namespace std;

class Player{
    private:
        Hand hand;
        string name;
    public:
        string getName();
        void printHand();
        int getCardsHeld();
        void removeCard(int i);
        void receveCard(Card in);
        void setName(string name);
        Card playCard(int cardNum);
};









































#endif