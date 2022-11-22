/* CS261- Assignment 1A - Question 2
   Name: Michael Murphy
   Date: 9/22/2022
   Solution description:
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c)
{
    // Swap the addresses stored in the pointer variables a and b
    
    // Decrement the value of integer variable c
    
    // Return c

    //swap
    int* tmpPtr = a;
    a = b;
    b = tmpPtr;

    c--;

    return c;
}

int main()
{
     // Declare three integers x,y and z and initialize them randomly to values in [0,10]
    
    // Print the values of x, y and z
    
    // Call foo() appropriately, passing x,y,z as parameters
    
    // Print the values of x, y and z
    
    // Print the value returned by foo
 
    srand(time(NULL));

    int x = rand() % 11;
    int y = rand() % 11;
    int z = rand() % 11;

    printf("Before foo: X: %d, Y: %d, Z: %d\n", x, y, z);
    int out = foo(&x, &y, z);
    printf("After foo: X: %d, Y: %d, Z: %d\n", x, y, z);
    printf("output of foo: %d\n", out);
    return 0;


    //the return value of foo is different then the value of z because z was passed by value.
    //x, y, and z are the same because their address were passed by value to foo.
}
    
    


