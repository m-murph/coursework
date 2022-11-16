#include "zoo.h"
#include <iostream>
#include <iomanip>
#include "animal.h"
#include "monkey.h"
#include "seaotter.h"
#include "meerkat.h"

#include <stdlib.h>

using namespace std;

/*********************************************************************
** Function: Zoo
** Description: the zoo constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the values in zoo will be initlized
*********************************************************************/
Zoo::Zoo(){
    money = 100000;
    animals = NULL;
    numKats = 0;
    numOtters = 0;
    numMonkeys = 0;
    totalAnimals = 0;
    spentOnFood = 0;
    spentOnTreatment = 0;
    adultMonkies = 0, adoMonkies = 0, babyMonkies = 0, adultSea = 0, adoSea = 0, babySea = 0, adultKat = 0, adoKat = 0, babyKat = 0;
    bankrupt = false; 
    boom = false;
    srand(time(NULL));
}

/*********************************************************************
** Function:Zoo
** Description: the copy constructor
** Parameters: o: the old zoo being copied
** Pre-Conditions: none
** Post-Conditions: a new zoo is created
*********************************************************************/
Zoo::Zoo(const Zoo& o){
    money = o.money;
    numKats= o.numKats, numOtters = o.numOtters, numMonkeys = o.numMonkeys;
    totalAnimals = o.totalAnimals;
    spentOnFood = o.spentOnFood;
    spentOnTreatment = o.spentOnTreatment;
    adultMonkies = o.adultMonkies, adoMonkies = o.adoMonkies, babyMonkies = o.babyMonkies, adultSea = o.adultSea, adoSea = o.adoSea, babySea = o.babySea, adultKat = o.adultKat, adoKat = o.adoKat, babyKat = o.babyKat;
    bankrupt = o.bankrupt;
    boom = o.boom;
    srand(time(NULL));
    animals = new Animal*[totalAnimals];
    for (int i = 0; i<totalAnimals; i++){
        if (o.animals[i]->getType() == "monkey"){
            Animal* m1 = new Monkey("", 0);
            *m1 = *(o.animals[i]);
            animals[i] = m1;
        }
        else if (o.animals[i]->getType() == "seaotter"){
            Animal* m1 = new Seaotter("", 0);
            *m1 = *(o.animals[i]);
            animals[i] = m1;
        }
        else{
            Animal* m1 = new Meerkat("", 0);
            *m1 = *(o.animals[i]);
            animals[i] = m1;
        }  
    }
}

/*********************************************************************
** Function: operator=
** Description: the assignment operator overload
** Parameters: o: the old zoo being copied
** Pre-Conditions: none
** Post-Conditions: a zoo is copied
*********************************************************************/
void Zoo::operator=(const Zoo& o){
    for (int i = 0; i<totalAnimals; i++){
        delete animals[i];
    }
    delete[] animals;
    money = o.money;
    numKats= o.numKats, numOtters = o.numOtters, numMonkeys = o.numMonkeys;
    totalAnimals = o.totalAnimals;
    spentOnFood = o.spentOnFood;
    spentOnTreatment = o.spentOnTreatment;
    adultMonkies = o.adultMonkies, adoMonkies = o.adoMonkies, babyMonkies = o.babyMonkies, adultSea = o.adultSea, adoSea = o.adoSea, babySea = o.babySea, adultKat = o.adultKat, adoKat = o.adoKat, babyKat = o.babyKat;
    bankrupt = o.bankrupt;
    boom = o.boom;

    animals = new Animal*[totalAnimals];
    for (int i = 0; i<totalAnimals; i++){
        if (o.animals[i]->getType() == "monkey"){
            Animal* m1 = new Monkey("", 0);
            *m1 = *(o.animals[i]);
            animals[i] = m1;
        }
        else if (o.animals[i]->getType() == "seaotter"){
            Animal* m1 = new Seaotter("", 0);
            *m1 = *(o.animals[i]);
            animals[i] = m1;
        }
        else{
            Animal* m1 = new Meerkat("", 0);
            *m1 = *(o.animals[i]);
            animals[i] = m1;
        }  
    }
}

