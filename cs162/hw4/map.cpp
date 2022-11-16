#include <iostream>
#include <vector>
#include "room.h"
#include "map.h"
#include <stdlib.h>
using namespace std;

/*********************************************************************
** Function: Map
** Description: the map constructor
** Parameters: s: the side length of the square map
** Pre-Conditions: none
** Post-Conditions: a map is created
*********************************************************************/
Map::Map(int s){
    size = s;
    hasGold = false;
    nChimera = false;
    tranq = 3;
    map = vector<vector<Room>>(s, vector<Room>(s));
    for (int i = 0; i<s; i++){
        for (int k = 0; k<s; k++){
            map[i][k].setEvent(new Empty);
        }
    }
    shuffleRooms();
    locateRooms();
    setPlayerRandomPosition(true);
}

/*********************************************************************
** Function: shuffleRooms
** Description: creates the non empty event rooms in random parts of the map
** Parameters: none
** Pre-Conditions: a map is created
** Post-Conditions: the map will be populated with the event rooms
*********************************************************************/
void Map::shuffleRooms(){ 
    vector<int> chosenx;
    vector<int> choseny;
    int x1;
    int y1;
    chosenx.push_back(-1);
    choseny.push_back(-1);
    for (int i = 0; i<6; i++){
        bool finding = true;
        while (finding){
            x1 = rand() % size;
            y1 = rand() % size;
            for (unsigned int j = 0; j<chosenx.size(); j++){
                if(chosenx[j] == x1 && choseny[j] == y1){
                    break;
                }
                else if(j == chosenx.size() - 1){
                    finding = false;
                    chosenx.push_back(x1);
                    choseny.push_back(y1);
                }
            }
        }
        if (i == 0){
            map[x1][y1].setEvent(new Chimera);
        }
        else if(i >= 1 && i <= 2){
            map[x1][y1].setEvent(new Bats);
        }
        else if(i >= 3 && i <= 4){
            map[x1][y1].setEvent(new Lava);
        }
        else{
            map[x1][y1].setEvent(new Gold);
        }
    }
}

/*********************************************************************
** Function: locateRooms
** Description: finds the x and y location of the event rooms
** Parameters: none
** Pre-Conditions: the shuffleRooms function has been called
** Post-Conditions: the x and y coordinates have been populated for each event
*********************************************************************/
void Map::locateRooms(){
    bool foundBats = false;
    bool foundLava = false;
    for (int i = 0; i<size; i++){
        for (int j = 0; j<size; j++){
            if (map[i][j].getEvent()->getType() == 1){
                chiX = i;
                chiY = j;
                chiXi = i;
                chiYi = j;
            }
            else if (map[i][j].getEvent()->getType() == 2 && foundBats == false){
                b1x = i;
                b1y = j;
                foundBats = true;
            }
            else if (map[i][j].getEvent()->getType() == 2 && foundBats == true){
                b2x = i;
                b2y = j;
            }
            else if (map[i][j].getEvent()->getType() == 3 && foundLava == false){
                l1x = i;
                l1y = j;
                foundLava = true;
            }
            else if (map[i][j].getEvent()->getType() == 3 && foundLava == true){
                l2x = i;
                l2y = j;
            }
            else if (map[i][j].getEvent()->getType() == 4){
                gx = i;
                gy = j;
                gxi = i;
                gyi = j;
            }
        }
    }
}

/*********************************************************************
** Function: setPlayerRandomPosition
** Description: puts the player in a random part of the map that does not have an event
** Parameters: initial: true to also change the initial positino of the player (rope), false for just changing player position
** Pre-Conditions: none
** Post-Conditions: the player will end up in a random location on the map
*********************************************************************/
void Map::setPlayerRandomPosition(bool initial){
    int x;
    int y;
    while(true){
        x = rand() % size;
        y = rand() % size;
        if (map[x][y].getEvent()->getType() == 0){
            if (initial){
                pxi = x;
                pyi = y;
            }
            px = x;
            py = y;
            break;
        }
    }
}

