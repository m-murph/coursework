#include "card.h"
#include "deck.h"
#include "hand.h"
#include "game.h"
#include "player.h"
#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;



/*********************************************************************
** Function: Game()
** Description: the constructor for the game class
** Parameters: none
** Pre-Conditions: a game object must be created for this to run
** Post-Conditions: the deck is shuffled, and "The Computer" is named.
*********************************************************************/
Game::Game(){
    cards.shuffle();
    players[0].setName("The Computer");
    srand(time(NULL));
}

/*********************************************************************
** Function: began()
** Description: this prompts the user for inpit, deals cards, then starts the game
** Parameters: none
** Pre-Conditions: a game object has been created
** Post-Conditions: name string for the play will be filled
*********************************************************************/
void Game::began(){
    cout << "Welcome to crazy 8s, please enter your name. " << endl;
    string name;// = "tmp name";
    cin >> name;
    players[1].setName(name);
    dealTo(0, 8);
    dealTo(1, 8);
    startGame();
}

/*********************************************************************
** Function:dealTo
** Description: deals cards to the targeted player
** Parameters: int player: the index of the player in the player array. int numCards: the number of cards you want to deal 
** Pre-Conditions: none
** Post-Conditions: the specfied player will have the specfied amount of cards
*********************************************************************/
void Game::dealTo(int player, int numCards){
    for (int i = 0; i<numCards; i++){
        players[player].receveCard(cards.dealCard());
    }
}

/*********************************************************************
** Function: startGame()
** Description: contains the main loop that switched between the player and the computer
** Parameters: none
** Pre-Conditions: all the data in cards and players has been properly dealt with
** Post-Conditions: the declareWinner function will be called
*********************************************************************/
void Game::startGame(){
    cout << endl;
    //deal the first face up card
    Card activeCard = cards.dealCard();
    cout << endl;

    bool running = true;
    while (running){
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        //start players turn
        if (running == true){
            activeCard = playersTurn(activeCard);
        }
        if (activeCard.getRank() == -1){
            declareWinner();
            running = false;
        }
        
        //start computers turn
        if (running == true){
            cout << "-------------------------------------------------------------------------------------------------------\n" << endl;
            activeCard = computersTurn(activeCard);
        }
        if (activeCard.getRank() == -1 && running == true){
            declareWinner();
            running = false;
        }
        cout << endl;
    }
}

/*********************************************************************
** Function: computersTurn
** Description: the function that starts the computers turn
** Parameters: activeCard: this is the "face up" card.
** Pre-Conditions: startGame has been called and the player has not won
** Post-Conditions: the function returns the new "face up" card (note a card that is returned with -1 for rank and suit means the computers hand or the deck is empty)
*********************************************************************/
Card Game::computersTurn(Card activeCard){
    Card tmpCard;
    bool findingCard = true;
    int timesDrawn = 0;
    cout << players[0].getName() << "'s turn:\n" << endl;

    while (findingCard){
        findingCard = computerSearchForCardToPlay(tmpCard, activeCard, timesDrawn);
        if (players[0].getCardsHeld() == 0){
            cout << players[0].getName() << " played the ";
            tmpCard.print();
            cout << players[0].getName() << "'s hand is empty!" << endl;
            tmpCard.setContent(-1, -1);
            return tmpCard;
        }
    }

    if (tmpCard.getRank() == -1){

        cout << players[0].getName() << " Drew " << timesDrawn << " time(s) from the deck" << endl;
        cout << "The deck is empty!" << endl;
        return tmpCard;
    }

    cout << players[0].getName() << " Drew " << timesDrawn << " time(s) from the deck then played the "; 
    tmpCard.print();
    cout << "There are " << players[0].getCardsHeld() << " card(s) in its hand and " << cards.getNumCards() << " card(s) left in the deck" << endl;
    return tmpCard;
}

