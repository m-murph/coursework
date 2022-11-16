
#include <iostream>
using namespace std;





void getString(string *) {
	string input;
	
	getline(cin, input);

	*string = input;

}





int main() {


	
	string input;

	string* pointer;
	pointer = &string;

	

	cout << "please enter a string: " << endl;
	getString(pointer);
	

	cout << "the tilde-version of your sting is:" << endl;








}