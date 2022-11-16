//s
#ifndef BATS_H
#define BATS_H
#include <iostream>
#include "event.h"
using namespace std;

class Bats : public Event{
    public:
        int printPerception();
        int getType();
};

#endif