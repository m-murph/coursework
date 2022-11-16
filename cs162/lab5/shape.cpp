#include <iostream>
#include "shape.h"
using namespace std;

Shape::Shape(string n, string c){
    name = n;
    color = c;
}

//float Shape::area(){
//    return 0;
//}

string Shape::getName(){
    return name;
}

string Shape::getColor(){
    return color;
}

void Shape::setName(string n){
    name = n;
}

void Shape::setColor(string c){
    color = c;
}

bool operator>(Shape& s1, Shape& s2){
    if (s1.area() > s2.area()){
        return true;
    }
    else{
        return false;
    }

}