#include <iostream>
#include "chimera.h"
using namespace std;

/*********************************************************************
** Function: printPerception
** Description: prints the perception for the event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the perception is printed to the output and is value is returned
*********************************************************************/
int Chimera::printPerception(){
    cout << "There is a terrible smell." << endl;
    return 1;
}

/*********************************************************************
** Function: getType
** Description: returns the type of event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the type of event is returned
*********************************************************************/
int Chimera::getType(){
    return 1;
}