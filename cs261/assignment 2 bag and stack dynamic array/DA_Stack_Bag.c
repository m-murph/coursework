// DA_Stack_Bag.c: Dynamic Array, Stack and Bag implementations
#include <assert.h>
#include <stdlib.h>
#include "DA_Stack_Bag.h"


/* ************************************************************************
	Struct DynArr
************************************************************************ */

typedef struct DynArr {
    TYPE* data;
    int size;
    int capacity;
}DynArr;

/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

DynArr* newDynArr(int capacity){
	DynArr* array = (DynArr*)malloc(sizeof(DynArr));
	assert(array != NULL);
	array->data = (TYPE*)malloc(sizeof(TYPE) * capacity);
	assert(array->data != NULL);
	array->capacity = capacity;
	array->size = 0;
	return array;
}

void _dynArraySetCapacity(DynArr* v, int newCap){
    assert(v != NULL && v->data != NULL);
	TYPE* tmpArray = (TYPE*)malloc(sizeof(TYPE) * newCap);
    assert(tmpArray != NULL);
	for (int i = 0; i<v->size; i++){
		tmpArray[i] = v->data[i];
	}
	free(v->data);
    v->capacity = newCap;
	v->data = tmpArray;
}

void deleteDynArr(DynArr *myDA){
	assert(myDA != NULL && myDA->data != NULL);
	free(myDA->data);
	myDA->size = 0;
	myDA->data = NULL;
	free(myDA);
}

int sizeDynArr(DynArr *myDA){
	return myDA->size;
}

void addDynArr(DynArr *myDA, TYPE value){
	assert(myDA != NULL && myDA->data != NULL);
	if (myDA->size >= myDA->capacity){
        _dynArraySetCapacity(myDA, 2 * myDA->capacity);
    }
	myDA->data[myDA->size] = value;
	myDA->size++;
}

TYPE getDynArr(DynArr *myDA, int position){
	assert(myDA != NULL && myDA->data != NULL && position < myDA->size && myDA->size != 0);
	return myDA->data[position];
}

void putDynArr(DynArr *myDA, int position, TYPE value){
	assert(myDA != NULL && myDA->data != NULL && position < myDA->size);
	myDA->data[position] = value;
}

void swapDynArr(DynArr *myDA, int idx_i, int  idx_j){
	assert(myDA != NULL && myDA != NULL && idx_i < myDA->size && idx_j < myDA->size);
	TYPE tmpVal = myDA->data[idx_i];
	myDA->data[idx_i] = myDA->data[idx_j];
	myDA->data[idx_j] = tmpVal;
}

void removeAtDynArr(DynArr *myDA, int idx_i){
	assert(myDA != NULL && myDA->data != NULL && idx_i < myDA->size);
	for (int i = idx_i; i<myDA->size - 1; i++){
		myDA->data[i] = myDA->data[i+1];
	}
	myDA->size--;
}

/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

Stack *newStack(int capacity){
	return newDynArr(capacity);
}

void deleteStack(Stack *myStack){
	deleteDynArr(myStack);
}

int sizeStack(Stack *myStack){
	assert(myStack != NULL);
	return myStack->size;
}

int isStackEmpty(Stack *myStack){
	assert(myStack != NULL);
	if (myStack->size == 0){
		return 1;
	}
	else{
		return 0;
	}
}

void pushStack(Stack *myStack, TYPE value){
	assert(myStack != NULL && myStack->data != NULL);
	addDynArr(myStack, value);
}

TYPE topStack(Stack *myStack){
	assert(myStack != NULL && myStack->data != NULL && myStack->size != 0);
	return myStack->data[myStack->size-1];
}

void popStack(Stack* myStack){
	assert(myStack != NULL && myStack->data != NULL && myStack->size != 0);
	myStack->size--;
}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

Bag *newBag(int capacity){
	return newDynArr(capacity);
}	

void deleteBag(Bag *myBag){
	deleteDynArr(myBag);
}	

int sizeBag(Bag *myBag){
	assert(myBag != NULL);
	return myBag->size;
}	

int isBagEmpty(Bag *myBag){
	assert(myBag != NULL);
	if (myBag->size == 0){
		return 1;
	}
	else{
		return 0;
	}
}	

void addBag(Bag *myBag, TYPE value){
	assert(myBag != NULL && myBag->data != NULL);
	addDynArr(myBag, value);
}	

int containsBag(Bag *myBag, TYPE value){
	assert(myBag != NULL && myBag->data != NULL);
	for (int i = 0; i<myBag->size; i++){
		if (myBag->data[i] == value){
			return 1;
		}
	}
	return 0;
}	

void removeBag(Bag *myBag, TYPE value){
	assert(myBag != NULL && myBag->data != NULL);
	int loc = -1;
    for (int i = 0; i<myBag->size; i++){
        if (myBag->data[i] == value){
            loc = i;
        }
    }
    if (loc != -1){
		for (int i = loc; i<myBag->size-1; i++){
			myBag->data[i] = myBag->data[i+1];
		}        
		myBag->size--;
		if (containsBag(myBag, value) == 1){
			removeBag(myBag, value);
		}
	}
}


