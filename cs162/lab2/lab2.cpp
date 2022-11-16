#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "mult_div.h"
using namespace std;

void print_output(mult_div_values ** table, int x, int y){
    cout << "Multiplication Table:" << endl;
    for (int i = 0; i<x; i++){
        for (int j = 0; j<y; j++){

            cout << setfill(' ') << left << setw(5) << table[i][j].mult;
        }
        cout << endl;
    }
    cout << endl;

    cout << "Division Table:" << endl;
    for (int i = 0; i<x; i++){
        for (int j = 0; j<y; j++){
            cout << setfill(' ') << left << setw(6) << ceil(table[i][j].div * 100)/100;
        }
        cout << endl;
    }
}

bool is_valid_dimensions(char* x, char* y){
    string cx = x;
    string cy = y;

    for (unsigned int i = 0; i<cx.length(); i++){
        if (!isdigit(cx[i])){
            return false;
        }
    }

    for (unsigned int i = 0; i<cy.length(); i++){
        if (!isdigit(cy[i])){
            return false;
        }
    }

    stringstream ss, sy;
    double xf, yf;

    ss << cx;
    ss >> xf;
    sy << cy;
    sy >> yf;

    if ((int)xf != xf || (int)yf != yf){
        return false;
    }
    return true;
}

mult_div_values** create_table(int x, int y){
    mult_div_values** valArray = new mult_div_values*[x];
    for (int i = 0; i<x; i++){
        valArray[i] = new mult_div_values[y];
    }
    return valArray;
}

void set_mult_values(mult_div_values ** valArray, int x, int y){
    for (int i = 0; i<x; i++){
        for (int j = 0; j<y; j++){
            valArray[i][j].mult = (i+1) * (j+1);
        }
    }
}

void set_div_values(mult_div_values ** valArray, int x, int y){
    for (int i = 0; i<x; i++){
        for (int j = 0; j<y; j++){
            valArray[i][j].div = ((double)i+1) / ((double)j+1);
        }
    }

}


bool checkValues(string cx, string cy){

    for (unsigned int i = 0; i<cx.length(); i++){
        if (!isdigit(cx[i])){
            return false;
        }
    }

    for (unsigned int i = 0; i<cy.length(); i++){
        if (!isdigit(cy[i])){
            return false;
        }
    }

    stringstream ss, sy;
    double xf, yf;

    ss << cx;
    ss >> xf;
    sy << cy;
    sy >> yf;

    if ((int)xf != xf || (int)yf != yf){
        return false;
    }
    return true;
}

void delete_table(mult_div_values ** table, int m){
    for (int i = 0; i<m; i++){
        delete[] table[i];
    }
    delete[] table;
}


