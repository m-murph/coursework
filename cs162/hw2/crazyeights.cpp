/*********************************************************************  
 * ** Program Filename: crazyeights.cpp 
 * ** Author: Michael Murphy
 * ** Date: 7/16/2022  
 * ** Description: contains the main function for a program where the user playes crazy 8s aganst the computer 
 * ** Input: the useres name, the cards the user wants to play, and of they want to play another game
 * ** Output: the game os printed to the output 
 * *********************************************************************/

#include "game.h"
#include <iostream>
using namespace std;
/*********************************************************************
** Function: main
** Description: the main function that starts the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the game will start and end
*********************************************************************/
int main(){
    bool playing = true;
    while (playing){
        Game myGame;
        myGame.began();
        cout << "Game ended." << endl;
        int d;
        cout << "Would you like to play another game? input 1 for yes and 0 for no." << endl;
        d = myGame.getUserInput(0, 2);
        if (d==0){
            playing = false;
        }
    }
    return 0;
}






