#include <iostream>
#include "lab2.cpp"
#include <cmath>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3 || !is_valid_dimensions(argv[1], argv[2])){
        cout << "Error, enter 2 integer command line arguments please." << endl;
        return 1;
    }

    
    string cx = argv[1], cy = argv[2];

    while (true){
    	stringstream ss, sy;
    	double x, y;
    	ss << cx;
    	ss >> x;
   	    sy << cy;
    	sy >> y;

        mult_div_values** table = create_table(x, y);
        set_mult_values(table, x, y);
        set_div_values(table, x, y);
        print_output(table, x, y);
        delete_table(table, x);

	    int run;
        cout << "would you like to see another table? (1-yes, 0-no)" << endl;
        cin >> run;
        if (run == 0){
            return 0;
        }

        cout << "enter the number of rows" << endl;
        cin >> cx;

        cout << "enter the number of colums" << endl;
        cin >> cy;

        if (!checkValues(cx, cy)){
            cout << "Error, enter integers please." << endl;
            return 1;
        }
    }
}
