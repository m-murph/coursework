#include <iostream>
#include "bats.h"
using namespace std;

/*********************************************************************
** Function: printPerception
** Description: prints the perception for the event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the perception is printed to the output and is value is returned
*********************************************************************/
int Bats::printPerception(){
    cout << "You hear the sound of flapping and shrieking." << endl;
    return 2;
}

/*********************************************************************
** Function: getType
** Description: returns the type of event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the type of event is returned
*********************************************************************/
int Bats::getType(){
    return 2;
}