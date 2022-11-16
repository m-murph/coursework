#include <iostream>
#include "house.h"

using namespace std;

int House::totalCount = 0;

// this is a default counstructor
House::House() {
	cout << "Created a new house!" << endl;
	totalCount++;
	numBedrooms = 0;
	numBathrooms = 0;
	numDoors = 0;
	numWindows = 0;
}
// (we could write more constructors if we want)

// destructor
House::~House() {
	cout << "I destroyed a house!" << endl;
}

string House::getAddress() {
	return address;
}

void House::displayAddress() {
	cout << "The address is: " << address << endl;
}
