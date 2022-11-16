#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
#include "room.h"
#include <stdlib.h>
using namespace std;

class Map{
    private:
        int pxi;
        int pyi;
        int px;
        int py;
        int b1x;
        int b1y;
        int b2x;
        int b2y;
        int l1x;
        int l1y;
        int l2x;
        int l2y;
        int chiX;
        int chiY;
        int gx;
        int gy;
        int size;
        bool hasGold;
        bool nChimera;
        int tranq;
        
        int gxi;
        int gyi;
        int chiXi;
        int chiYi;
        vector<vector<Room>> map;
    public:
        Map(int s);
        void printMap(bool d);
        void shuffleRooms();
        void setPlayerRandomPosition(bool initial);
        void printDebugMap();
        void getInput();
        void move(string dir);
        void fireT();
        void percept();
        int checkPos();
        void moveChimera();
        void locateRooms();
        void inputForT(int&, int&);
        void resetMap();
};


#endif