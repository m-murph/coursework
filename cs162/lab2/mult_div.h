#include <iostream>
using namespace std;

struct mult_div_values {
    int mult;
    float div;
};

bool is_valid_dimensions(char *, char *);
mult_div_values** create_table(int, int);
void set_mult_values(mult_div_values **, int, int);
void set_div_values(mult_div_values **, int, int);
void delete_table(mult_div_values **, int);
void print_output(mult_div_values **, int, int);

bool checkValues(string, string);
