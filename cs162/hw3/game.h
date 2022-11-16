#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "zoo.h"
#include "monkey.h"
#include "seaotter.h"
#include "meerkat.h"
#include <limits>
using namespace std;

class Game{
    private:
        int time; //in weeks
        Zoo z1;
    public:
        Game();
        void start();
        void beganCycle();
        int getUserInput(int, int);
        bool buyAnimals();
        void extendedInput(int&, int&, int&, bool&);

        bool ff(int w);

        bool buyAnimalsForTheFirstTime();
};

#endif