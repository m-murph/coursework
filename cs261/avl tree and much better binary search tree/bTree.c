#include <stdlib.h>
#include <stdio.h>
#define TYPE int

typedef struct node{
    TYPE value;
    struct node* left;
    struct node* right;

}node;

typedef struct BinarySearchTree{
    struct node* root;
    int size;
}BinarySearchTree;





void BSTremove(BinarySearchTree*, TYPE);


/* ANSWERS TO QUESTION 9 */
TYPE getFirst(node* n){
    if (n->left == NULL){
        return n->value;
    }
    return getFirst(n->left);
}
void removeFirst(BinarySearchTree* t){
    node* it = t->root;
    while (it->left != NULL){
        it = it->left;
    }
    BSTremove(t, it->value);
}




void BSTinit(BinarySearchTree* tree){
    tree->size = 0;
    tree->root = NULL;
}

node* BSTnodeAdd(node* current, TYPE newValue){
    if (current == NULL){
        node* current2 = (node*)malloc(sizeof(node));
        current2->value = newValue;
        current2->left = NULL;
        current2->right = NULL;
        return current2;
    }
    else if (newValue < current->value){
        current->left = BSTnodeAdd(current->left, newValue);
    }
    else{
        current->right = BSTnodeAdd(current->right, newValue);
    }
    return current; 
}
void BSTadd(BinarySearchTree* tree, TYPE newValue){
    tree->root = BSTnodeAdd(tree->root, newValue);
    tree->size++;
}

int BSTsize(BinarySearchTree* tree){
    return tree->size;
}

int c(node* n ,TYPE d){
    if (n->value == d){
        return 1;
    }
    else if (d < n->value && n->left != NULL){
        return c(n->left, d);
    }
    else if (d >= n->value && n->right != NULL){
        return c(n->right, d);
    }
    return  0;
}
int BSTcontains(BinarySearchTree* tree, TYPE d){
    if (tree->size != 0){
        return c(tree->root, d);
    }
    return 0;
}






struct node* removeLeftMost(node* current){
    if (current->left == NULL){
        node* tmp = current->right;
        free(current);
        return tmp;
    }
    return current;
}
node* BSTnodeRemove(node* current, TYPE d){
    if (current->value == d){
        if (current->right == NULL){
            return current->left;
        }
        else{
            current->value = getFirst(current->right);
            current->right = removeLeftMost(current->right);
        }
    }
    else if(d < current->value){
        current->left = BSTnodeRemove(current->left, d);
    }
    else{
        current->right = BSTnodeRemove(current->right, d);
    }
    return current;
}
void BSTremove(BinarySearchTree* tree, TYPE d){
    if(BSTcontains(tree, d) == 1){
        tree->root = BSTnodeRemove(tree->root, d);
        tree->size--;
    }
}


void pn(node* n){
    printf("%d\n", n->value);
    if (n->left != NULL){
        pn(n->left);
    }
    if (n->right != NULL){
        pn(n->right);
    }   
}
void print(BinarySearchTree* t){
    if (t->size > 0){
        printf("ROOT = %d\n", t->root->value);
        pn(t->root);
    }
    else{
        printf("its empty bruh\n");
    }
}


/* ANSWER TO QUESTION 8 */
int main(){
    BinarySearchTree* t = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    BSTinit(t);
    printf("adding 0, 0, 0, 0\n");
    BSTadd(t, 0);
    BSTadd(t, 0);
    BSTadd(t, 0);
    BSTadd(t, 0);
    printf("left most val: %d\n", getFirst(t->root));
    printf("contains 0?... %d\n", BSTcontains(t, 0));
    printf("removing all 0s\n");
    BSTremove(t, 0);
    BSTremove(t, 0);
    BSTremove(t, 0);
    BSTremove(t, 0);
    printf("contains 0?... %d\n", BSTcontains(t, 0));
    printf("\n\n");

    printf("adding 10, 9, 8, 7\n");
    BSTadd(t, 10);
    BSTadd(t, 9);
    BSTadd(t, 8);
    BSTadd(t, 7);
    printf("left most val: %d\n", getFirst(t->root)); 

    removeFirst(t);
    printf("contains 7 after calling removeFirst?... %d\n", BSTcontains(t, 7));
    BSTremove(t, 10);
    printf("contains 10 after removing 10?... %d\n", BSTcontains(t, 10));
    BSTremove(t, 8);
    printf("contains 8 after removing 8?... %d\n", BSTcontains(t, 8));
    printf("removing 9\n");
    BSTremove(t, 9);
    printf("size shoud be 0...size is: %d\n", BSTsize(t));

    return 0;
}