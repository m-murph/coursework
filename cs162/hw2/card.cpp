#include <iostream>
#include "card.h"
using namespace std;
/*********************************************************************
** Function: setContent
** Description: sets the rank and suit of the card
** Parameters: r: the cards rank. s: the cards suit
** Pre-Conditions: a card object has been created
** Post-Conditions: the card will have a rank and suit
*********************************************************************/
void Card::setContent(int r, int s){
    rank = r;
    suit = s;
}

/*********************************************************************
** Function: getRank
** Description: returns the rank of a card
** Parameters: none
** Pre-Conditions: a card object has been created
** Post-Conditions: the rank is returned
*********************************************************************/
int Card::getRank(){
    return rank;
}

/*********************************************************************
** Function: getSuit
** Description: returns the suit of a card
** Parameters: none
** Pre-Conditions: a card object has been created
** Post-Conditions: the suit is returned
*********************************************************************/
int Card::getSuit(){
    return suit;
}

/*********************************************************************
** Function:print
** Description: prints the card
** Parameters: none
** Pre-Conditions: a card object has been created
** Post-Conditions: the card is printed to the standard output in human friendly format
*********************************************************************/
void Card::print(){
    if (rank == 0){
        cout << "Ace of "; 
    }
    else if (rank == 10){
        cout << "Jack of ";
    }
    else if (rank == 11){
        cout << "Queen of ";
    }
    else if (rank == 12){
        cout << "King of ";
    }
    else{
        cout << rank + 1 << " of ";
    }
    printSuit();
}

/*********************************************************************
** Function: printSuit
** Description: prints the suit of the card
** Parameters: none
** Pre-Conditions: print has been called
** Post-Conditions: the suit is printed in a human friendly format
*********************************************************************/
void Card::printSuit(){
    if (suit == 0){
        cout << "Diamonds" << endl;
    }
    else if (suit == 1){
        cout << "Clubs" << endl;
    }
    else if (suit == 2){
        cout << "Hearts" << endl;
    }
    else if (suit == 3){
        cout << "Spades" << endl;
    }
}