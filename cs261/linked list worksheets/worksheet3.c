#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#ifndef TYPE						
# define TYPE      int				
# define TYPE_SIZE sizeof(TYPE)
#endif



struct dLink{
    TYPE value;
    struct dLink* next;
    struct dLink* prev;
};

struct LinkedList{
    struct dLink* frontSentinel;
    struct dLink* backSentinel;
    int count;
};

void linkedListInit(struct LinkedList* lst){
    struct dLink* fSen = (struct dLink*)malloc(sizeof(struct dLink));
    struct dLink* bSen = (struct dLink*)malloc(sizeof(struct dLink));
    assert(fSen != NULL && bSen != NULL);

    lst->count = 0;
    lst->frontSentinel = fSen;
    lst->backSentinel = bSen;

    lst->frontSentinel->next = bSen;
    lst->frontSentinel->prev = NULL;

    lst->backSentinel->prev = fSen;
    lst->backSentinel->next = NULL;
}

void _addLink(struct LinkedList* lst, struct dLink* lnk, TYPE e){
    //adds to front of the bag
    struct dLink* newLink = (struct dLink*)malloc(sizeof(struct dLink));
    newLink->value = e;
    newLink->next = lnk;
    newLink->prev = lst->frontSentinel;
    lst->frontSentinel->next = newLink;
    lnk->prev = newLink;
    lst->count++;
}

void _removeLink(struct LinkedList* lst, struct dLink* lnk){
    lnk->prev->next = lnk->next;
    lnk->next->prev = lnk->prev;
    lst->count--;
    free(lnk);
}

void linkedListFree(struct LinkedList* lst){
    struct dLink* nextLink;
    nextLink = lst->frontSentinel->next;

    while (nextLink != NULL){
        free(nextLink->prev);
        nextLink = nextLink->next;
    }
    free(lst->backSentinel);
}

void linkedListAdd(struct LinkedList* lst, TYPE e){
    _addLink(lst, lst->frontSentinel->next, e);
}

int linkedListContains(struct LinkedList* lst, TYPE e){
    struct dLink* lptr = lst->frontSentinel->next;
    while(lptr != lst->backSentinel){
        if (lptr->value == e){
            return 1;
        }
        lptr = lptr->next;
    }
    return 0;
}

void linkedListRemove(struct LinkedList* lst, TYPE e){
    struct dLink* lptr = lst->frontSentinel->next;
    struct dLink* tmpPtr;
    while(lptr != lst->backSentinel){
        if(lptr->value == e){
            tmpPtr = lptr->next;
            _removeLink(lst, lptr);
            lptr = tmpPtr;
        }
        else{
            lptr = lptr->next;
        } 
    }
}


/*
void printLinkedList(struct LinkedList* lst){
    struct dLink* lptr = lst->frontSentinel->next;
    while(lptr != lst->backSentinel){
        printf("%d\n", lptr->value);
        lptr = lptr->next;
    } 
    printf("\n");   
}

int main(){
    struct LinkedList l;
    struct LinkedList* list = &l;
    linkedListInit(list);

    linkedListAdd(list, 1);
    linkedListAdd(list, 2);
    linkedListAdd(list, 3);
    linkedListAdd(list, 4);
    linkedListAdd(list, 5);

    printLinkedList(list);

    linkedListRemove(list, 5);
 

    printLinkedList(list);

    printf("Size: %d\n", list->count);

    linkedListFree(list);



    return 0;

}
*/







