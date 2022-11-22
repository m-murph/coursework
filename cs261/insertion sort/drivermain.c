#include <stdlib.h>
#include <stdio.h>
#include "insertionsort.h"
#include "dynarray.h"
#include "structs.h"

int main(){
    struct dynarray* array = dynarray_create();
    char inp[100];
    printf("\nPlease enter integers (press 'enter' after each entry, enter 'd' when done).\n");
    printf("Note, only enter around 4 - 5 integers or the visualization will take up many lines and be hard to read\n");
    fgets(inp, 2000, stdin);

    while (*inp != 'd'){
        int num; 
        if (sscanf(inp, "%d", &num) != 0){
            data* new = (data*)malloc(sizeof(data));
            new->value = num;
            dynarray_insert(array, new);
        }
        else if (*inp != 's'){
            printf("Error, not 'd' or integer input, try again.\n");
        }
        fgets(inp, 2000, stdin);
    }

    printf("Input array is:\n");
    printArray(array);

    insertionSort(array);
    printf("Finished, Sorted array is:\n");
    printArray(array);

    //free the memory
    int k = dynarray_size(array);
    for (int i = 0; i<k; i++){
        free(dynarray_get(array, i));
    }
    dynarray_free(array);
    return 0;
}