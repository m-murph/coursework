#include <iostream>
#include "gold.h"
using namespace std;

/*********************************************************************
** Function: printPerception
** Description: prints the perception for the event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the perception is printed to the output and is value is returned
*********************************************************************/
int Gold::printPerception(){
    cout << "You see the shine of gold in the distance." << endl;
    return 4;
}

/*********************************************************************
** Function: getType
** Description: returns the type of event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the type of event is returned
*********************************************************************/
int Gold::getType(){
    return 4;
}