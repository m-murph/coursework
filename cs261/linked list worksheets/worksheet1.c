#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct link{
    int value;
    struct link* next;
};

struct linkedListStack{
    struct link* firstLink;
};

void linnkedListStackInit(struct linkedListStack* s){
    assert(s != NULL);
    s->firstLink = NULL;
}

struct link* _newLink(int v, struct link* n){
    struct link* lnk = (struct link*)malloc(sizeof(struct link));
    assert(lnk != NULL);
    lnk->value = v;
    lnk->next = n;
    return lnk;
}

void linkedListStackPush(struct linkedListStack* s, int d){
    assert(s != NULL);
    s->firstLink = _newLink(d, s->firstLink);
}

int linkedListStackTop(struct linkedListStack* s){
    assert(s != NULL && s->firstLink != NULL);
    return s->firstLink->value;
}

void linkedListStackPop(struct linkedListStack* s){
    assert(s != NULL && s->firstLink != NULL);
    struct link* d = s->firstLink;
    if (s->firstLink->next != NULL){
        s->firstLink = s->firstLink->next;
    }
    else{
        s->firstLink = NULL;
    }
    free(d);
}

int linkedListStackIsEmpty(struct linkedListStack* s){
    assert(s != NULL);
    if (s->firstLink == NULL){
        return 1;
    }
    return 0;
}

void linkedListStackFree(struct linkedListStack* s){
    assert(s != NULL);
    while(!linkedListStackIsEmpty(s)){
        linkedListStackPop(s);
    }
}

/*
void printLL(struct linkedListStack* s){
    struct link* tmpLink = s->firstLink;
    while (tmpLink != NULL){
        printf("%d\n", tmpLink->value);
        tmpLink = tmpLink->next;
    }
}

int main(){
    struct linkedListStack myList;

    struct linkedListStack* myListP = &myList;

    linnkedListStackInit(myListP);

    linkedListStackPush(myListP, 4);
    //linkedListStackPush(myListP, 5);
    //linkedListStackPush(myListP, 6);

    printf("%d\n", linkedListStackTop(myListP));

    linkedListStackPop(myListP);

    printf("%d\n", linkedListStackIsEmpty(myListP));

    linkedListStackFree(myListP);
    return 0;
}
*/
