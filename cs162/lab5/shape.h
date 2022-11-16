//s
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

class Shape{
    private:
        string name;
        string color;
    public:
        Shape(string n, string c);
        virtual float area() = 0;
        string getName();
        string getColor();
        void setName(string n);
        void setColor(string c); 
        friend bool operator>(Shape& s1, Shape& s2);
};

#endif