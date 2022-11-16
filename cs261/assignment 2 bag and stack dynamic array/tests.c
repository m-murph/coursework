/* tests.c
   This file is used for testing the dynamic array, the stack and the bag implementations. 
   This test suite is by no means complete or thorough.
   More testing is needed on your own, and more tests will be performed by the TA.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "DA_Stack_Bag.h"

void assertTrue(int predicate, char *message) 
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}
int main(int argc, char* argv[])
{

	DynArr *myDA;
	myDA = newDynArr(2);

/* ************************************************************************
	Dynamic Array Tests
************************************************************************ */

	printf("\n\nTesting addDynArr...\n");
	addDynArr(myDA, 3);
	addDynArr(myDA, 4);
	addDynArr(myDA, 10);
	addDynArr(myDA, 5);
	addDynArr(myDA, 6);
	
	printf("The array's content: [3,4,10,5,6]\n");
	assertTrue(EQ(getDynArr(myDA, 0), 3), "Test 1st element == 3");
	assertTrue(EQ(getDynArr(myDA, 1), 4), "Test 2nd element == 4");
	assertTrue(EQ(getDynArr(myDA, 2), 10), "Test 3rd element == 10");
	assertTrue(EQ(getDynArr(myDA, 3), 5), "Test 4th element == 5");
	assertTrue(EQ(getDynArr(myDA, 4), 6), "Test 5th element == 6");
	assertTrue(sizeDynArr(myDA) == 5, "Test size = 5");
	
	printf("\n\nTesting putDynArr...\nCalling putDynArr(myDA, 2, 7)\n");
	putDynArr(myDA, 2, 7); 
	printf("The array's content: [3,4,7,5,6]\n");
	assertTrue(EQ(getDynArr(myDA, 2), 7), "Test 3rd element == 7");
	assertTrue(sizeDynArr(myDA) == 5, "Test size = 5");
	
	printf("\n\nTesting swapDynArr...\nCalling swapDynArr(myDA, 2, 4)\n");
	swapDynArr(myDA, 2, 4);
	printf("The array's content: [3,4,6,5,7]\n");
	assertTrue(EQ(getDynArr(myDA, 2), 6), "Test 3rd element == 6");
	assertTrue(EQ(getDynArr(myDA, 4), 7), "Test 5th element == 7");
	
	printf("\n\nTesting removeAtDynArr...\nCalling removeAtDynArr(myDA, 1)\n");
	removeAtDynArr(myDA, 1);
	printf("The array's content: [3,6,5,7]\n");
	assertTrue(EQ(getDynArr(myDA, 0), 3), "Test 1st element == 3");
	assertTrue(EQ(getDynArr(myDA, 3), 7), "Test 4th element == 7");
	assertTrue(sizeDynArr(myDA) == 4, "Test size = 4");
	
	deleteDynArr(myDA);
	
/* ************************************************************************
	Stack Tests
************************************************************************ */
	
	Stack *myStack;
	myStack = newStack(2);
	
	printf("\n\nTesting stack interface...\n");
	pushStack(myStack, 3);
	pushStack(myStack, 6);
	pushStack(myStack, 5);
	pushStack(myStack, 7);
	printf("The stack's content: [3,6,5,7] <- top\n");
	assertTrue(!isStackEmpty(myStack), "Testing isStackEmpty");
	assertTrue(sizeStack(myStack) == 4, "Test size = 4");
	assertTrue(EQ(topStack(myStack), 7), "Test topStack == 7");
	
	popStack(myStack);
	printf("Poping...\nThe stack's content: [3,6,5] <- top\n");
	assertTrue(sizeStack(myStack) == 3, "Test size = 3");
	assertTrue(EQ(topStack(myStack), 5), "Test topStack == 5");
	
	pushStack(myStack, 9);
	printf("Pushing 9...\nThe stack's content: [3,6,5,9] <- top\n");
	assertTrue(sizeStack(myStack) == 4, "Test size = 4");
	assertTrue(EQ(topStack(myStack), 9), "Test topStack == 9");
	
	deleteStack(myStack);
	
/* ************************************************************************
	Bag Tests
************************************************************************ */
	
	Bag *myBag;
	myBag = newBag(2);
	
	printf("\n\nTesting bag interface...\n");
	addBag(myBag, 3);
	addBag(myBag, 6);
	addBag(myBag, 5);
	addBag(myBag, 9);
	printf("The bag's content: [3,6,5,9]\n");
	assertTrue(!isBagEmpty(myBag), "Testing isBagEmpty");
	assertTrue(sizeBag(myBag) == 4, "Test size = 4");
	assertTrue(containsBag(myBag, 3), "Test containing 3");
	assertTrue(containsBag(myBag, 6), "Test containing 6");
	assertTrue(containsBag(myBag, 5), "Test containing 5");
	assertTrue(containsBag(myBag, 9), "Test containing 9");
	assertTrue(!containsBag(myBag, 7), "Test not containing 7");
	
	removeBag(myBag, 3);
	printf("Removing 3...\nThe bag's content: [6,5,9]\n");
 	assertTrue(!containsBag(myBag, 3), "Test not containing 3");
	
    deleteBag(myBag);

	Bag* bag2 = newBag(5);
	addBag(bag2, 4);
	addBag(bag2, 4);
	addBag(bag2, 4);
	addBag(bag2, 4);
	addBag(bag2, 5);

	for (int i = 0; i<sizeBag(bag2); i++){
		printf("%d\n", getDynArr(bag2, i));
	}
	printf("\n");
	removeBag(bag2, 4);
	for (int i = 0; i<sizeBag(bag2); i++){
		printf("%d\n", getDynArr(bag2, i));
	}
	printf("%d\n", sizeBag(bag2));
	deleteBag(bag2);

	
	int i = 5;
	int* iptr = &i;
	free(iptr);
	
	
	//Bag bag3 
	//bag3.size = 1;
	return 0;
}