/*********************************************************************
** Function: computerSearchForCardToPlay
** Description: this is where the computer finds a playable card
** Parameters: tmpCard: this is a temporary card that holds the values of a playable card. activeCard: this is the face up card. timesDrawn: this is the amount of times the computer had to draw from the deck
** Pre-Conditions: computersTurn has been called
** Post-Conditions: the functino returns false if it found a playable card or true if it did not
*********************************************************************/
bool Game::computerSearchForCardToPlay(Card & tmpCard, Card activeCard, int & timesDrawn){
    //this searches for a playable card that is not an 8, then searches for an 8, if it finds niether it draws until the deck is empty or it finds a card
    for (int i = 0; i<players[0].getCardsHeld(); i++){
        if (((players[0].playCard(i).getRank() == activeCard.getRank() || players[0].playCard(i).getSuit() == activeCard.getSuit()) && players[0].playCard(i).getRank() != 7)){
            tmpCard = players[0].playCard(i);
            players[0].removeCard(i);
            return false;
        }
    }
    for (int i = 0; i<players[0].getCardsHeld(); i++){
        if(players[0].playCard(i).getRank() == 7){
            tmpCard = players[0].playCard(i);
            players[0].removeCard(i);
            int newSuit = rand() % 4;
            tmpCard.setContent(7, newSuit);
            cout << "\n" << players[0].getName() << " played a crazy 8! The card was chosen to be an ";
            tmpCard.print();
            return false;
        }
    }
    //computer draws from deck
    players[0].receveCard(cards.dealCard());
    timesDrawn = timesDrawn + 1;
    if (cards.getNumCards() == 0){
        tmpCard.setContent(-1, -1);
        return false;
    }
    return true;
}

/*********************************************************************
** Function: playersTurn
** Description: this function starts the players turn
** Parameters: activeCard: the "face up" card
** Pre-Conditions: startGame has been called
** Post-Conditions: the new "face up" card is returned
*********************************************************************/
Card Game::playersTurn(Card activeCard){
    cout << players[1].getName() << "'s hand is:\n" << endl;
    players[1].printHand();
    cout << "\nThe face up Card is ";
    activeCard.print();
    cout << "Input the card you want to play indicated by the numbers on the left of the cards. Input -1 to draw from the deck if you wish." << endl;

    printPlayableCards(activeCard);

    int play = 0;
    Card tmpCard;
    tmpCard.setContent(0, 0);

    getUserCardInput(tmpCard, activeCard, play);
    if (tmpCard.getRank() == -1){
        return tmpCard;
    }
    players[1].removeCard(play);
    cout << "You played the ";
    tmpCard.print();

    if (players[1].getCardsHeld() == 0){
        cout << players[1].getName() << "'s hand is empty!" << endl;
        tmpCard.setContent(-1, -1);
    }
    return tmpCard;
}

/*********************************************************************
** Function: printHandAfterDrawing
** Description: this prints the players new hand after they draw a card
** Parameters: drawnCard: the card they drew from the deck
** Pre-Conditions: function getUserCardInput has been called
** Post-Conditions: the players new hand is printed to the standard output
*********************************************************************/
void Game::printHandAfterDrawing(Card drawnCard, Card activeCard){     
    cout << players[1].getName() << " drew a card, its the ";
    drawnCard.print();
    cout << "There are " << cards.getNumCards() << " Cards(s) left in the deck. \n\n" << players[1].getName() << "'s new hand is " << endl;
    players[1].printHand();
    cout << "\nThe face up card is ";
    activeCard.print();
    cout << "Input the card you want to play indicated by the numbers on the left of the cards. If no cards are playable, input -1 to draw a card from the deck." << endl;
}

/*********************************************************************
** Function: printPlayableCards
** Description: this function prints all the id's of the valid cards in the players hand, and will tell the player they need to draw if they have no valid cards
** Parameters: activeCard: the "face up" card 
** Pre-Conditions: getUserCardInput has been called
** Post-Conditions: either the valid card id's have been printed or the no playable cards message has been printed
*********************************************************************/
void Game::printPlayableCards(Card activeCard){
    bool playableCards = false;
    bool ranPrompt = false;
    for (int i = 0; i<players[1].getCardsHeld(); i++){
        if (players[1].playCard(i).getRank() == activeCard.getRank() || players[1].playCard(i).getSuit() == activeCard.getSuit() || players[1].playCard(i).getRank() == 7){
            if (!ranPrompt){
                cout << "Valid cards are: ";
                ranPrompt = true;
            }
            cout << "(" << i << ")";
            playableCards = true;
        } 
    }
    if (!playableCards){
        cout << "No cards are playable! You must draw from the deck (input -1)." << endl;
    }
}

