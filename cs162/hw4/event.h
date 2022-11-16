#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

class Event{
    public:
        virtual int printPerception() = 0;
        virtual int getType() = 0;
        virtual ~Event();
};

#endif