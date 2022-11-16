#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define TYPE int

struct dlink{
    TYPE value;
    struct dlink* next;
    struct dlink* prev;
};

struct linkedList{
    int size;
    struct dlink* frontSentinel;
    struct dlink* backSentinel;
};

void linkedListInit(struct linkedList* q){
    q->frontSentinel = (struct dlink *) malloc(sizeof(struct dlink));
    assert(q->frontSentinel != 0);
    q->backSentinel = (struct dlink *) malloc(sizeof(struct dlink));
    assert(q->backSentinel); 
    q->frontSentinel->next = q->backSentinel; 
    q->backSentinel->prev = q->frontSentinel;
    q->size = 0; 
}

/* _addLink places a new link BEFORE the provide link, lnk */
void _addLink(struct linkedList *q, struct dlink *lnk, TYPE e){
    struct dlink* nl = (struct dlink *) malloc(sizeof(struct dlink));
    nl->value = e;
    lnk->prev->next = nl;
    nl->prev = lnk->prev;
    nl->next = lnk;
    lnk->prev = nl;
    q->size++;
}

void _removeLink(struct linkedList* q, struct dlink *lnk){
    assert(q != NULL && lnk != NULL);
    lnk->prev->next = lnk->next;
    lnk->next->prev = lnk->prev;
    q->size--;
    free(lnk);
}

TYPE LinkedListFront(struct linkedList* q){
    assert(q->frontSentinel->next != q->backSentinel);
    return q->frontSentinel->next->value;
}

TYPE LinkedListBack(struct linkedList *q){
    assert(q->frontSentinel->next != q->backSentinel);
    return q->backSentinel->prev->value;
}

void LinkedListAddFront (struct linkedList *q, TYPE e){
    _addLink(q, q->frontSentinel->next, e); 
} 

void LinkedListAddback (struct linkedList *q, TYPE e){
    _addLink(q, q->backSentinel, e);
}

int linkedListIsEmpty (struct linkedList *q) {    
    return q->size == 0; 
}

void linkedListRemoveFront (struct linkedList *q) {    
    assert(! linkedListIsEmpty(q));    
    _removeLink(q, q->frontSentinel->next); 
}

void LinkedListRemoveBack (struct linkedList *q) {    
    assert(! linkedListIsEmpty(q));    
    _removeLink(q, q->backSentinel->prev); 
}

void linkedListFree(struct linkedList* q){
    while (q->size > 0){
        linkedListRemoveFront(q);
    }
    free (q->frontSentinel);
    free (q->backSentinel);
    q->frontSentinel = q->backSentinel = NULL;
}

/* print is for debug only */
void printList(struct linkedList* l){
    struct dlink* tmpLink = l->frontSentinel->next;
    while(tmpLink != l->backSentinel){
        printf("%d\n", tmpLink->value);
        tmpLink = tmpLink->next;
    }
    printf("\n");
}


int main(){
    struct linkedList* ml = (struct linkedList*)malloc(sizeof(struct linkedList));
    linkedListInit(ml);

    LinkedListAddFront(ml, 1);
    LinkedListAddFront(ml, 2);
    LinkedListAddFront(ml, 3);
    LinkedListAddFront(ml, 4);
    printList(ml);

    printf("%d\n", LinkedListFront(ml));
    printf("%d\n", LinkedListBack(ml));

    linkedListFree(ml);
    free(ml);
    return 0;
}

