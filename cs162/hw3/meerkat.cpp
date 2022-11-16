#include "meerkat.h"
#include <iostream>
using namespace std;

/*********************************************************************
** Function: Meerkat
** Description: the constructor 
** Parameters: t: the type of the animal, a the age of the animal
** Pre-Conditions: none
** Post-Conditions: the animal is constructed
*********************************************************************/
Meerkat::Meerkat(string t, int a) : Animal(t, a){
    revenue = 25;
    treatmentCost = 100;
    foodCost = 25;
}

/*********************************************************************
** Function: getRevenue
** Description: returns the amount of revenue the animal makes
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
int Meerkat::getRevenue(){
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
int Meerkat::getTreatmentCost(){
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
int Meerkat::getFoodCost(){
    return foodCost;
}