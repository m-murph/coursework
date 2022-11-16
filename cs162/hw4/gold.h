#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include "event.h"
using namespace std;

class Gold : public Event{
    public:
        int printPerception();
        int getType();
};

#endif