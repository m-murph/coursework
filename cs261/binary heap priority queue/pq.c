#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define TYPE int

typedef struct dyArray{
    TYPE* array;
    int size;
    int capacity;
}dyArray;


/* needed array functions */

dyArray* newDynArr(int capacity){
	dyArray* array = (dyArray*)malloc(sizeof(dyArray));
	array->array = (TYPE*)malloc(sizeof(TYPE) * capacity);
	array->capacity = capacity;
	array->size = 0;
	return array;
}

int dyArraySize(dyArray* d){
    return d->size;
}

void _dynArraySetCapacity(dyArray* v, int newCap){
	TYPE* tmpArray = (TYPE*)malloc(sizeof(TYPE) * newCap);
	for (int i = 0; i<v->size; i++){
		tmpArray[i] = v->array[i];
	}
	free(v->array);
    v->capacity = newCap;
	v->array = tmpArray;
}
void addDynArr(dyArray *myDA, TYPE value){
	if (myDA->size >= myDA->capacity){
        _dynArraySetCapacity(myDA, 2 * myDA->capacity);
    }
	myDA->array[myDA->size] = value;
	myDA->size++;
}

TYPE dyArrayGet(dyArray* ar, int index){
    return ar->array[index];
}

void dyArrayPut(dyArray* ar, int position, TYPE value){
    ar->array[position] = value;
}

void dyArrayRemoveLast(dyArray* d){
    if (d->size > 0){
        d->size--;
    }
}





/* heap functions */

dyArray* initHeap(int size){
    return newDynArr(size);
}

void _swap(dyArray* heap, int id1, int id2){
    TYPE tmp = dyArrayGet(heap, id1);
    dyArrayPut(heap, id1, dyArrayGet(heap, id2));
    dyArrayPut(heap, id2, tmp);
}

void _adjustHeap(struct dyArray* heap, int max, int pos){
    int leftChild = 2*pos + 1;
    int rightChild = 2*pos + 2;
    int smallChild;
    if (rightChild <= max){
        if (dyArrayGet(heap, leftChild) < dyArrayGet(heap, rightChild)){
            smallChild = leftChild;
        }
        else{
            smallChild = rightChild;
        }
        if (dyArrayGet(heap, pos) > dyArrayGet(heap, smallChild)){
            _swap(heap, pos, smallChild);
            _adjustHeap(heap, max, smallChild);
        }
    }
    else if(leftChild < max){
        if (dyArrayGet(heap, pos) > dyArrayGet(heap, leftChild)){
            _swap(heap, pos, leftChild);
            _adjustHeap(heap, max, leftChild);
        }
    }
}

TYPE heapGetFirst(dyArray* heap){
    return dyArrayGet(heap, 0);
}

TYPE heapRemoveFirst(struct dyArray* heap){
    int last = dyArraySize(heap);
    TYPE r = heapGetFirst(heap);
    assert(last != 0);
    dyArrayPut(heap, 0, dyArrayGet(heap, last-1));
    dyArrayRemoveLast(heap);
    _adjustHeap(heap, last-1, 0);
    return r;
}

void _swapUp(dyArray* heap, int index){
    int parent = (index-1)/2;
    if (dyArrayGet(heap, parent) > dyArrayGet(heap, index)){
        _swap(heap, parent, index);
        _swapUp(heap, parent);
    }
}
void addPQ(dyArray* heap, TYPE newValue){
    addDynArr(heap, newValue);
    _swapUp(heap, dyArraySize(heap)-1);
}


int main(){
    dyArray* pq = initHeap(11);

    addPQ(pq, 16);
    addPQ(pq, 11);
    addPQ(pq, 14);
    addPQ(pq, 12);
    addPQ(pq, 8);
    addPQ(pq, 7);
    addPQ(pq, 10);
    addPQ(pq, 9);
    addPQ(pq, 5);
    addPQ(pq, 3);
    addPQ(pq, 2);

    while(pq->size > 0){
        printf("Removed: %d\n", heapRemoveFirst(pq)); 
    }

    return 0;
}




    /*
    for (int i = 0; i<pq->size; i++){
        printf("%d: %d\n", i, pq->array[i]);
    }
    printf("\n\n");
    */