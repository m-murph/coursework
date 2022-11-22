#include <stdlib.h>
#include <stdio.h>
#include "insertionsort.h"
#include "structs.h"

int compare(void* a, void* b){
    if (((data*)a)->value <= ((data*)b)->value){
        return 1;
    }
    else{
        return 0;
    }
}

void printArray(struct dynarray* array){
    if (dynarray_size(array) == 0){
        printf("Nonexistant (empty).\n");
        return;
    }
    int k = dynarray_size(array);
    printf("{");
    for (int i = 0; i<k; i++){
        if (i != k-1){
            printf("%d, ", ((data*)dynarray_get(array, i))->value);
        }
        else{
            printf("%d", ((data*)dynarray_get(array, i))->value);
        }
    } 
    printf("}");
    printf("\n");
}