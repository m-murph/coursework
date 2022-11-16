//g
#ifndef GAME_H
#define GAME_H
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;

class Game{
    private:
        Deck cards;
        Player players[2];
    public:
        Game();
        void began();
        void startGame();
        void declareWinner();
        Card playersTurn(Card activeCard);
        Card computersTurn(Card activeCard);
        int getUserInput(int low, int high);
        void dealTo(int player, int numCards);
        void printPlayableCards(Card activeCard);
        bool checkCard(Card & tmpCard, Card activeCard);
        void printHandAfterDrawing(Card DrawnCard, Card activeCard);
        void getUserCardInput(Card & tmpCard, Card activeCard, int & play);
        bool computerSearchForCardToPlay(Card & tmpCard, Card activeCard, int & timesDrawn);
        
};

#endif





