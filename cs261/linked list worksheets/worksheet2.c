#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#ifndef TYPE						
# define TYPE      int				
# define TYPE_SIZE sizeof(TYPE)
#endif

struct link{
    TYPE value;
    struct link* next;
};

struct listQueue{
    struct link* firstLink;
    struct link* lastLink;
};

void listQueueInit (struct listQueue *q){
    struct link *lnk = (struct link*)malloc(sizeof(struct link));
    assert(lnk != 0);
    lnk->next = 0;
    q->firstLink = q->lastLink = lnk;
}

void listQueueAddBack(struct listQueue* q, TYPE e){
    struct link* newLink = (struct link*)malloc(sizeof(struct link));
    assert(newLink != NULL);
    newLink->value = e;
    newLink->next = NULL;
    q->lastLink->next = newLink;
    q->lastLink = newLink;
}

TYPE listQueueFront(struct listQueue* q){
    assert(q->lastLink != q->firstLink);
    return q->firstLink->next->value;
}

void listQueueRemoveFront(struct listQueue* q){
    assert(q->lastLink != q->firstLink);
    struct link* tmpPtr = q->firstLink->next;
    if (tmpPtr == q->lastLink){ 
        q->lastLink = q->firstLink;
        q->firstLink->next = NULL;
    }
    else{
        q->firstLink->next = q->firstLink->next->next;
    }
    free(tmpPtr);
}

int listQueueIsEmpty(struct listQueue* q){
    if (q->firstLink == q->lastLink){
        return 1;
    }
    return 0;
}

/*
void printList(struct listQueue* q){
    struct link* tmpPtr = q->firstLink->next;
    while(tmpPtr != NULL){
        printf("%d\n", tmpPtr->value);
        tmpPtr = tmpPtr->next;
    }
}

int main(){
    struct listQueue list;
    struct listQueue* myList = &list;
    listQueueInit(myList);
    listQueueAddBack(myList, 2);
    listQueueAddBack(myList, 3);
    listQueueAddBack(myList, 4);
    listQueueAddBack(myList, 5);

    printList(myList);

    listQueueRemoveFront(myList);
    listQueueRemoveFront(myList);
    listQueueRemoveFront(myList);
    listQueueRemoveFront(myList);

    printf("%d\n", listQueueIsEmpty(myList));
    listQueueAddBack(myList, 12);
    printf("%d\n", listQueueIsEmpty(myList));

    printf("\n");
    printList(myList);



    return 0;
}
*/



