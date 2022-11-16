#include <iostream>
#include <vector>
#include "animal.h"
#include "meerkat.h"
using namespace std;

int main(){

    vector<Meerkat> den;

    Meerkat mk1("meerkat", "Emma", 104);
    Meerkat mk2("meerkat", "Liam", 104);
    Meerkat mk3("meerkat", "Oliver", 104);

    den.push_back(mk1);
    den.push_back(mk2);
    den.push_back(mk3);

    cout << "there are " << den.size() << " meerkats in the array" << endl;
    cout << "The first meerkat is: " << den.front().getName() << endl;

    Meerkat mk4("meerkat", "steve", 104);
    den.push_back(mk4);

    cout << "Name found using []: " << den[2].getName() << endl;

    cout << "Name found using at(): " << den.at(2).getName() << endl;

    vector<Meerkat> betterDen;

    betterDen = den;
    cout << endl;
    cout << "copied vector meerkat names: " << endl;
    for (unsigned int i = 0; i<betterDen.size(); i++){
        cout << betterDen[i].getName() << endl;
    }
    return 0;
}

