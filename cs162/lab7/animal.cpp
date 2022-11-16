#include <iostream>
#include "animal.h"
using namespace std;

/*********************************************************************
** Function: Animal
** Description: the constructor for the animal class
** Parameters: t: the type of animal. a: the age of the animal
** Pre-Conditions: none
** Post-Conditions: an animal is constructed
*********************************************************************/
Animal::Animal(string t, string n, int a){
    type = t;
    age = a;
    name = n;
}

/*********************************************************************
** Function: increaseAge
** Description: indexes the age of the animal by a given amount
** Parameters: i: the amount you want to index
** Pre-Conditions: none
** Post-Conditions: the age will be indexed
*********************************************************************/
void Animal::increaseAge(int i){
    age = age + i;
}

/*********************************************************************
** Function: getType 
** Description: gets the type of animal
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns a string with the animal type
*********************************************************************/
string Animal::getType(){
    return type;
}

/*********************************************************************
** Function: getAge
** Description: gets the age of the animal
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: an integer is returned
*********************************************************************/
int Animal::getAge(){
    return age;
}

/*********************************************************************
** Function: getBaby
** Description: sees if the animal is a baby or not
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: a boolean is returned
*********************************************************************/
bool Animal::getBaby(){
    if (age < 7){
        isBaby = true;
    }
    else{
        isBaby = false;
    }
    return isBaby;
}

string Animal::getName(){
    return name;
}

/*********************************************************************
** Function: ~Animal
** Description: this exists to stop compile warnings
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
Animal::~Animal(){}