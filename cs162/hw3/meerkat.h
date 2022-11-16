//s
#ifndef MEERKAT_H
#define MEERKAT_H
#include <iostream>
#include "animal.h"

class Meerkat : public Animal{
    private:
        int revenue;
        int treatmentCost;
        int foodCost;
    public:
        Meerkat(string t, int a);
        int getRevenue();
        int getTreatmentCost();
        int getFoodCost();
};




#endif