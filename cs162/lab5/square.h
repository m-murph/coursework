//s
#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include "rectangle.h"
using namespace std;

class Square : public Rectangle{
    public:
        Square(float, string, string);
        float area();
};

#endif