/*********************************************************************
** Function:~Zoo
** Description: the destructor
** Parameters: none
** Pre-Conditions: a zoo exists and then goes out of scope 
** Post-Conditions: the memory allocated for the animal array is deleted
*********************************************************************/
Zoo::~Zoo(){
    for (int i = 0; i<totalAnimals; i++){
        delete animals[i];
    }
    delete[] animals; 
}

/*********************************************************************
** Function: ageAnimals 
** Description: increases the age of all animals in the zoo by 1 week
** Parameters: none
** Pre-Conditions: the animals array is populated
** Post-Conditions: the animals will be 1 week older
*********************************************************************/
void Zoo::ageAnimals(){
    for (int i = 0; i<totalAnimals; i++){
        animals[i]->increaseAge(1);
    }
}

/*********************************************************************
** Function: addAnimal
** Description: adds an animal to the animals array
** Parameters: in: a pointer to an animal
** Pre-Conditions: none
** Post-Conditions: an animal pointer is now in the array
*********************************************************************/
void Zoo::addAnimal(Animal* in){ 
    Animal** tmpArray = new Animal*[totalAnimals + 1];
    tmpArray[totalAnimals] = in;
    for (int i = 0; i<totalAnimals; i++){
        tmpArray[i] = animals[i];
    }

    delete[] animals; 

    animals = tmpArray;
    totalAnimals = totalAnimals + 1;

    if (in->getType() == "monkey"){
        numMonkeys ++;
    }
    else if (in->getType() == "sea otter"){
        numOtters ++;
    }
    else{
        numKats ++;
    }
    tallyAnimals();
}

/*********************************************************************
** Function: removeAnimal
** Description: removes an animal from the animal pointer array
** Parameters: index: the index in the array that you want to be removed
** Pre-Conditions: the array has at least 1 animal in it
** Post-Conditions: there will be one less animal in the animal array
*********************************************************************/
void Zoo::removeAnimal(int index){
    if (animals != NULL){
        if (animals[index]->getType() == "monkey"){
            numMonkeys --;
        }
        else if(animals[index]->getType() == "sea otter"){
            numOtters --;
        }
        else{
            numKats --;
        }

        Animal** tmpArray = new Animal*[totalAnimals - 1];
        for (int i = 0; i<index; i++){
            tmpArray[i] = animals[i];
        }
        for (int i = index + 1; i<totalAnimals; i++){
            tmpArray[i-1] = animals[i];
        }

        delete animals[index];
        delete[] animals;
        animals = tmpArray;
        totalAnimals = totalAnimals - 1;
    }
    tallyAnimals();
}

/*********************************************************************
** Function: getBalance
** Description: returns the balance of the zoo
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the balance
*********************************************************************/
int Zoo::getBalance(){
    return money;
}

/*********************************************************************
** Function: feed
** Description: feeds all the animals in the zoo and calculates the cost
** Parameters: none
** Pre-Conditions: animals are in the animal pointer array
** Post-Conditions: the price of food will be calculated and recorded
*********************************************************************/
void Zoo::feed(){
    spentOnFood = 0;
    for (int i = 0; i<totalAnimals; i++){
        spentOnFood = spentOnFood + animals[i]->getFoodCost();
    } 
}

/*********************************************************************
** Function: sickness
** Description: runs when the random event is an animal getting sick
** Parameters: none
** Pre-Conditions: there are animals in the animal pointer array
** Post-Conditions: and animal will recover and the price of treatment will be recorded, or the animal will be removed
*********************************************************************/
void Zoo::sickness(){
    spentOnTreatment = 0;
    int random = rand() % totalAnimals;

    cout << "Oh no! A " << animals[random]->getType() << " got sick, its treatment will cost $" << animals[random]->getTreatmentCost() << "." << endl;

    if (animals[random]->getTreatmentCost() > money){
       removeAnimal(random);
       cout << "Unfortunatly you could not afford the treatment and the animal was donated to a zoo that could. " << endl;
       //i aint killin nothin
    }
    else{
        spentOnTreatment = animals[random]->getTreatmentCost();
        cout << "The animal was treated successfully" << endl;
    }
}

