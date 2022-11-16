//s
#include <iostream>
#include <cmath>
#include "circle.h"
using namespace std;

Circle::Circle(float r, string n, string c) : Shape(n, c){
    radius = r;
}

float Circle::area(){
    return M_PI*radius*radius;
}

float Circle::getRadius(){
    return radius;
}

void Circle::setRadius(float r){
    radius = r;
}