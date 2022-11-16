#include "card.h"
#include "deck.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


/*********************************************************************
** Function: Deck
** Description: the contructor for the deck class
** Parameters: none
** Pre-Conditions: a deck object is created
** Post-Conditions: the deck will be filled with cards and the number of cards will be set
*********************************************************************/
Deck::Deck(){
    numCards = 52;
    fillDeck();
}

/*********************************************************************
** Function: fillDeck
** Description: this fills the card array with cards
** Parameters: none
** Pre-Conditions: a deck object has been created 
** Post-Conditions: the card array will be populated with 52 cards in order
*********************************************************************/
void Deck::fillDeck(){
    int currentCard = 0;
    for (int j = 0; j<13; j++){
        for (int k = 0; k<=3; k++){
            cards[currentCard].setContent(j, k);
            currentCard = currentCard + 1;
        }
    }
}


/*********************************************************************
** Function: shuffle
** Description: shuffles the deck of cards
** Parameters: none
** Pre-Conditions: the deck has been populated
** Post-Conditions: the cards in the card array will be in a random order
*********************************************************************/
void Deck::shuffle(){
    int index;
    int index2;
    Card tempCard;
    srand(time(NULL));

    //shuffle the deck
    for (int i = 0; i<=15000; i++){
        index = rand() % 52;
        index2 = rand() % 52;
        
        tempCard = cards[index];
        cards[index] = cards[index2];
        cards[index2] = tempCard;
    }
}

/*********************************************************************
** Function:print()
** Description: prints the deck in non-human format (for debugging)
** Parameters: none
** Pre-Conditions: the deck has to be initalized
** Post-Conditions: the deck is printed in non human friendly format
*********************************************************************/
void Deck::print(){
    for (int i = 0; i<52; i++){
        cout << "rank: " << cards[i].getRank() << " Suit: " << cards[i].getSuit() << endl;
    }
}

/*********************************************************************
** Function: dealCard
** Description: deals a card from the deck
** Parameters: none
** Pre-Conditions: the deck has been populated
** Post-Conditions: a card from the deck is "removed" from the array and returned
*********************************************************************/
Card Deck::dealCard(){
    numCards = numCards - 1;
    return cards[numCards]; 
}

/*********************************************************************
** Function: getNumCards
** Description: returns the number of cards in the deck
** Parameters: none
** Pre-Conditions: a deck object has been created
** Post-Conditions: the number of cards is returned
*********************************************************************/
int Deck::getNumCards(){
    return numCards;
}