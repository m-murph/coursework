/*
	This file describes the House class.
*/
#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>

class House {
public:
	// constructors
	House();
	// destructor
	~House();


	// prototypes for member functions
	std::string getAddress();
	void displayAddress();

	// member variables of the House class
	std::string address;
	int numBedrooms;
	int numBathrooms;
	int numDoors;
	int numWindows;
	// For future use:
	//Person* array;

	static int totalCount;
};
#endif
