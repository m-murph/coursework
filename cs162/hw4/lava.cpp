#include <iostream>
#include "lava.h"
using namespace std;

/*********************************************************************
** Function: printPerception
** Description: prints the perception for the event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the perception is printed to the output and is value is returned
*********************************************************************/
int Lava::printPerception(){
    cout << "it feels incredibly hot." << endl;
    return 3;
}

/*********************************************************************
** Function: getType
** Description: returns the type of event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the type of event is returned
*********************************************************************/
int Lava::getType(){
    return 3;
}