#include "dictionary.h"
using namespace std;

// default constructor
Dictionary::Dictionary() {
	cout << "Default constructor invoked." << endl;
	index = 0; // start with 0 entries
	// set the default number of alternate spellings to 0
	for (int i = 0; i < MAX_ENTRIES; i++) {
		entries[i].alt_spellings = NULL;
		entries[i].num_alt_spellings = 0;
	}
}

// copy constructor
Dictionary::Dictionary(const Dictionary& old_obj) {
	cout << "Copy constructor invoked." << endl;

	// your code will go here

	index = old_obj.index;
	for (int i = 0; i<10; i++){
	
		if (index > 0 && old_obj.entries[i].num_alt_spellings > 0){
			entries[i].alt_spellings = new string[old_obj.entries[i].num_alt_spellings];
			entries[i].word = old_obj.entries[i].word;
			entries[i].num_alt_spellings = old_obj.entries[i].num_alt_spellings;
			for (int j = 0; j<entries[i].num_alt_spellings; j++){
				
				entries[i].alt_spellings[j] = old_obj.entries[i].alt_spellings[j];
			}
		}
		else{
			entries[i].alt_spellings = NULL;
			entries[i].num_alt_spellings = 0;
		}	
	}
}

// assignment operator overload
Dictionary& Dictionary::operator=(const Dictionary& old_obj) {
	cout << "Assignment operator overload invoked." << endl;

	// your code will go here

	index = old_obj.index;
	for (int i = 0; i<10; i++){
		delete[] entries[i].alt_spellings;
		if (index > 0 && old_obj.entries[i].num_alt_spellings > 0){
			entries[i].alt_spellings = new string[old_obj.entries[i].num_alt_spellings];
			entries[i].word = old_obj.entries[i].word;
			entries[i].num_alt_spellings = old_obj.entries[i].num_alt_spellings;
			for (int j = 0; j<entries[i].num_alt_spellings; j++){
				entries[i].alt_spellings[j] = old_obj.entries[i].alt_spellings[j];
			}
		}
		else{
			entries[i].alt_spellings = NULL;
			entries[i].num_alt_spellings = 0;
		}	
	}
	return *this;
}

// deallocate all dynamic memory
Dictionary::~Dictionary() {
	cout << "Destructor invoked." << endl;
	for (int i = 0; i < MAX_ENTRIES; i++)
		delete [] entries[i].alt_spellings;
}

// add a word to the dictionary (along with its two alternate spellings)
void Dictionary::add_word(string new_word, string alt_1, string alt_2) {
	entry *tmp = &entries[index];
	tmp->word = new_word;
	tmp->num_alt_spellings = 2;
	tmp->alt_spellings = new string[tmp->num_alt_spellings];
	tmp->alt_spellings[0] = alt_1;
	tmp->alt_spellings[1] = alt_2;
	index++;
}



void Dictionary::display(){
	for (int i = 0; i<index; i++){
		cout << "Word: " << entries[i].word;
		cout << ". Alternate spelling(s): ";
		for (int j = 0; j<entries[i].num_alt_spellings; j++){
			cout << entries[i].alt_spellings[j] << " ";
		}
		cout << endl;
	}
}

