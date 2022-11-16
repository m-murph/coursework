//s
#ifndef SEAOTTER_H
#define SEAOTTER_H
#include <iostream>
#include "animal.h"

class Seaotter : public Animal{
    private:
        int revenue;
        int treatmentCost;
        int foodCost;
    public:
        Seaotter(string t, int a);
        int getRevenue();
        int getTreatmentCost();
        int getFoodCost();
};





#endif