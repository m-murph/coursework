#include <iostream>
#include "event.h"
#include "chimera.h"
#include "bats.h"
#include "lava.h"
#include "gold.h"
#include "empty.h"
#include "room.h"
using namespace std;

/*********************************************************************
** Function: room constructor
** Description: constructs a room by setting the event pointer to null
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: a room is created
*********************************************************************/
Room::Room(){
    events = NULL;
}

/*********************************************************************
** Function: getEvent
** Description: returns the pointer to the event
** Parameters: none
** Pre-Conditions: a room has been constructed 
** Post-Conditions: a pointer is returned
*********************************************************************/
Event* Room::getEvent(){
    return events;
}

/*********************************************************************
** Function: setEvent
** Description: sets the event that this room can have
** Parameters: ep: a pointer to an event
** Pre-Conditions: the room has been constructed
** Post-Conditions: the room will have an updated event
*********************************************************************/
void Room::setEvent(Event* ep){
    delete events;
    events = ep;
}

/*********************************************************************
** Function: the destructor for the room class 
** Description: delets the stuff at the event pointer
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the dynamically allocated memory for the room pointer is freed
*********************************************************************/
Room::~Room(){
    //cout << "ROOM DESTRUCT RAN" << endl;
    delete events;
}
