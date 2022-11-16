/********************************************************************* 
 * * Program Filename: homework1.cpp
 * * Author: Michael Murphy
 * * Date: 7-1-2022
 * * Description: takes information about highschools and their football matches from a file and processes them.
 * * Input: a file name and numbers that decie which calculations to do
 * * Output: the earliest year the schools are on file, the best year the school has had (by points aquired), and the overall win ratio for each school
 * *********************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

struct Match{
    unsigned int year;
    unsigned int homeScore;
    string opponentName;
    unsigned int opponentScore;
};

struct School {
    string name;
    string moniker;
    string city;
    double winRatio;
    int numMatches;
    struct Match* array;
};

//required functions
Match* create_match_array(int numMatches);
void load_match_data(Match* matches, int numSchools, ifstream & file);
void load_school_data(School* schools, int numSchools, ifstream & file);
School* create_school_array(int numSchools);
void delete_school_data(Match* matches, int numMatches);

//my functions
void fillWinRatio(School* schools, int numSchools);
void getUserInput(School* schoolArray, int numSchools);
void displayEarliestYear(School* schools, int numSchools);
void listPerformance(School* schools, int numSchools);
void listBestYear(School* schools, int numSchools);
string doubleToString(int x);
void sortAndPrint(string* schoolNames, int numSchools);




/*********************************************************************  
 * ** Function: delete_school_data
 * ** Description: un-allocates the memmory that was allocated when the school struct and match struct arrays were created
 * ** Parameters: School* schools: a pointer to an array of school structs (the structs contain the match arrays). int numSchools: the number of schools in that array  
 * ** Pre-Conditions: the school struct array and match struct array have had their memmmory allocated
 * ** Post-Conditions: the school struct array and match struct arrays will be wiped from memmory  
 * *********************************************************************/
void delete_school_data(School* schools, int numSchools){
    for (int i = 0; i<numSchools; i++){
        delete[] schools[i].array;
    }
    delete[] schools;
}

/*********************************************************************  
 * ** Function: create_match_array
 * ** Description: allocates memmory for the match struct arrays 
 * ** Parameters: int numMatches: the number of match structs that need to be in the array
 * ** Pre-Conditions: the number of matches has been determined in the load_school_data function 
 * ** Post-Conditions: there will be memmory allocated for an array of match structs
 * *********************************************************************/
Match* create_match_array(int numMatches){
    Match *matchArray = new Match[numMatches];
    return matchArray;
}

/*********************************************************************  
 * ** Function: create_school_array
 * ** Description: allocates memmory for the School struct array
 * ** Parameters: int numSchools: the number of school structs that you want to be in the array
 * ** Pre-Conditions: the number of school has been found 
 * ** Post-Conditions: there will be memmory allocated for an array of school structs 
 * *********************************************************************/
School* create_school_array(int numSchools){
    School *schoolArray = new School[numSchools];
    return schoolArray;
}

/*********************************************************************  
 * ** Function: load_match_data
 * ** Description: populates the match structs in the match struct array
 * ** Parameters: Match* matches: a pointer to an array of match structs. int numMatches: the number of matches that need to be in the array. ifstream & file: a refrence to the data file.
 * ** Pre-Conditions: the file is open, load_school_data has been called, and the number of matches has been given, and memmory has been allocated for the array.
 * ** Post-Conditions: the array will be filled with match structs, and the data in the structs will be filled 
 * *********************************************************************/
void load_match_data(Match* matches, int numMatches, ifstream & file){
    for (int i = 0; i<numMatches; i++){
        file >> matches[i].year;
        file.ignore();
        file >> matches[i].homeScore;
        file.ignore();
        getline(file, matches[i].opponentName, ';');
        file >> matches[i].opponentScore;
        file.ignore();
    }
}

/*********************************************************************  
 * ** Function: load_school_data
 * ** Description: populates the structs in the school struct array 
 * ** Parameters:  School* schools: a pointer to an array of school structs. int numSchools: the number of schools in the file. ifstream & file: a refrence to the data file.
 * ** Pre-Conditions: the file is open, memmory has been allocated for the school array, and the number of schools has been determined
 * ** Post-Conditions: the structs in the school struct array will be fully populated 
 * *********************************************************************/
