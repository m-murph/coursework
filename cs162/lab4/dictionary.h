#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
using namespace std;

#define MAX_ENTRIES 10

struct entry {
	string word;
	string* alt_spellings; // dynamic array of alternate spellings
	int num_alt_spellings; // the size of the alt_spellings array
};

class Dictionary {
private:
	int index; // how many of the entries are already in use
	entry entries[MAX_ENTRIES]; // a statically allocated array of entry structs
public:
	Dictionary(); // default constructor
	Dictionary(const Dictionary&); // copy constructor
	~Dictionary();
	Dictionary& operator=(const Dictionary&); // assignment operator overload
	// add a word to the dictionary (along with its two alternate spellings)
	void add_word(string new_word, string alt_1, string alt_2);

	void display();
};

#endif