/*********************************************************************
** Function: isBankrupt
** Description: sees if the zoo is bankrupt
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns true if bankrupt and false if not. Also prints out bankrupt message
*********************************************************************/
bool Zoo::isBankrupt(){
    if (money <= 500 && totalAnimals <= 0){
        bankrupt = true;
        cout << "You have gone bankrupt, you have no more animals and cannot afford to buy any. " << endl;
    }
    else if (money <= 0){
        cout << "You have ran out of money and gone bankrupt " << endl;
        bankrupt = true;
    }
    return bankrupt;
}

/*********************************************************************
** Function: hasFunds
** Description: checks to see if the zoo has funds for a purchace
** Parameters: i: the amout of money
** Pre-Conditions: none
** Post-Conditions: true if the zoo can afforad it, false if not
*********************************************************************/
bool Zoo::hasFunds(int i){
    if (i > money){
        return false;
    }
    return true;
}

/*********************************************************************
** Function: subtractBalance
** Description: subtracts an amount from the zoos balance
** Parameters: i: the amout to subtract
** Pre-Conditions: none
** Post-Conditions: money will be subtracted
*********************************************************************/
void Zoo::subtractBalance(unsigned int i){
    money = money - i;
}

/*********************************************************************
** Function: printStatus
** Description: prints the table of owned animals 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: a table of owned animals is printed
*********************************************************************/
void Zoo::printStatus(){
    tallyAnimals();
    int w = 18;
    cout << setfill(' ') << left << setw(w) << "";
    cout << setfill(' ') << left << setw(w) << "Monkies";
    cout << setfill(' ') << left << setw(w) << "Sea Otters";
    cout << setfill(' ') << left << setw(w) << "Meerkats" << endl;
    
    cout << setfill(' ') << left << setw(w) << "Adults";
    cout << setfill(' ') << left << setw(w) << adultMonkies;
    cout << setfill(' ') << left << setw(w) << adultSea;
    cout << setfill(' ') << left << setw(w) << adultKat << endl;

    cout << setfill(' ') << left << setw(w) << "Adolecents";
    cout << setfill(' ') << left << setw(w) << adoMonkies;
    cout << setfill(' ') << left << setw(w) << adoSea;
    cout << setfill(' ') << left << setw(w) << adoKat << endl;

    cout << setfill(' ') << left << setw(w) << "Babies";
    cout << setfill(' ') << left << setw(w) << babyMonkies;
    cout << setfill(' ') << left << setw(w) << babySea;
    cout << setfill(' ') << left << setw(w) << babyKat << endl;

    cout << setfill(' ') << left << setw(w) << "Totals";
    cout << setfill(' ') << left << setw(w) << adultMonkies + adoMonkies + babyMonkies;
    cout << setfill(' ') << left << setw(w) << adultSea + adoSea + babySea;
    cout << setfill(' ') << left << setw(w) << adultKat + adoKat + babyKat << endl;
    
    cout << "\nTotal animals: " << totalAnimals <<  "\n\n" << endl;
}

/*********************************************************************
** Function: tallyAnimals
** Description: tallies all the animals recording types and ages
** Parameters: none
** Pre-Conditions: the animal ponter array is called
** Post-Conditions: none
*********************************************************************/
void Zoo::tallyAnimals(){
    adultMonkies = 0, adoMonkies = 0, babyMonkies = 0, adultSea = 0, adoSea = 0, babySea = 0, adultKat = 0, adoKat = 0, babyKat = 0;
    for (int i = 0; i<totalAnimals; i++){
        if (animals[i]->getType() == "monkey"){
            if (animals[i]->getBaby()){
                babyMonkies++;
            }
            else if(animals[i]->getAge() < 103){
                adoMonkies++;
            }
            else{
                adultMonkies++;
            }
        }
        else if (animals[i]->getType() == "seaotter"){
            if (animals[i]->getBaby()){
                babySea++;
            }
            else if(animals[i]->getAge() < 103){
                adoSea++;
            }
            else{
                adultSea++;
            }
        }
        else if (animals[i]->getType() == "meerkat"){
            if (animals[i]->getBaby()){
                babyKat++;
            }
            else if(animals[i]->getAge() < 103){
                adoKat++;
            }
            else{
                adultKat++;
            }
        }
    }
}

