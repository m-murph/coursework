#ifndef LAVA_H
#define LAVA_H

#include <iostream>
#include "event.h"
using namespace std;

class Lava : public Event{
    public:
        int printPerception();
        int getType();
};

#endif