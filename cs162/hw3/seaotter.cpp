#include "seaotter.h"
#include <iostream>
using namespace std;

/*********************************************************************
** Function: Seaotter
** Description: the constructor 
** Parameters: t: the type of the animal, a the age of the animal
** Pre-Conditions: none
** Post-Conditions: the animal is constructed
*********************************************************************/
Seaotter::Seaotter(string t, int a) : Animal(t, a){
    revenue = 200;
    treatmentCost = 800;
    foodCost = 50;
}

/*********************************************************************
** Function: getRevenue
** Description: returns the amount of revenue the animal makes
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Seaotter::getRevenue(){
    if (getBaby()){
        return revenue*2;
    }
    else{
        return revenue;
    }
}

/*********************************************************************
** Function: getTreatmentCost
** Description: returns the price of treatment for the animal
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Seaotter::getTreatmentCost(){
    if (getBaby()){
        return treatmentCost*2;
    }
    else{
        return treatmentCost;
    }
}

/*********************************************************************
** Function: getFoodCost
** Description: returns the price of food for this animal
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Seaotter::getFoodCost(){
    return foodCost;
}