void load_school_data(School* schools, int numSchools, ifstream & file){
    for (int i = 0; i<numSchools; ++i){
	file.ignore();
        getline(file, schools[i].name, ';');
        getline(file, schools[i].moniker, ';');
        getline(file, schools[i].city, ';');
        file >> schools[i].numMatches;
        file.ignore();

        //allocate memory for the match array for this school then fill it up
        Match* matches = create_match_array(schools[i].numMatches);
        load_match_data(matches, schools[i].numMatches, file);
        schools[i].array = matches;
    }
    //fill the win ratios
    fillWinRatio(schools, numSchools);
}

/*********************************************************************  
 * ** Function: fillWinRatio
 * ** Description: fills the win ratio for a school struct in the school struct array
 * ** Parameters: School* schoolArray: a pointer to an array of school structs, int numSchools: the number of schools in the array
 * ** Pre-Conditions: load_school_data has been called
 * ** Post-Conditions: the win ratio for each school struct in the school struct array will be populated 
 * *********************************************************************/
void fillWinRatio(School* schoolArray, int numSchools){
    int totalWins;
    for (int i = 0; i<numSchools; i++){
        totalWins = 0;
        for (int j = 0; j<schoolArray[i].numMatches; j++){
            if (schoolArray[i].array[j].homeScore > schoolArray[i].array[j].opponentScore){
                totalWins = totalWins + 1;
            }
        }
        schoolArray[i].winRatio = totalWins/(double)schoolArray[i].numMatches;
    }
}

/*********************************************************************  
 * ** Function: displayEarliestYear
 * ** Description: find the earliest year for each school and prints it out
 * ** Parameters: School* schools: a pointer to an array of school structs, int numSchools: the number of schools in the array
 * ** Pre-Conditions: the school struct array has been entirely populated and the user has requested to see the earliest year 
 * ** Post-Conditions: the earliest year for each school will be printed to the standard output
 * *********************************************************************/
void displayEarliestYear(School* schools, int numSchools){
    unsigned int earlyYear;
    for (int i = 0; i<numSchools; i++){
        earlyYear = 2147483647;
        for (int j = 0; j<schools[i].numMatches; j++){
            if (schools[i].array[j].year < earlyYear){
                earlyYear = schools[i].array[j].year;
            }
        }
        cout << schools[i].name << ", '" << schools[i].moniker << "', Team founded: " << earlyYear << ", City: " << schools[i].city << endl;
    }
}

/*********************************************************************  
 * ** Function: doubleToString
 * ** Description: converts a double to a string using stringstream
 * ** Parameters: double x: the double that you want to convert
 * ** Pre-Conditions: listBestYear has been called
 * ** Post-Conditions: a string that has numerical charters will be returned
 * *********************************************************************/
string doubleToString(double x){
    stringstream ss;
    string output;
    ss << x;
    ss >> output;
    return output;
}

/*********************************************************************  
 * ** Function: listBestYear
 * ** Description: prints the best year by total number of points a school has had
 * ** Parameters: School* schools: a pointer to an array of school structs, int numSchools: the number of schools in the array
 * ** Pre-Conditions: the school struct array has been popululated and the user has requested to see the best year of each school
 * ** Post-Conditions: the best year for each school will be printed to standard output 
 * *********************************************************************/
void listBestYear(School* schools, int numSchools){
    string* sortArray = new string[numSchools];
    for (int i = 0; i<numSchools; i++){
        int pointsA = 0, maxPointsA = 0, highYear = 0;
        unsigned int currentYear = schools[i].array[0].year;

        for (int j = 0; j<schools[i].numMatches; j++){
            if (schools[i].array[j].year == currentYear){
                pointsA = pointsA + schools[i].array[j].homeScore;

                if (pointsA > maxPointsA){
                    maxPointsA = pointsA;
                    highYear = schools[i].array[j].year;
                }
            }
            else{
                currentYear = schools[i].array[j].year;
                pointsA = schools[i].array[j].homeScore;
            }      
        }
        sortArray[i] = schools[i].name + ": " + doubleToString((double)maxPointsA) + " points in " + doubleToString((double)highYear);
    }
    sortAndPrint(sortArray, numSchools);
    //free the allocated memory
    delete[] sortArray;
}