/*********************************************************************
** Function: triggerRandomEvent
** Description: triggeres the weekly special event to happen
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: a special even will happen
*********************************************************************/
void Zoo::triggerRandomEvent(){
    int event = rand() % 4;
    tallyAnimals();
    if ((event == 0) && (adultMonkies >= 2 || adultSea >= 2 || adultKat >= 2)){
        reproduction();
    }
    else{
        event = rand() % 3 + 1;
    }

    if (event == 1 && totalAnimals > 0){
        sickness();
    }
    else if (event == 2){
        boom = true;
        cout << "There is a boom in visitors this week! " << endl;
    }
    else if (event == 3){
        cout << "There was no special event this week. " << endl;
    }
}


/*********************************************************************
** Function: reproduction
** Description: creates a new baby animal from a random adult animal
** Parameters: none
** Pre-Conditions: 2 adult animals are in the animal array
** Post-Conditions: a new baby animal is added to the array
*********************************************************************/
void Zoo::reproduction(){
    cout << "This week a ";
    //find a random adult animal to give birth
    while(true){
        int index = rand() % totalAnimals;
        if (animals[index]->getAge() > 103){
            if (animals[index]->getType() == "monkey"){
                Monkey* m1 = new Monkey("monkey", 0);
                addAnimal(m1);
                babyMonkies++;
                cout << "monkey gave birth!" << endl;
                break;
            }
            else if(animals[index]->getType() == "seaotter"){
                Seaotter* s1 = new Seaotter("seaotter", 0);
                addAnimal(s1);
                babySea++;
                cout << "sea otter gave birth!" << endl;
                break;
            }
            else{
                Meerkat* m1 = new Meerkat("meerkat", 0);
                Meerkat* m2 = new Meerkat("meerkat", 0);
                Meerkat* m3 = new Meerkat("meerkat", 0);
                addAnimal(m1);
                addAnimal(m2);
                addAnimal(m3);
                babyKat = babyKat + 3;
                cout << "meerkat gave birth!" << endl;
                break;
            }
        }
    }
}

/*********************************************************************
** Function: calcRevenue
** Description: calculaes and prints the revenue summary of the zoo for that week
** Parameters: none
** Pre-Conditions: a week has passed
** Post-Conditions: none
*********************************************************************/
void Zoo::calcRevenue(){
    int weeklyRevenue = 0;
    int madeFromAnimals = 0;
    int boomRevenue = 0;
    for (int i = 0; i<totalAnimals; i++){
        if (boom == false){
            madeFromAnimals = madeFromAnimals + animals[i]->getRevenue();
        }
        else{
            if (animals[i]->getType() != "monkey"){
                madeFromAnimals = madeFromAnimals + animals[i]->getRevenue();
            }
            else{
                int extra = rand() % 701 + 500;
                madeFromAnimals = madeFromAnimals + animals[i]->getRevenue() + extra;
                boomRevenue = boomRevenue + extra;
            }
        }
    }
    weeklyRevenue = madeFromAnimals - (spentOnFood + spentOnTreatment);
    money = money + weeklyRevenue;

    printMoneySummary(weeklyRevenue, madeFromAnimals, boomRevenue);

    
}

/*********************************************************************
** Function: printMoneySummary
** Description: prints out the info about expences and profit and revenue for the week
** Parameters: weeklyRevenue: the money made that week, madeFromAnimals: the money made from the animals that weeek, boomRevenue: the additonal revenue made from having a boom
** Pre-Conditions: calcRevenue was called
** Post-Conditions: the info will be printed
*********************************************************************/
void Zoo::printMoneySummary(int weeklyRevenue, int madeFromAnimals, int boomRevenue){
    cout << "This week you spent " << spentOnFood << " dollars on food and " << spentOnTreatment << " dollars on treatment for a total weekly expense of " << (spentOnFood + spentOnTreatment) << " dollars." << endl;
    if (boom == true && (numMonkeys > 0)){
        cout << "Because of the boom you made an additonal " << boomRevenue << " dollars from your monkies for a total of " << madeFromAnimals << " dollars from your animals." << endl;
    }
    else{
        cout << "You made " << madeFromAnimals << " dollars from you animals." << endl;
    }
    cout << "Total revenue this week is " << weeklyRevenue << " dollars." << endl;
    cout << "Your balance is " << money << " dollars." << endl;
    boom = false;
    spentOnTreatment = 0;

}

