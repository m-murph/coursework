#include <stdlib.h>
#include <stdio.h>
#include "insertionsort.h"
#include "dynarray.h"

/* THE data STRUCT IS ONLY HERE FOR THE PRINT() STATEMENTS FOR VISUALIZING THE ALGORITHM, IT WOULD BE IN THE STRUCTS.H FILE FOR THE ACTUAL IMPLEMENTATION
    ADDIONALLY, EVERY PRINTF() FUNCTION IN THIS FILE WOULD NOT BE IN THE ACTUAL IMPLEMENTATION */
typedef struct data{
    int value;
}data;


void _insert(struct dynarray* array, void* value){\
    dynarray_insert(array, value);
    printf("Inserting %d into the end of the sorted array.\n", ((data*)value)->value);
    printf("\n  Array Status:  ");
    printArray(array);
    printf("\n");

    int k = dynarray_size(array);
    //This for has O(n) time complexity
    int i;
    for (i = k-1; i>0; i--){
        //swap the values until the new value reaches its proper position
        if (compare(dynarray_get(array, i-1), dynarray_get(array, i)) == 0){
            printf("Swapping %d and %d...\n", ((data*)dynarray_get(array, i))->value, ((data*)dynarray_get(array, i-1))->value);
            void* tmp = dynarray_get(array, i-1);
            dynarray_set(array, i-1, dynarray_get(array, i));
            dynarray_set(array, i, tmp);
            printf("\n  Array Status: ");
            printArray(array);
            printf("\n");
        }
        else{
            break;
        }
    }
}

void insertionSort(struct dynarray* array){
    if (dynarray_size(array) == 0){
        return;
    }
    int k = dynarray_size(array);
    void* start = dynarray_get(array, 0);
    struct dynarray* sortedArray = dynarray_create();
    printf("Inserting %d to initialize the sorted array\n", ((data*)start)->value);
    dynarray_insert(sortedArray, start);
    printf("\n  Array Status:  ");
    printArray(sortedArray);
    printf("\n");

    //This for loop takes O(n^2) to complete
    for (int i = 1; i<k; i++){
        //_insert() has O(n) complexity
        _insert(sortedArray, dynarray_get(array, i));
    }

    //Just copies sorted array back over to original array, O(n).
    for (int i = 0; i<k; i++){
        dynarray_set(array, i, dynarray_get(sortedArray, i));
    }

    //free the temporary sortedArray but not the things its pointing to.
    dynarray_free(sortedArray);

    /* Overall, this function can take up to O(n^2) to complete due 2 to nested for loops */
}