/*********************************************************************  
 * ** Function: sortAndPrint
 * ** Description: alphabetaclly sorts strings then prints them out
 * ** Parameters: string* schoolNames: a pointer to an array of strings. int numSchools: number of schools in the school struct array which is also the size of the schoolNames array
 * ** Pre-Conditions: listBestyears has been called and schoolNames has been filled up
 * ** Post-Conditions: schoolNames will be printed alphabetically then wiped from memory
 * *********************************************************************/
void sortAndPrint(string* schoolNames, int numSchools){
    bool changes = true;
    string tmpString;
    //bubble sort
    while (changes){
        changes = false;
        for (int i = 0; i<numSchools-1; i++){
            if (schoolNames[i] > schoolNames[i+1]){
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

/*********************************************************************  
 * ** Function: listPerformance
 * ** Description: prints out the schools and their win ratio
 * ** Parameters: School* schools: a pointer to an array of school structs, int numSchools: the number of schools in the array
 * ** Pre-Conditions: the school struct array has been popululated and the user has requested to see the overall performance 
 * ** Post-Conditions: the schools overall performace will be printed to standard output
 * *********************************************************************/
void listPerformance(School* schools, int numSchools){
    //create the string that will have the sorted win ratio output
    string* output = new string[numSchools];
    for (int i = 0; i<numSchools; i++){
        output[i] = doubleToString(round(((double)schools[i].winRatio) * 1000)/1000) + " for " + schools[i].name;
    }
    bool changes = true;
    string tmpString;
    //bubble sort
    while (changes){
        changes = false;
        for (int i = 0; i<numSchools-1; i++){
            if (output[i] < output[i+1]){
                tmpString = output[i+1];
                output[i+1] = output[i];
                output[i] = tmpString;
                changes = true;
            }
        }
    }
    for (int i = 0; i<numSchools; i++){
        cout << output[i] << endl;
    }
    delete[] output;
} 

/*********************************************************************  
 * ** Function: getUserInput
 * ** Description: prompts the user with the calculations that can be done and receves their input and calles the respective method
 * ** Parameters: School* schools: a pointer to an array of school structs, int numSchools: the number of schools in the array
 * ** Pre-Conditions: 
 * ** Post-Conditions: 
 * *********************************************************************/
void getUserInput(School* schoolArray, int numSchools){
    int input = 0;
    while (input != 4){
        cout << "Which option would you like to choose?" << endl;
        cout << "Display each school's earliest year on file (Press 1): " << endl;
        cout << "List the best year (by points acquired) for each school (Press 2): " << endl;
        cout << "Sort schools by overall historical performance (win ratio) (Press 3): " << endl;
        cout << "Quit (Press 4): " << endl;
        cin >> input;
	cout << endl;
        if (input == 1){
            displayEarliestYear(schoolArray, numSchools);
        }
        else if (input == 2){
            listBestYear(schoolArray, numSchools);
        }
        else if (input == 3){
            listPerformance(schoolArray, numSchools);
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]){
    ifstream dataFile;
    dataFile.open(argv[1]);
    if (argc != 2){
        cout << "Error, incorrect number of command line arguments entered." << endl;
	    dataFile.close();
        return 1;
    }
    if (!dataFile.is_open()){
        cout << "Error, the requested file was not found." << endl;
        return 1;
    }
    cout << endl;
    
    //find number of schools
    int numSchools = 0;
    dataFile >> numSchools;
    dataFile.ignore();

    //allocate memory for the match and school array then fill it up
    School* schoolArray = create_school_array(numSchools);
    load_school_data(schoolArray, numSchools, dataFile);
    
    //get user input
    getUserInput(schoolArray, numSchools);

    //clean up
    delete_school_data(schoolArray, numSchools);
    dataFile.close();
    return 0;
}

