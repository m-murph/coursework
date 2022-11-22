#ifndef INSERTIONSORT_C
#define INSERTIONSORT_C
#include "dynarray.h"


/* insertionsort.h uses the dynarray.h file provided for assignent 5 */

void insertionSort(struct dynarray* array);
int compare(void*, void*);

//printArray() only needs to be implemented if you with to print your array.
void printArray(struct dynarray* array);

#endif