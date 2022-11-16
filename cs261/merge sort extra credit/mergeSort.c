#include <stdlib.h>
#include <stdio.h>


typedef struct fArray{
    int** vals;
    int size;
}fArray;

int isEven(int a){
    if ((double)a/2.0 == (double)(a/2))
        return 1;
    return 0;
}




int** divide(int* a, int size){
    int** dividedArray = (int**)malloc(sizeof(int**) * size);
    int* dividePoints = (int*)malloc(sizeof(int) * size);
    if (isEven(size) == 1){
        for (int i = 0; i<size; i = i + 2){
            dividePoints[i] = i;
        }
    }
    else{
        int i;
        for (i = 0; i<size; i = i +2){
            dividePoints[i] = i;
        }
        dividePoints[i+1] = i+1;
    }

}

int* rebuild(int** ma);




void mergeSort(int* a, int size){
    int** masterArray = divide(a, size);
}


int main(){

    int myInts[35];
    for (int i = 34; i >= 0; i--){
        myInts[i] = i;
    }


    for (int i = 0; i<35; i++){
        //printf("%d\n", myInts[i]);
    }
    printf("\n\n\n");

    mergeSort(myInts, 35);

    for (int i = 0; i<35; i++){
        //printf("%d\n", myInts[i]);
    }
}