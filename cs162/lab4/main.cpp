#include "dictionary.h"
#include <iostream>
using namespace std;

/*
	Test the functionality of the dictionary
*/
int main() {
	/*
	Dictionary d1;
	d1.add_word("island", "ilande", "ylonde");
	d1.add_word("jeopardy", "yeopardie", "ieoperde");
	d1.display();
	Dictionary d2;
	d2 = d1;
	Dictionary d3 = d1;
	d2.display();
	cout << "\n\n\n" << endl;
	*/

	
	
	Dictionary src, book2;    
	src.add_word("island", "ilande", "ylonde");    
	Dictionary book1 = src;    
	book1.add_word("february", "feverere", "feverell");    
	book2 = book1;    
	book2.add_word("jeopardy", "yeopardie", "ieoperde");    

	cout << "Contents of src: " << endl;    
	src.display();    
	cout << "Contents of book1: " << endl;    
	book1.display();    
	cout << "Contents of book2: " << endl;    
	book2.display(); 
	






	return 0;
}
