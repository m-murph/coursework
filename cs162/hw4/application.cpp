#include <iostream>
#include "map.h"
#include "room.h"
#include <time.h>
#include <sstream>
using namespace std;
/******************************************************
** Program: application.cpp
** Author: Michael Murphy
** Date: 8-11-2022
** Description: YOU HAVE TO KILL THE CHIMERA, well in this case, shoot it with a tranquilizer.
** Input: w a s d and t
** Output: a mine with rooms in the form of a grid and diferent percepts
******************************************************/

void runGame(Map&, bool, int);
void printMessages(int);

/*********************************************************************
** Function: main
** Description: The main function that contains the loop for playing the game
** Parameters: argc, argument count, argv, argument values
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int main(int argc, char* argv[]){
    if (argc != 3){
        cout << "Your command arguments must be an integer that is at least 4 and then 'true' or 'false'" << endl;
        return 1;
    }
    int s;
    stringstream ss;
    ss << (argv[1]);
    s = stoi(ss.str());
    if (s < 4){
        cout << "Your map size must be at least 4" << endl;
        return 1;
    }
    cout << "A chimera is loose in the local gold mine, the miners have hired you to tranquilize it so it can be removed." << endl;
    cout << "Your payment for this task is a sack of gold that they have left somewhere in the mine, don't forget it." << endl;
    cout << "Be warned, there are some hazards down there so try not to die." << endl;
    bool debug = false;
    if (*(argv[2]) == 't'){
        debug = true;
    }
    srand(time(NULL));
    Map m(s);
    runGame(m, debug, s);
    return 0;
}

/*********************************************************************
** Function: runGame
** Description: the function that contians the loop for playing the game
** Parameters: m: a refrence to a map, debug; a boolean for debug mode
** Pre-Conditions: main has been called
** Post-Conditions: the game ends
*********************************************************************/
void runGame(Map & m, bool debug, int s){
    m.printMap(debug);
    bool playing = true;
    while (playing){
        m.getInput();
        int event = m.checkPos();
        m.printMap(debug);
        printMessages(event);
        if (event == 1 || event == 2 || event == 0){
            string in;
            cout << "Would you like to play again with the same map (y/n)? Or input q to quit." << endl;
            cin >> in;
            if (in == "y"){
                playing = true;
                m.resetMap();
                m.printMap(debug);
            }
            else if (in == "n"){
                playing = false;
                Map m2(s);
                runGame(m2, debug, s);
            }
            else{
                playing = false;
            }
        }
    }
}

/*********************************************************************
** Function: printMessages
** Description: prints various messages that the player uses durring the game
** Parameters: event: corosponds to the message being printed
** Pre-Conditions: runGame has been called
** Post-Conditions: a message is printed or nothing is printed
*********************************************************************/
void printMessages(int event){
    if(event == 1){
        cout << "You have died to the chimera, game over." << endl;
    }
    else if (event == 2){
        cout << "You fell in lava and died, game over." << endl;
    }
    else if (event == 3){
        cout << "You have entered a room full of bats, they have carried you to a random place in the mine." << endl;
    }
    else if(event == 4){
        cout << "You found the gold!" << endl;
    }
    else if (event == 0){
        cout << "You have escaped and won!" << endl;
    }
}