/*********************************************************************
** Function: percept
** Description: looks into adjacent rooms and prints their perceptions if applicible
** Parameters: none
** Pre-Conditions: a map exists
** Post-Conditions: perceptions are printed to the output
*********************************************************************/
void Map::percept(){
    if (px > 0){
        map[px-1][py].getEvent()->printPerception();
    }
    if (px < size-1){
        map[px+1][py].getEvent()->printPerception();
    }
    if (py > 0){
        map[px][py-1].getEvent()->printPerception();
    }
    if (py < size-1){
        map[px][py+1].getEvent()->printPerception();
    }
}

/*********************************************************************
** Function: getInput
** Description: the function that gets input for the user each turn
** Parameters: none
** Pre-Conditions: a map has been generated
** Post-Conditions: the player will be moved or a tranquilizer will be fired
*********************************************************************/
void Map::getInput(){
    string dir;
    cout << "Where would you like to move (w, a, s, d)? Or press t to fire the tranquilizer." << endl;
    while (true){
        cin >> dir;
        if (dir == "t" && tranq > 0){
            fireT();
            break;
        }
        else if(tranq == 0 && dir == "t"){
            cout << "You don't have any tranquilizers left, input w a s or d to move" << endl;
        }
        else if (dir == "w" || dir == "a" || dir == "s" || dir == "d"){
            move(dir);
            break;
        }
        else{
            cout << "Try again, please input w a s d or space" << endl;
        }
    }
}

/*********************************************************************
** Function:inputForT
** Description: the function to get input for the direction that the tranquilizer is fired
** Parameters: vx: the "x velocity" of the tranquilizer, really just the direction. vy: the "y velocity" also just really the direction
** Pre-Conditions: the fireT functiuon has been called 
** Post-Conditions: the "velocity" of the tranquilizer is changed to match the direction of fire
*********************************************************************/
void Map::inputForT(int& vx, int& vy){
    string dir;
    cout << "which way would you like to fire the tranquilizer (w, a, s, d)?" << endl;
    while (true){
        cin >> dir;
        if (dir == "w"){
            vy = -1;
            break;
        }
        else if (dir == "s"){
            vy = 1;
            break;
        }
        else if(dir == "a"){
            vx = -1;
            break;
        }
        else if (dir == "d"){
            vx = 1;
            break;
        }
        else{
            cout << "Try again, please input w, a, s, or d" << endl;
        }
    }
}

/*********************************************************************
** Function: fireT
** Description: the logic behind firing a tranquilizer
** Parameters: none
** Pre-Conditions: getInput has been called
** Post-Conditions: the user will have 1 less tranquilizer, and either the chimera will be neutralized, or the chimera will teleport to a random spot
*********************************************************************/
void Map::fireT(){
    tranq--;
    int tx = px;
    int ty = py;
    int vx = 0;
    int vy = 0;
    inputForT(vx, vy);
    for (int i = 0; i<3; i++){
        tx = tx + vx;
        ty = ty + vy;
        if(tx == chiX && ty == chiY){
            cout << "\n\nYou hit the chimera, it has been tranquilized!" << endl;
            nChimera = true;
            map[tx][ty].setEvent(new Empty);
        }
    }
    if (!nChimera){
        cout << "\n\nThe tranquilizer missed, the sound spooked the chimera and it ran to another part of the mine!!" << endl;
        moveChimera();
    }   
}

/*********************************************************************
** Function: move
** Description: moves the player 1 space in a given diraction
** Parameters: dir: a string that describes the direction
** Pre-Conditions: getInput has been called
** Post-Conditions: the player will be moved in the direction, or the user will be infomed that they tried to move into a wall
*********************************************************************/
void Map::move(string dir){
    if (dir == "w" && py > 0){
        py--;
    }
    else if(dir == "s" && py < size-1){
        py++;
    }
    else if(dir == "a" && px > 0){
        px--;
    }
    else if(dir == "d" && px < size-1){
        px++;
    }
    else{
        cout << "\n\nYou ran into a wall." << endl;
    }
}

/*********************************************************************
** Function: moveChimera
** Description: moves the chimera to a random place
** Parameters: none
** Pre-Conditions: assume the map has been populated with events
** Post-Conditions: the chimera will be in a new random place
*********************************************************************/
void Map::moveChimera(){
    int x;
    int y;
    while(true){
        x = rand() % size;
        y = rand() % size;
        if (map[x][y].getEvent()->getType() == 0 && !(x == px && y == py && x == chiX && x == chiY)){
            map[chiX][chiY].setEvent(new Empty);
            map[x][y].setEvent(new Chimera);
            chiX = x;
            chiY = y;
            break;
        }
    }
}

