//
#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include <iomanip>
#include "animal.h"
#include "monkey.h"
#include "seaotter.h"
#include "meerkat.h"

#include <stdlib.h>

using namespace std;

class Zoo{
    private:
        Animal** animals;
        int numKats;
        int numOtters;
        int numMonkeys;
        int totalAnimals;
        bool boom;
        int adultMonkies, adoMonkies, babyMonkies, adultSea, adoSea, babySea, adultKat, adoKat, babyKat;
        int money;
        bool bankrupt;
        int spentOnTreatment;
        int spentOnFood;
    public:
        //big 3
        Zoo(const Zoo& o);
        void operator=(const Zoo& o);
        ~Zoo();

        Zoo();
        void addAnimal(Animal* in);
        void removeAnimal(int index);
        int getBalance();
        void subtractBalance(unsigned int i);
        void feed();
        bool isBankrupt();
        bool hasFunds(int i);
        void printStatus();
        void tallyAnimals();
        void triggerRandomEvent();
        void sickness();
        void reproduction();
        void calcRevenue();
        void printMoneySummary(int, int, int);
        void ageAnimals();
};









#endif