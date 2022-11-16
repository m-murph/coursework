//s
#ifndef CHIMERA_H   
#define CHIMERA_H
#include <iostream>
#include "event.h"
using namespace std;

class Chimera : public Event{
    public:
        int printPerception();
        int getType();
};

#endif
