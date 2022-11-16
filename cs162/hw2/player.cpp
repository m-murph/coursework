#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include <iostream>
using namespace std;





/*********************************************************************
** Function:setName
** Description: sets the players name
** Parameters: inputName: the string of the players name
** Pre-Conditions: a player object is created
** Post-Conditions: the players name will be set
*********************************************************************/
void Player::setName(string inputName){
    name = inputName;
}

/*********************************************************************
** Function:getName
** Description: gets the players name
** Parameters: none
** Pre-Conditions: setName has to be called
** Post-Conditions: a string with the name is returned
*********************************************************************/
string Player::getName(){
    return name;
}

/*********************************************************************
** Function: receveCard
** Description: adds a card to the players hand
** Parameters: in: the card that the player is adding to their hand
** Pre-Conditions: a player object has been created
** Post-Conditions: a card is added to the players hand
*********************************************************************/
void Player::receveCard(Card in){
    hand.addToHand(in);
}

/*********************************************************************
** Function:printHand()
** Description: prints the players hand in human friendly format
** Parameters: none 
** Pre-Conditions: the players hand has cards in it
** Post-Conditions: the hand is printed to the standard output
*********************************************************************/
void Player::printHand(){
    hand.printHand();
}

/*********************************************************************
** Function: playCard
** Description: gets the players card at the requested index
** Parameters: cardNum: the index of the requested card
** Pre-Conditions: the playres hand has cards in it
** Post-Conditions: a card is returned
*********************************************************************/
Card Player::playCard(int cardNum){
    return hand.getCard(cardNum);

}

/*********************************************************************
** Function:removeCard
** Description:removes a card from the players hand at a specfied index
** Parameters: i: the specfied index of the card you want to remove 
** Pre-Conditions:the players hand has cards in it
** Post-Conditions: the players hand will have 1 less card
*********************************************************************/
void Player::removeCard(int i){
    hand.deleteCard(i);
}

/*********************************************************************
** Function: getCardsHeld
** Description: returns the amount of cards the player has in their hand 
** Parameters: none
** Pre-Conditions: a player object has been initialized
** Post-Conditions: and integer is returned
*********************************************************************/
int Player::getCardsHeld(){
    return hand.getNumCards();
}