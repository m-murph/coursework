//
#ifndef MONKEY_H
#define MONKEY_H
#include <iostream>
#include "animal.h"
using namespace std;

class Monkey : public Animal{
    private:
        int revenue;
        int treatmentCost;
        int foodCost;
    public:
        Monkey(string t, int a);
        int getRevenue();
        int getTreatmentCost();
        int getFoodCost();
        int getCost();

};





#endif