/*********************************************************************
** Function: checkPos
** Description: checks to see if the player has moved into an event square
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: and integer is returned that describes where the player is
*********************************************************************/
int Map::checkPos(){
    //return 1 for death by chimera, 2 for death by lava, 3 for the bats, 4 for finding gold, 0 for winnig, and -1 for nothing 
    if (px == chiX && py == chiY && nChimera == false){
        return 1;
    }
    else if ((px == l1x && py == l1y) || (px == l2x && py == l2y)){
        return 2;
    }
    else if ((px == b1x && py == b1y) || (px == b2x && py == b2y)){
        setPlayerRandomPosition(false);
        return 3;
    }
    else if (px == gx && py == gy){
        hasGold = true;
        gx = -1;
        map[px][py].setEvent(new Empty);
        return 4;
    }
    else if (px == pxi && py == pyi && nChimera == true && hasGold == true){
        return 0;
    }
    else{
        return -1;
    }
}


/*********************************************************************
** Function: resetMap
** Description: resets the movable aspets of the map back to the original positinon
** Parameters: none
** Pre-Conditions: the map has been populated
** Post-Conditions: the map will be reset to its original state
*********************************************************************/
void Map::resetMap(){
    hasGold = false;
    nChimera = false;
    px = pxi;
    py = pyi;

    map[chiX][chiY].setEvent(new Empty);
    chiX = chiXi;
    chiY = chiYi;
    map[chiX][chiY].setEvent(new Chimera);

    gx = gxi;
    gy = gyi;
    map[gx][gy].setEvent(new Gold);
}



/*********************************************************************
** Function: printMap
** Description: prints the mine to output
** Parameters: debug: determins weather to print the debug view or the regular one
** Pre-Conditions: a map has been made 
** Post-Conditions: the map is printed to output either in regular view or debug view
*********************************************************************/
void Map::printMap(bool debug){
    if (debug == false){
        for (int k = 0; k<size; k++){
            for (int i = 0; i<size; i++){
                cout << "+---";
            }
            cout << "+" << endl;
            for (int j = 0; j<3; j++){
                for (int i = 0; i<size+1; i++){
                    if (py == k && px == i && j == 1){
                        cout << "|";
                        cout << " * ";
                    }
                    else{
                        cout << "|";
                        cout << "   ";
                    }
                }
                cout << endl;
            }
        }
        for (int i = 0; i<size; i++){
            cout << "+---";
        }
        cout << "+" << endl;
    }
    else{
        printDebugMap();
    }
    percept();
}

/*********************************************************************
** Function: printDebugMap
** Description: prints the debug view of the map
** Parameters: none
** Pre-Conditions: printMap has been called with true
** Post-Conditions: the debug view has been printed to the output
*********************************************************************/
void Map::printDebugMap(){
    for (int k = 0; k<size; k++){
        for (int i = 0; i<size; i++){
            cout << "+---";
        }
        cout << "+" << endl;
        for (int j = 0; j<3; j++){
            for (int i = 0; i<size+1; i++){
                cout << "|";
                if (i<size && map[i][k].getEvent()->getType() == 1 && j == 0){
                    cout << " c ";
                }
                else if(i<size && map[i][k].getEvent()->getType() == 2 && j == 0){
                    cout << " b ";
                }
                else if(i<size && map[i][k].getEvent()->getType() == 3 && j == 0){
                    cout << " l ";
                }
                else if(i<size && map[i][k].getEvent()->getType() == 4 && j == 0){
                    cout << " g ";
                }
                else if(py == k && px == i && j == 1){
                    cout << " * ";
                }
                else if(pyi == k && pxi == i && j == 0){
                    cout << " r ";
                }
                else{
                    cout << "   ";
                }
            }
            cout << endl;
            }
    }
    for (int i = 0; i<size; i++){
        cout << "+---";
    }
    cout << "+" << endl;   
}

