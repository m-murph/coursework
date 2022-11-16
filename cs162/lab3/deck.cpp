#include <iostream>
#include "deck.h"
#include <stdlib.h>
using namespace std;

Deck::Deck(){
    numCards = 52;
    fillDeck();
}

void Deck::fillDeck(){
    int currentCard = 0;
    for (int j = 0; j<13; j++){
        for (int k = 0; k<=3; k++){
            cards[currentCard].setContent(j, k);
            currentCard = currentCard + 1;
        }
    }
}

void Deck::shuffle(){
    int index;
    int index2;
    Card tempCard;
    srand(time(NULL));

    //generate 2 random indexes then swap the cards at the random indexes.
    for (int i = 0; i<=15000; i++){
        index = rand() % 52;
        index2 = rand() % 52;
        
        tempCard = cards[index];
        cards[index] = cards[index2];
        cards[index2] = tempCard;
    }
}

void Deck::print(){
    for (int i = 0; i<numCards; i++){
        if (cards[i].getRank() == 0){
            cout << "Ace of "; 
        }
        else if (cards[i].getRank() == 10){
            cout << "Jack of ";
        }
        else if (cards[i].getRank() == 11){
            cout << "Queen of ";
        }
        else if (cards[i].getRank() == 12){
            cout << "King of ";
        }
        else{
            cout << cards[i].getRank() + 1 << " of ";
        }
        printSuit(i);
    }
}

void Deck::printSuit(int i){
    if (cards[i].getSuit() == 0){
        cout << "Diamonds" << endl;
    }
    else if (cards[i].getSuit() == 1){
        cout << "Clubs" << endl;
    }
    else if (cards[i].getSuit() == 2){
        cout << "Hearts" << endl;
    }
    else if (cards[i].getSuit() == 3){
        cout << "Spades" << endl;
    }
}

