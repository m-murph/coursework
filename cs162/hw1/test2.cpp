//s
#include <iostream>
using namespace std;


void sortAndPrint(string* schoolNames, int numSchools){
    bool changes = true;
    string tmpString;
    //sort the string contaning the names
    while (changes){
        changes = false;
        for (int i = 0; i<numSchools-1; i++){
            if (schoolNames[i] < schoolNames[i+1]){
                tmpString = schoolNames[i+1];
                schoolNames[i+1] = schoolNames[i];
                schoolNames[i] = tmpString;
                changes = true;
            }
        }
    }
    //print the array
    for (int i = 0; i<numSchools; i++){
        cout << schoolNames[i] << endl;
    }
}


int main(){
    int num = 10;
    string* array = new string[num];

    array[0] = "0.1 sand";
    array[1] = "0.2 horse";
    array[2] = "0.8 sdfsdfsd";
    array[3] = "0.9 ffykfgf";
    array[4] = "0.6 rydd";
    array[5] = "0.5 k";
    array[6] = "1 tuif";
    array[7] = "0.9999 fhf";
    array[8] = "0.2 eeeretrfhf";
    array[9] = "0.1 jfgjgfjfg";

    sortAndPrint(array, num);
    delete[] array;
}