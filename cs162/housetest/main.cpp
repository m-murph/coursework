/*
	In-class demo to illustrate the development of a House class.
*/

#include <iostream>
#include "house.h"

using namespace std;


int main() {
	
	const int MYINT = 374;
	const int MYINT2 = 494;
	int const* ptr = &MYINT;
	
	cout << *ptr << endl;
	// The following line won't work:
	//(*ptr)++;
	cout << *ptr << endl;
	
	int const* const p2 = &MYINT;
	// The following line won't work:
	//p2 = &MYINT2;
	
	
	
	House myHouse;
	myHouse.address = "123 Main St, Happytown, USA";
	myHouse.displayAddress();
	
	House anotherHouse;
	anotherHouse.address = "223 4th Ave, Sunny Cove, USA";
	anotherHouse.displayAddress();
	cout << "The value of totalCount is: " << House::totalCount << endl;
	
	House* coolHouse = new House;
	(*coolHouse).address = "330 5th Ave, Rocky Edge, USA";
	// The following commented line is identical to the next line...
	//(*coolHouse).displayAddress();
	coolHouse->displayAddress(); // uses the "arrow" operator to dereference the pointer

	// display the totalCount
	cout << "The value of totalCount is: " << House::totalCount << endl;

	// delete the dynamic memory
	delete coolHouse;
	return 0;
}