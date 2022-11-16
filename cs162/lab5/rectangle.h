//
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "shape.h"
using namespace std;

class Rectangle : public Shape{
    private:
        float height;
        float width;
    public:
        float area();
        Rectangle(float w, float h, string n, string c);
        float getWidth();
        float getHeight();
        void setWidth(float w);
        void setHeight(float h);
};

#endif
