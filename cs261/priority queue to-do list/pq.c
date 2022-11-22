/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name:
 * Email: 
 */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "dynarray.h"
#include "pq.h"

/*
 * This is the structure that represents a priority queue
 */

struct pq
{ 
  struct dynarray* dyn_array;
};


/*
* Struct to store the elements of the priority queue
*/

typedef struct node
{
  void* value;
  int priority;

}node;

void _swap(struct pq* queue, int id1, int id2){
  void* tmp = dynarray_get(queue->dyn_array, id1);
  dynarray_set(queue->dyn_array, id1, dynarray_get(queue->dyn_array, id2));
  dynarray_set(queue->dyn_array, id2, tmp);
}

/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */

pq* createPq()
{
  struct pq* new_queue = (struct pq*)malloc(sizeof(struct pq));
  assert(new_queue != NULL);
  new_queue->dyn_array = dynarray_create();
  return new_queue;
}


/*
 * This function should free the memory allocated to a given priority queue
 */

void freePq(pq* myPq)
{
  // FIXME
  if(myPq == NULL){
    return;
  }

  int k = dynarray_size(myPq->dyn_array);
  for (int i = 0; i<k; i++){
    free(((node*)dynarray_get(myPq->dyn_array, i))->value);
    free(((node*)dynarray_get(myPq->dyn_array, i)));
  }

  dynarray_free(myPq->dyn_array);
  free(myPq);
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 */

int isemptyPq(pq* myPq)
{
	
  if (dynarray_size(myPq->dyn_array) == 0){
    return 1;
  }
  return 0;
	
}


/*
 * This function should add a given element into a priority queue with a
 * specified priority value.
 */

void _swapUp(struct pq* heap, int index){
    int parent = (index-1)/2;
    if (((node*)dynarray_get(heap->dyn_array, parent))->priority > ((node*)dynarray_get(heap->dyn_array, index))->priority){
        _swap(heap, parent, index);
        _swapUp(heap, parent);
    }
}
void addPq(struct pq* myPq, void* value, int priority)
{
  node* newNode = (node*)malloc(sizeof(node));
  assert(newNode != NULL);
  newNode->priority = priority;
  newNode->value = value;
	dynarray_insert(myPq->dyn_array, newNode);
  _swapUp(myPq, dynarray_size(myPq->dyn_array)-1);
}


/*
 * This function should return the value of the item with lowest priority
 *
 */

void* getPq(pq* myPq)
{
  //FIXME
  if (dynarray_size(myPq->dyn_array) > 0){
    return ((node*)dynarray_get(myPq->dyn_array, 0))->value;
  }
  else{
    return NULL;
  } 
}


void _adjustHeap(struct pq* heap, int max, int pos){
    int leftChild = 2*pos + 1;
    int rightChild = 2*pos + 2;
    int smallChild;
    if (rightChild <= max){
        if (((node*)dynarray_get(heap->dyn_array, leftChild))->priority < ((node*)dynarray_get(heap->dyn_array, rightChild))->priority){
            smallChild = leftChild;
        }
        else{
            smallChild = rightChild;
        }
        if (((node*)dynarray_get(heap->dyn_array, pos))->priority > ((node*)dynarray_get(heap->dyn_array, smallChild))->priority){
            _swap(heap, pos, smallChild);
            _adjustHeap(heap, max, smallChild);
        }
    }
    else if(leftChild < max){
        if (((node*)dynarray_get(heap->dyn_array, pos))->priority > ((node*)dynarray_get(heap->dyn_array, leftChild))->priority){
            _swap(heap, pos, leftChild);
            _adjustHeap(heap, max, leftChild);
        }
    }
}

/*
 * This function should remove the value with lowest priority 
 */

void removePq(struct pq* myPq)
{
    int last = dynarray_size(myPq->dyn_array);
    if (last == 0){
      return;
    }
    node* tmp = ((node*)dynarray_get(myPq->dyn_array, 0));
    dynarray_set(myPq->dyn_array, 0, dynarray_get(myPq->dyn_array, last-1));
    dynarray_remove(myPq->dyn_array, last-1);
    _adjustHeap(myPq, last-1, 0);

    free(tmp->value);
    free(tmp);
}


/*
 * This function should print the values that are in the pq
 * and their priorities on the screen
 * from the queue.
 */

void printPq(struct pq* myPq)
{
  // FIXME

  
  for (int i = 0; i<dynarray_size(myPq->dyn_array); i++){
    printf("%s", (char*)(((node*)dynarray_get(myPq->dyn_array, i))->value));
    printf(", Priority: %d\n", ((node*)dynarray_get(myPq->dyn_array, i))->priority);
  }
  

  /*
  if (dynarray_size(myPq->dyn_array) == 0){
    printf("The to-do list is empty!\n");
    return;
  }
  struct pq* printP = createPq();

  for (int i = 0; i<dynarray_size(myPq->dyn_array); i++){
    node* tmpNode = (node*)dynarray_get(myPq->dyn_array, i);
    addPq(printP, tmpNode->value, tmpNode->priority); 
  }

  int k = 0;
  while (dynarray_size(printP->dyn_array) > 0){
    node* current = (node*)getPq(printP);
    char* message = (char*)current->value;
    printf("To-do: ");

    for (int i = 0; i<sizeof(message); i++){
      printf("ksdikhgshgs\n");
      printf("%s\n", message);
    }
    
    printf(", Priority: %d\n", current->priority);
    removePq(printP);
    k++;

  }
  */
}