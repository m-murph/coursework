#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"


/* Define this function, type casting the value of void * to the desired type.
   The current definition of TYPE in bst.h is void*, which means that left and
   right are void pointers. To compare left and right, you should first cast
   left and right to the corresponding pointer type (struct data *), and then
   compare the values pointed by the casted pointers.

   Return value:
	-1 if left < right return
	 1 if left > right return
	 0 if left = right return
  
   DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
   which is really wrong.
*/

int compare(TYPE left, TYPE right)
{
	/*FIXME: write this*/
   if (((struct data*)left)->number > ((struct data*)right)->number){
      return 1;
   }
   else if (((struct data*)left)->number < ((struct data*)right)->number){
      return -1;
   }
	return 0; 
}


// Define this function, type casting the value of void* to the desired type

void print_type(TYPE value)
{
	/*FIXME: write this*/
   printf("%d\n", ((struct data*)(value))->number);
}


