#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "bst.h"
#include "structs.h"

struct Node
{
	TYPE         value;
	struct Node* left;
	struct Node* right;
};

struct BSTree
{
	struct Node* root;
	int          count;
};


int compare(TYPE left, TYPE right)
{
   if (((struct data*)left)->number > ((struct data*)right)->number){
      return 1;
   }
   else if (((struct data*)left)->number < ((struct data*)right)->number){
      return -1;
   }
	return 0;
}

void print_type(TYPE value)
{
   printf("%d\n", ((struct data*)(value))->number);
}







/*----------------------------------------------------------------------------*/
//BINARY SEARCH TREE FUNCTIONS GO HERE
/*----------------------------------------------------------------------------*/

struct BSTree* newBSTree()						// Allocates and initializes the BST
{
	/*write this*/
    BSTree* newTree = (BSTree*)malloc(sizeof(BSTree));
    newTree->root = NULL;
    newTree->count = 0;
	return newTree;
}


void _deleteBSTree(struct Node* myTree){
    if (myTree->left != NULL){
        _deleteBSTree(myTree->left);
    }
    if (myTree->right != NULL){
        _deleteBSTree(myTree->right);
    }
    free(myTree);
}
void deleteBSTree(BSTree* myTree)				// Deallocate nodes in BST and deallocate the BST structure
{
	/*write this*/
    if (myTree->root != NULL){
        _deleteBSTree(myTree->root);
    }
    free(myTree);
}



int isEmptyBSTree(BSTree* myTree)				// Returns "1" if the BST is empty or "0" if not 
{
	/*write this*/
    if (myTree->count == 0){
        return 1;
    }
    return 0;
}


int sizeBBSTree(BSTree* myTree)				// Returns the size of the BST
{
	/*write this*/
    return myTree->count;
}



void _addBSTree(struct Node* myTree, TYPE value){
    //if (compare(myTree->value, value) == -1)
    //if (myTree->value->number < value && myTree->right)
    if (myTree->right != NULL && (compare(myTree->value, value) == -1 || compare(myTree->value, value) == 0)){
        _addBSTree(myTree->right, value);
    }
    else if (myTree->left != NULL && compare(myTree->value, value) == 1){
        _addBSTree(myTree->left, value);
    }
    else if (myTree->left == NULL && compare(myTree->value, value) == 1){
        struct Node* newLeaf = (struct Node*)malloc(sizeof(struct Node));
        newLeaf->value = value;
        newLeaf->left = NULL;
        newLeaf->right = NULL;
        myTree->left = newLeaf;
        return;
    }
    else{
        struct Node* newLeaf = (struct Node*)malloc(sizeof(struct Node));
        newLeaf->value = value;
        newLeaf->left = NULL;
        newLeaf->right = NULL;
        myTree->right = newLeaf;
        return;
    }
}
void addBSTree(BSTree* myTree, TYPE value)		// Adds an element into the BST
{
	/*write this*/
    if (myTree->root != NULL){
        _addBSTree(myTree->root, value);
    }
    else{
        myTree->root = (struct Node*)malloc(sizeof(struct Node));
        myTree->root->left = NULL;
        myTree->root->right = NULL;
        myTree->root->value = value;
    }
    myTree->count++;	
}




int _containsBSTree(struct Node* myTree, TYPE value){
    if (compare(myTree->value, value) == 0){
        return 1;
    }
    
    if (((compare(myTree->value, value) == -1) || compare(myTree->value, value) == 0) && myTree->right != NULL){
        return _containsBSTree(myTree->right, value);
    }
    else if (myTree->left != NULL && compare(myTree->value, value) == 1){
        return _containsBSTree(myTree->left, value);
    }
    else{
        return 0;
    }
}
int containsBSTree(BSTree* myTree, TYPE value)	// Returns "1" if the BST contains the specified element or "0" if not
{
	/*write this*/
    return _containsBSTree(myTree->root, value);	
}




TYPE _minBSTree(struct Node* myTree){
    if (myTree->left == NULL){
        return myTree->value;
    }
    return _minBSTree(myTree->left);
}
TYPE minBSTree(BSTree* myTree)					// Returns the minimum value in the BST 
{
	/*write this*/
    return _minBSTree(myTree->root);	
}




TYPE _maxBSTree(struct Node* myTree){
    if (myTree->right == NULL){
        return myTree->value;
    }
    return _minBSTree(myTree->right);
}
TYPE maxBSTree(BSTree* myTree)					// Returns the maximum value in the BST  
{
	/*write this*/
    return _maxBSTree(myTree->root);
}



