//s
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "shape.h"
using namespace std;

class Circle : public Shape{
    private:
        float radius;
    public:
        float area();
        Circle(float r, string n, string c);
        float getRadius();
        void setRadius(float r);

        
};

#endif