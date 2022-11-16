#ifndef EMPTY_H
#define EMPTY_H

#include <iostream>
#include "event.h"
using namespace std;

class Empty : public Event{
    public:
        int printPerception();
        int getType();
};

#endif