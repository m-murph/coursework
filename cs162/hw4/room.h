//s
#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "event.h"
#include "chimera.h"
#include "bats.h"
#include "lava.h"
#include "gold.h"
#include "empty.h"
using namespace std;



class Room{
    private:
        Event* events;
    public:
        Room();
        void setEvent(Event* pe);
        Event* getEvent();
        ~Room();
};


#endif