//can be replaced with left most child in rigth subtree, or right most child in the left subtree

void _removeNode(struct Node* myTree){
    if (myTree->right != NULL){
        struct Node* tmpNode = myTree->right;
        struct Node* trailer = myTree->right;
        while (tmpNode->left != NULL){
            tmpNode = tmpNode->left;
            if (tmpNode->left != NULL){
                trailer = trailer->left;
            }
        }
        myTree->value = tmpNode->value;
        if (tmpNode->right != NULL){
            struct Node* oldNode = tmpNode->right;
            tmpNode->value = tmpNode->right->value;
            tmpNode->left = tmpNode->right->left;
            tmpNode->right = tmpNode->right->right;
            free(oldNode);
        }
        else{
            if (myTree->right == tmpNode){
                myTree->right = NULL;
            }
            else{
                trailer->left = NULL;
            }
            free(tmpNode);

        } 
    }
    else if(myTree->left != NULL){
        struct Node* oldNode = myTree->left;
        myTree->value = myTree->left->value;
        myTree->right = myTree->left->right;
        myTree->left = myTree->left->left;
        free(oldNode);
    }
}
void _removeBSTree(struct Node* myTree, TYPE value){
    if (myTree->left != NULL && myTree->left->left == NULL && myTree->left->right == NULL && compare(myTree->left->value, value) == 0){
        free(myTree->left);
        myTree->left = NULL;
        return;
    }
    else if(myTree->right != NULL && myTree->right->left == NULL && myTree->right->right == NULL && compare(myTree->right->value, value) == 0){
        free(myTree->right);
        myTree->right = NULL;
        return;
    }
    else if(compare(myTree->value, value) == 0){
        _removeNode(myTree);
        return;
    }

    if (compare(myTree->value, value) == -1 && myTree->right != NULL){
        _removeBSTree(myTree->right, value);
    }
    else if (myTree->left != NULL && compare(myTree->value, value) == 1){
        _removeBSTree(myTree->left, value);
    }
}
void removeBSTree(BSTree *tree, TYPE value){
    if (containsBSTree(tree, value) == 0){
        printf("Error: the tree does not contain that value.");
    }
    else if(tree->count == 1){
        free(tree->root);
        tree->root = NULL;
        tree->count--;
    }
    else{
        _removeBSTree(tree->root, value);
        tree->count--;
    }
}




void _printBSTree(struct Node* myTree){
    //i guess it works
    print_type(myTree->value);
    if (myTree->left == NULL && myTree->right == NULL){
        return;
    }
    if (myTree->left != NULL && myTree->right != NULL){
        _printBSTree(myTree->left);
        _printBSTree(myTree->right);
    }
    else if(myTree->right == NULL && myTree->left != NULL){
        _printBSTree(myTree->left);
    }
    else{
        _printBSTree(myTree->right);
    }
}
void printBSTree(BSTree* myTree)				// Prints the values in the BST.
{
	/*write this*/
    if (myTree->count > 0){
        //printf("NEW ROOT: ");
        //print_type(myTree->root->value);
        _printBSTree(myTree->root);
    }
    else{
        printf("The tree is empty.\n");
    }
}






/*----------------------------------------------------------------------------*/

// Test value stuff -----

struct TestValues
{
    struct data* values;
    int n;
};

void initValue(struct data* value, int number, const char* name)
{
    value->number = number;
    value->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(value->name, name);
}

void freeValue(struct data* value)
{
    free(value->name);
}

struct TestValues* createValues()
{
    struct TestValues* values = malloc(sizeof(struct TestValues));
    values->n = 7;
    values->values = malloc(values->n * sizeof(struct data));
    
    initValue(&(values->values[0]), 5, "rooty");
    initValue(&(values->values[1]), 9, "lefty");
    initValue(&(values->values[2]), 6, "righty");
    initValue(&(values->values[3]), 7, "lefty of lefty");
    initValue(&(values->values[4]), 2, "lefty of lefty");
    initValue(&(values->values[5]), 3, "lefty of lefty");
    initValue(&(values->values[6]), 1, "lefty of lefty");
    
    return values;
}

void destroyValues(struct TestValues* values)
{
    for (int i = 0; i < values->n; ++i)
    {
        freeValue(&(values->values[i]));
    }
    free(values->values);
    free(values);
}

// -----

void printTestResult(int predicate, char *nameTestFunction, char 
*message){
    if (predicate)
        printf("%s(): PASS %s\n",nameTestFunction, message);
    else
        printf("%s(): FAIL %s\n",nameTestFunction, message);        
}

