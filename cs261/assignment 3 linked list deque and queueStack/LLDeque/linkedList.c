/***********************************************************
* Author: 
* Email: 
* Date Created: 
* Filename: linkedList.c
*
* Overview:
*	This program is a linked list implementation of the deque and bag ADTs. 
*	Note that both implementations utilize a linked list with
*	both a front and back sentinel and double links (links with
*	next and prev pointers).
************************************************************/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

#ifndef FORMAT_SPECIFIER
#define FORMAT_SPECIFIER "%d"
#endif


/* ************************************************************************
	Structs Link and LinkedList
************************************************************************ */

struct LinkedList {
	int size;
	struct Link* head;
	struct Link* tail;
};

struct Link {
	TYPE data;
	struct Link* next;
	struct Link* previous;
};

/* ************************************************************************
	Linked List Functions
************************************************************************ */

// Allocates and initializes a linked list
LinkedList* linkedListCreate()
{
	LinkedList* newList = (LinkedList*) malloc(sizeof(LinkedList));
	assert(newList != NULL);
	newList->size = 0;
	newList->head = NULL;
	newList->tail = NULL;

	return newList;
}

// Deallocates every link in the list
void deletelinkedList(LinkedList* list)
{
	assert(list != NULL);

	if (list->head == NULL && list->tail == NULL) {
		free(list);
		return;
	} 

	Link* temp;

	while(list->head->next != NULL) {
		temp = list->head->next;
		free(list->head);
		list->head = temp;
	}
	free(list->head);
	free(list);
}

// Returns the size of the list
int sizelinkedList(LinkedList* myList)
{
	assert(myList != NULL);
	return myList->size;
}					

// Returns 1 if the list is empty and 0 otherwise
int isEmptyLinkedList(LinkedList* myList)
{
	assert(myList != NULL);
	if (myList->size == 0) {
		return 1;
	}
	return 0;
}

/* Create a new link and allocate memory for it */
Link* _createNewLink(TYPE value)
{
	Link* newLink = (Link*) malloc(sizeof(Link));
	assert(newLink != NULL);
	newLink->data = value;
	newLink->next = NULL;
	newLink->previous = NULL;

	return newLink;
}

// Adds a new link with the given value before the given link and increments the list's size
void addLinkBefore(LinkedList* list, TYPE value)
{
	assert(list != NULL);
	Link* newLink = _createNewLink(value);
	/* If the list is empty */
	if (isEmptyLinkedList(list)) {
		list->head = newLink;
		list->tail = newLink;
	} else {
		Link* iterator = NULL;
		iterator = list->head;

		list->head = newLink;
		newLink->next = iterator;
		iterator->previous = newLink;
	}
	list->size++;
}

// Removes the given link from the list and decrements the list's size
void removeLinkOLD(LinkedList* list, TYPE value) 
{
	assert(list != NULL);
	Link* iterator = NULL;
	iterator = list->head;

	/* If the list is not empty*/
	if (list->head != NULL && list->tail != NULL) {
		/* Check if there is only one element in the list */
		if (list->head == list->tail) {
			list->head = NULL;
			list->tail = NULL;
			free(iterator);
		} else {
			/* Removing the first element (Remove from beginning) */
			if (list->head->data == value)
			{
				Link* nodeToRemove = iterator;
				list->head = nodeToRemove->next;
				nodeToRemove->previous = NULL;

				free(nodeToRemove);
				list->size--;
			} else if (list->tail->data == value) {
				/* Removing the last element (Remove from the end) */
				Link* nodeToRemove = list->tail;
				list->tail = nodeToRemove->previous;
				list->tail->next = NULL;

				free(nodeToRemove);
				list->size--;
			} else {
				/* Loop until we find the link with the value we want to remove (Remove in between) */
				while (iterator) {
					if (iterator->data == value) {
						Link* nodeToRemove = iterator;
						nodeToRemove->previous->next = nodeToRemove->next;
						nodeToRemove->next->previous = nodeToRemove->previous;			
						free(nodeToRemove);
						list->size--;
					}
					iterator = iterator->next;
				}
			}
		}	
		//list->size--;
	} else {
		printf("The link is empty.\n");
	}
}



	

