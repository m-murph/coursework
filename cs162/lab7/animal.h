#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std;


class Animal{
    private:
        string type;
        int age; //in weeks
        bool isBaby;
    protected:
        string name;
    public:
        Animal(string t, string n, int a);
        void increaseAge(int);
        string getType();
        int getAge();
        bool getBaby();
        string getName();


        virtual int getRevenue() = 0;
        virtual int getFoodCost() = 0;
        virtual int getTreatmentCost() = 0;
        virtual ~Animal();
};



















#endif