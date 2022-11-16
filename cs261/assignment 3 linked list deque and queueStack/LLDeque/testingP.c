#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(){
    LinkedList* ml = linkedListCreate();
    addLinkBefore(ml, 3);
    addLinkBefore(ml, 4);
    addLinkBefore(ml, 5);
    addLinkBefore(ml, 6);
    addLinkBefore(ml, 3);

    printLinkedList(ml);

    removeLink(ml, 4);

    printLinkedList(ml);








    return 0;
}