#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


int main(){
    LinkedList* ml = linkedListCreate();


    addLinkBefore(ml, 3);
    addLinkBefore(ml, 2);
    addLinkBefore(ml, 5);
    addLinkBefore(ml, 4);
    addLinkBefore(ml, 3);

    printLinkedList(ml);
    printf("SIZE: %d\n", sizelinkedList(ml));

    removeLink(ml, 3);

    printLinkedList(ml);

    printf("SIZE: %d\n", sizelinkedList(ml));

}










int mainOLD(int argc, char* argv[])
{


  /* Linked list */
  printf("Testing linked List..\n");
  LinkedList* myList;
  myList = linkedListCreate();
  printf("Size of list: %d\n", sizelinkedList(myList));
  addLinkBefore(myList, 2);
  addLinkBefore(myList, 4);
  addLinkBefore(myList, 5);
  addLinkBefore(myList, 1);
  addLinkBefore(myList, 7);
  printf("Size of list: %d\n", sizelinkedList(myList));
  printLinkedList(myList); 

  removeLink(myList, 10);
  removeLink(myList, 2);
  removeLink(myList, 1);
  printLinkedList(myList);

  deletelinkedList(myList);

  /* Deque */
  printf("Testing deque ..\n");
  Deque* myDeque = dequeCreate();

  printf("Size of deque: %d\n", sizeDeque(myDeque));
  addFrontDeque(myDeque, 3);
  addFrontDeque(myDeque, 6);
  addFrontDeque(myDeque, 9);
  addBackDeque(myDeque, 1);
  addBackDeque(myDeque, 7);
  addBackDeque(myDeque, 8);
  printf("Size of deque: %d\n", sizeDeque(myDeque));
  printDeque(myDeque);
  printf("Front: %d\n", frontDeque(myDeque));
  printf("Back: %d\n", backDeque(myDeque));
  removeFrontDeque(myDeque);
  removeBackDeque(myDeque);
  printDeque(myDeque);
  printf("Size of deque: %d\n", sizeDeque(myDeque));
  removeBackDeque(myDeque);
  removeBackDeque(myDeque);
  removeBackDeque(myDeque);
  printDeque(myDeque);

  deleteDeque(myDeque);

  /* Bag */
  printf("Testing bag ..\n");
  Bag* myBag = bagCreate();
  printf("Size of bag: %d\n", sizeBag(myBag));
  addBag(myBag, 2);
  addBag(myBag, 1);
  addBag(myBag, 3);
  addBag(myBag, 4);
  printBag(myBag);
  printf("%d ", containsBag(myBag, 4));
  printf("%d ", containsBag(myBag, 6));
  printf("%d \n", containsBag(myBag, 1));
  removeBag(myBag, 1);
  removeBag(myBag, 2);
  printBag(myBag);
  
  deleteBag(myBag);

  return 0;
}