/*********************************************************************
** Function: checkCard
** Description: this function checks to see if the player has inputed a valid card and handles the playing of a crazy 8
** Parameters: tmpCard: a refrence to the temporary card that will become the new "face up" card. activeCard: the current "face up" card
** Pre-Conditions: getUserCardInput has been called
** Post-Conditions: true is retuend if a valid card has been played, false if not.
*********************************************************************/
bool Game::checkCard(Card & tmpCard, Card activeCard){
    if (tmpCard.getRank() == 7){
        int newSuit;
        cout << "You played a crazy 8! what would you like the new suit to be? \n(0) diamonds\n(1) clubs\n(2) hearts\n(3) spades" << endl;
        newSuit = getUserInput(0, 4);
        tmpCard.setContent(7, newSuit);
        return true;
    }
    else if (tmpCard.getSuit() == activeCard.getSuit() || tmpCard.getRank() == activeCard.getRank()){
        return true;
    }
    else{
        cout << "Error, please input a valid card. " << endl;
        return false;
    }
}

/*********************************************************************
** Function: getUserCardInput
** Description: This function gets the card input from the player
** Parameters: tmpCard: the temporary card that will become the new "face up" card. activeCard: the current "face up" card. play: the card id the player wants to play.
** Pre-Conditions: playersTurn has been called
** Post-Conditions: the functino will set tmpCard to the played card (or -1 -1) and play to the play the user made.
*********************************************************************/
void Game::getUserCardInput(Card & tmpCard, Card activeCard, int & play){
    bool goodCardTT = false;
    while (!goodCardTT){
        play = getUserInput(-1, players[1].getCardsHeld());
        cout << endl;
        while (play == -1){
            Card drawnCard = cards.dealCard();
            if (cards.getNumCards() == 0){
                cout << "The deck is empty!" << endl;
                tmpCard.setContent(-1, -1);
                goodCardTT = true;
                break;
            }
            players[1].receveCard(drawnCard);
            printHandAfterDrawing(drawnCard, activeCard);
            printPlayableCards(activeCard);
            play = getUserInput(-1, players[1].getCardsHeld());
        }
        if (tmpCard.getRank() != -1){
            tmpCard = players[1].playCard(play);
            goodCardTT = checkCard(tmpCard, activeCard);
        }  
    }
}

/*********************************************************************
** Function: declareWinner
** Description: this function declares the winner, or if it is a tie, and other info about the games state when the game ends
** Parameters: none
** Pre-Conditions: a players hand or the deck has 0 cards in it
** Post-Conditions: the games ends and the winner will be printed along with some other info.
*********************************************************************/
void Game::declareWinner(){
    cout << endl;
    if (players[0].getCardsHeld() == 0 || players[0].getCardsHeld() < players[1].getCardsHeld()){
        cout << players[0].getName() << " is the winner! " << endl;
        if (players[0].getCardsHeld() != 0){
            cout << players[0].getName() << " had " << players[0].getCardsHeld() << " Card(s) left in their hand while " << players[1].getName() << " had " << players[1].getCardsHeld() << " cards in their hand." << endl;
        }
    }
    else if (players[1].getCardsHeld() == 0 || players[1].getCardsHeld() < players[0].getCardsHeld()){
        cout << players[1].getName() << " is the winner! " << endl;
        if (players[1].getCardsHeld() != 0){
            cout << players[1].getName() << " had " << players[1].getCardsHeld() << " Card(s) left in their hand while " << players[0].getName() << " had " << players[0].getCardsHeld() << " cards in its hand." << endl;
        }
    }
    else{
        cout << "The game ended in a tie between " << players[0].getName() << " and " << players[1].getName() << "!" << endl;
        cout << "There were " << players[0].getCardsHeld() << " card(s) left in their hands." << endl;
    }
}

/*********************************************************************
** Function: getUserInput
** Description: gets input from the user and makes sure it is in the form of an integer in the specified range
** Parameters: int low: the low bound for the input (inclusive). int high: the high bound for the input (exclusive)
** Pre-Conditions: none
** Post-Conditions: an integer in the specfied input will be returned
*********************************************************************/
int Game::getUserInput(int low, int high){
    int input;
    bool exit;
    cin >> input;
    exit = cin.fail();
    while(true){
        if (exit){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Error, please enter the correct input type in the correct range. " << endl;
            cin >> input;
            exit = cin.fail();
        }
        if(!exit){
            if ((low <= input && input < high)){
                break;
            }
            exit = true;
        }
    }
    return input;
}