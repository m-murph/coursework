#include "card.h"
#include "deck.h"
#include "hand.h"
#include <iostream>
using namespace std;



/*********************************************************************
** Function: the constructor for the hand class
** Description: initializes a hand with 0 cards set to null
** Parameters: none 
** Pre-Conditions: a hand object is created
** Post-Conditions: there will be 0 null cards in the hand
*********************************************************************/
Hand::Hand(){
    cards = NULL;
    numCards = 0;
}


/*********************************************************************
** Function: the copy constructor for the hand class
** Description: allows you to make copies of the hand class
** Parameters: old_obj = the hand you want to make a copy of
** Pre-Conditions: a new hand is created with the right syntax to invoke this
** Post-Conditions: a copied hand will be made
*********************************************************************/
Hand::Hand(const Hand& old_obj){
    numCards = old_obj.numCards;

    if (numCards > 0){
        cards = new Card[numCards];
        for (int i = 0; i<numCards; i++){
            cards[i] = old_obj.cards[i];
        }
    }
    else{
        cards = NULL;
    }
}

/*********************************************************************
** Function: operator=
** Description: the aassignment operator overload for the hand class
** Parameters: old_object: the old hand that will be copied
** Pre-Conditions: a hand exists
** Post-Conditions: the old hand will be deleted and a new one will be made
*********************************************************************/
Hand& Hand::operator=(const Hand& old_obj){
    delete[] cards;
    numCards = old_obj.numCards;

    if (numCards > 0){
        cards = new Card[numCards];
        for (int i = 0; i<numCards; i++){
            cards[i] = old_obj.cards[i];
        }
    }
    else{
        cards = NULL;
    }
    return *this;
}

/*********************************************************************
** Function: addToHand
** Description: adds a card to the end of the players hand
** Parameters: card: the card you want to add
** Pre-Conditions: a hand has been initialized
** Post-Conditions: the hand will have a new card
*********************************************************************/
void Hand::addToHand(Card card){
    Card* newArray = new Card[numCards+1];
    newArray[numCards] = card;
    for (int i = 0; i<numCards; i++){
        newArray[i] = cards[i]; 
    }

    delete[] cards;
    cards = newArray;
    numCards = numCards + 1;
}

/*********************************************************************
** Function: deleteCard
** Description: removes a card from the hand at the specifed index
** Parameters: cardNum: the index where you want the card to be removed
** Pre-Conditions: the hand has card(s) in it
** Post-Conditions: the card will be removed from the card array
*********************************************************************/
void Hand::deleteCard(int cardNum){
    Card* newArray = new Card[numCards-1];
    for (int i = 0; i<cardNum; i++){
        newArray[i] = cards[i];
    }
    for (int i = cardNum + 1; i<numCards; i++){
        newArray[i-1] = cards[i];
    }

    delete[] cards;
    cards = newArray;
    numCards = numCards - 1;
}

/*********************************************************************
** Function: getNumCards
** Description: returns the number of cards int the hand
** Parameters: none
** Pre-Conditions: the hand has been initilized
** Post-Conditions: an int will be returned
*********************************************************************/
int Hand::getNumCards(){
    return numCards;
}


/*********************************************************************
** Function: getCard
** Description: returns a card at the specfied index without deleting from the hand
** Parameters: i: the index of ther card you want retuend
** Pre-Conditions: the hand has cards in it
** Post-Conditions: the requested card is returne
*********************************************************************/
Card Hand::getCard(int i){
    return cards[i];
}

/*********************************************************************
** Function: printHand
** Description: prints the hand in human friendly format with the card id before the card
** Parameters: none
** Pre-Conditions: the hand with card ids are printed to the standard output
** Post-Conditions: the hand has cards in it
*********************************************************************/
void Hand::printHand(){
    for (int i = 0; i<numCards; i++){
        cout << "(" << i << ") ";
        cards[i].print();
    }
}

/*********************************************************************
** Function: destructor for the hand class
** Description: deletes the dynamacally allocated array of cards for the hand
** Parameters: none
** Pre-Conditions: a hand object is created
** Post-Conditions: the card array is deleted
*********************************************************************/
Hand::~Hand(){
    delete[] cards;
}