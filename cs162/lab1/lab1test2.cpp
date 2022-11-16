#include <iostream>
using namespace std;

void getString(string* pointerToInput);

string convertToTilde(string * pointerToInput);

int searchAndReplace(char inChar, string originalInput, string & refToTildeString);



int main() {

	string input = "test";
	string * pointerToInput = &input;

	cout << "please enter a string: " << endl;
	getString(pointerToInput);
	
	string tString = convertToTilde(pointerToInput);
	cout << "the tilde-version of your sting is: \n" << tString << endl;
	
	cout << "Please tell me the char that you would like to locate and replace: " << endl;
	char inChar;
	cin >> inChar;

	int charsFound = searchAndReplace(inChar, *pointerToInput, tString);

	cout << "The new output string is \n" << tString << endl;
	cout << "Found " << charsFound << " instance(s) of " << inChar << "." << endl;

	return 0;
}

void getString(string * pointerToInput) {
	string input;
	getline(cin, input);
	*pointerToInput = input;
}

string convertToTilde(string * pointerToInput){
	string tString = *pointerToInput;

	for (int i = 0; i < tString.length(); i++){
		if (tString[i] != ' '){
			tString[i] = '~';
		}
	}
	return tString;
}

int searchAndReplace(char inChar, string originalInput, string & refToTildeString){
	int foundChars = 0;

	for (int i = 0; i < originalInput.length(); i++){
		if (originalInput[i] == inChar){
			foundChars = foundChars + 1;
			refToTildeString[i] = inChar;
		}
	}	
	return foundChars;
}

