//s
#include <iostream>
#include "rectangle.h"
using namespace std;

Rectangle::Rectangle(float w, float h, string n, string c) : Shape(n, c){
    width = w;
    height = h;
}

float Rectangle::area(){
    return width * height;
}

float Rectangle::getWidth(){
    return width;
}

float Rectangle::getHeight(){
    return height;
}

void Rectangle::setWidth(float w){
    width = w;
}

void Rectangle::setHeight(float h){
    height = h;
}