/**
 * Tests adding 4 nodes to the BST.
 */
void testAddNode()
{
    struct TestValues* tv = createValues();
    struct BSTree *tree	= newBSTree();
    
    // Add all values to the tree
    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
        if (tree->count != i + 1)
        {
            printf("addNode() test: FAIL to increase count when inserting\n");
            return;
        }
    }
    
    // Check that root node is rooty
    if (tree->root->value != &(tv->values[0]))
    {
        printf("addNode() test: FAIL to insert 50 as root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 50 as root\n");
    }
    
    if (tree->root->left->value != &(tv->values[1]))
    {
        printf("addNode() test: FAIL to insert 13 as left child of root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 13 as left of root\n");
    }
    
    if (tree->root->right->value != &(tv->values[2]))
    {
        printf("addNode() test: FAIL to insert 110 as right child of root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 110 as right of root\n");
    }
    
    if (tree->root->left->left->value != &(tv->values[3]))
    {
        printf("addNode() test: FAIL to insert 10 as left child of left of root\n");
        return;
    }
    else
    {
        printf("addNode() test: PASS when adding 10 as left of left of root\n");
    }
    
    deleteBSTree(tree);
    destroyValues(tv);
}

/**
 * Tests that the BST contains the added elements,
 * and that it does not contain an element that was not added.
 */
void testContainsBSTree()
{
    struct TestValues* tv = createValues();
    struct BSTree *tree	= newBSTree();
    
    // Create value not added to the tree
    struct data notInTree;
    notInTree.number = 111;
    notInTree.name = "not in tree";
    
    // Add all other values to the tree
    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
    }
    
    printTestResult(containsBSTree(tree, &(tv->values[0])), "containsBSTree", "when test containing 50 as root");
    printTestResult(containsBSTree(tree, &(tv->values[1])), "containsBSTree", "when test containing 13 as left of root");
    printTestResult(containsBSTree(tree, &(tv->values[2])), "containsBSTree", "when test containing 110 as right of root");
    printTestResult(containsBSTree(tree, &(tv->values[3])), "containsBSTree", "when test containing 10 as left of left of root");
    
    printTestResult(!containsBSTree(tree, &notInTree), "containsBSTree", "when test containing 111, which is not in the tree");
    
    deleteBSTree(tree);
    destroyValues(tv);
}

/**
 * Tests leftMost.
 */
void testMinMax()
{
	struct TestValues* tv = createValues();
    BSTree* tree	= newBSTree();

    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
    }
	
	if(compare(minBSTree(tree), &(tv->values[3])) == 0)
		printf("Test minBSTree(): PASS\n");
    else
        printf("Test minBSTree(): FAIL\n");
	
	if(compare(maxBSTree(tree), &(tv->values[2])) == 0)
		printf("Test maxBSTree(): PASS\n");
    else
        printf("Test maxBSTree(): FAIL\n");
	
	deleteBSTree(tree);
    destroyValues(tv);
}



/**
 * Tests removal of all nodes.
 */
void testRemoveBSTree()
{
    struct TestValues* tv = createValues();
    BSTree *tree	= newBSTree();

    for (int i = 0; i < tv->n; ++i)
    {
        addBSTree(tree, &(tv->values[i]));
    }
    
	printf("Original tree:\n");
	printBSTree(tree);
	
    removeBSTree(tree, &tv->values[0]);
	printf("The tree below should not contain the value 5\n");
    //printf("NEW ROOT: ");
    //print_type(tree->root->value);
	printBSTree(tree);

    /*   
    removeBSTree(tree, &tv->values[2]);
	printf("The tree below should not contain the value 110\n");
	printBSTree(tree);
	   
    removeBSTree(tree, &tv->values[1]);
	printf("The tree below should not contain the value 13\n");
	printBSTree(tree);
        
    removeBSTree(tree, &tv->values[0]);
	printf("The tree below should be empty\n");
	printBSTree(tree);
    
    deleteBSTree(tree);
    destroyValues(tv);
    */
}


// Main function for testing

int main(int argc, char *argv[])
{	

   /* After implementing your code, you must uncomment the following calls to the test functions and test your code. Otherwise, you will not receive any 
points */

  	//testAddNode();
	
	printf("\n");
  	//testContainsBSTree();
	
	printf("\n");
    //testMinMax();
	
	printf("\n");
    testRemoveBSTree();
    
    
	return 0;
}