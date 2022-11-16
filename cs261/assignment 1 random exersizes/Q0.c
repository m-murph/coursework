/* CS261- Assignment 1A - Question 0
   Name: Michael Murphy
   Date: 9/22/2022
   Solution description:
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr)
{
  
     // Print the value and address of the integer pointed to by iptr
          
     // Increment the value of the integer pointed to by iptr by 5
          
     // Print the address of iptr itself

     printf("Value of the int at iptr: %d\n", *iptr);
     printf("Address that iptr is pointing to: %p\n", iptr);

     *iptr = *iptr + 5;

     //printf("Result of adding 5 to value at iptr: %d\n", *iptr);   
     printf("Address of iptr after adding 5 to the integer iptr is pointing to: %p\n", &iptr);

}


void fooB(int* jptr)
{
     // Print the value and address of the integer pointed to by jptr
            
     // Decrement jptr by 1
      
     // Print the address of jptr itself


     printf("Value of the int at jptr: %d\n", *jptr);
     printf("Address that jptr is pointing to: %p\n", jptr);

     jptr = jptr - 1;

     printf("Address of jptr: %p\n", &jptr);
}


int main()
{

    // Declare an integer x and initialize it randomly to a value in [0,10]
    
    // Print the value and address of x
    
    // Call fooA() with the address of x
    
    // Print the value of x
    
    // Call fooB() with the address of x
    
    // Print the value and address of x

     srand(time(NULL));
     int x = rand() % 11;
     printf("Vale of x: %d\n", x);
     printf("Address of x: %p\n", &x);

     int* xp = &x;
     fooA(xp);
     printf("The value of x after fooA is %d\n", x);
     //the value is different because we passed it by pointer to fooA then fooA added 5 to it

     fooB(xp);
     printf("Value of x after fooB: %d\n", x);
     printf("Address of x after fooB: %p\n", &x);
     //they are not different because fooB did not alter the actual value of x, just the pointer. the pointer to x is also the 
     //same because we passed the pointer by value to fooB so the pointer in main() was not changed

    return 0;
}