// Prints the values of the links in the list from front to back
void printLinkedList(LinkedList* list)
{
	assert(list != NULL);
	Link* iterator = list->head;

	if (isEmptyLinkedList(list)) {
		printf("The list is empty.\n");
	} else {
		while (iterator) {
			printf("%d ", iterator->data);
			iterator = iterator->next;
		}
		printf("\n");
	}
}								

/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Allocates and initializes the deque */
Deque* dequeCreate()
{
	Deque* newDeque = linkedListCreate();

	return newDeque;
}

/* Deallocates the data and deletes the deque */
void deleteDeque(Deque* myDeque)
{
	deletelinkedList(myDeque);
}

/* Returns the size of the deque */
int sizeDeque(Deque* myDeque)
{
	assert(myDeque != NULL);
	return myDeque->size;
}

/* Returns 1 if the deque is empty and 0 otherwise */
int isEmptyDeque(Deque* myDeque)
{
	assert(myDeque != NULL);
	return isEmptyLinkedList(myDeque);
}

/* Adds a new link with the given value to the front of the deque */
void addFrontDeque(Deque* myDeque, TYPE value)
{
	addLinkBefore(myDeque, value);
}

/* Adds a new link with the given value to the back of the deque */
void addBackDeque(Deque* myDeque, TYPE value)
{
	assert(myDeque != NULL);
	Link* newLink = _createNewLink(value);
	Link* iterator = NULL;
	iterator = myDeque->tail;

	newLink->previous = iterator;
	iterator->next = newLink;
	myDeque->tail = newLink;

	myDeque->size++;
}

/* Returns the value of the link at the front of the deque */
TYPE frontDeque(Deque* myDeque)
{
	assert(myDeque != NULL);
	return myDeque->head->data;
}

/* Returns the value of the link at the back of the deque */
TYPE backDeque(Deque* myDeque)
{
	assert(myDeque != NULL);
	return myDeque->tail->data;
}

/* Removes the link at the front of the deque */
void removeFrontDeque(Deque* myDeque)
{
	assert(myDeque != NULL);
	TYPE frontLinkValue = myDeque->head->data;

	removeLink(myDeque, frontLinkValue);
}

/* Removes the link at the back of the deque */
void removeBackDeque(Deque* myDeque)
{
	assert(myDeque != NULL);
	TYPE lastLinkValue = myDeque->tail->data;
	
	removeLink(myDeque, lastLinkValue);
}

/* Prints the values of the links in the deque from front to back */
void printDeque(Deque* myDeque)
{
	printLinkedList(myDeque);
}

/* ************************************************************************
	Bag Functions
************************************************************************ */

/* Allocates and initializes the bag */
Bag* bagCreate()
{
	Bag* newBag = linkedListCreate();

	return newBag;
}

/* Deallocates the data and deletes the bag */
void deleteBag(Bag* myBag)
{
	deletelinkedList(myBag);
}

/* Returns the size of the bag */
int sizeBag(Bag* myBag)
{
	assert(myBag != NULL);
	return myBag->size;
}

/* Returns "1" if the bag is empty or "0" if not */
int isBagEmpty(Bag* myBag)
{
	assert(myBag != NULL);
	return isEmptyLinkedList(myBag);
}

/* Adds an element into the bag */
void addBag(Bag* myBag, TYPE value)
{
	addLinkBefore(myBag, value);
}

/* Returns "1" if the bag contains the specified element or "0" if not */
int containsBag(Bag* myBag, TYPE value)
{
	Link* iterator = NULL;
	iterator = myBag->head;

	while (iterator) {
		if (iterator->data == value)
		{
			return 1;
		}
		iterator = iterator->next;
	}
	return 0;
}

/* Removes the specific element from the bag */
void removeBag(Bag* myBag, TYPE value)
{
	removeLink(myBag, value);
} 

/* Prints the values of the links in the bag from front to back */
void printBag(Bag* myBag)
{
	printLinkedList(myBag);
}



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
