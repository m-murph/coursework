#include <iostream>
#include "square.h"
using namespace std;

Square::Square(float sideL, string n, string c) : Rectangle(sideL, sideL, n, c){
}

float Square::area(){
    return getWidth()*getWidth();
}