

#include <iostream>
using namespace std;




class House {
public:
    string  getAddress();
    void displayAddress();
    string address;
    int numBedrooms;
    int numBathrooms;
    int numDoors;
    int numWindows;
};

string House::getAddress(){
    return address;
}

void House::displayAddress() {
    cout << "The address is " << address << endl;
}


int main(){

    House myHouse;
    myHouse.address = "69 bruh moment ave";
    cout << myHouse.getAddress() << endl;
    myHouse.displayAddress();


    House anotherHouse;
    anotherHouse.address = "420 sorry noob way";
    anotherHouse.displayAddress();



    House* coolHouse = new House;

    (*coolHouse).address = "73 IDI street, ketchup town";
    (*coolHouse).displayAddress();

    coolHouse->displayAddress(); 



    delete coolHouse;
    return 0;
}
