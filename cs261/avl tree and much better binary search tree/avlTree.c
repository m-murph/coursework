#include <stdlib.h>
#include <stdio.h>
#define TYPE int

typedef struct AVLnode{
    TYPE value;
    struct AVLnode* left;
    struct AVLnode* right;
    int height;

}AVLnode;

typedef struct BinarySearchTree{
    struct AVLnode* root;
    int size;
}BinarySearchTree;





void removeAVLTree(BinarySearchTree*, TYPE);

TYPE getFirst(AVLnode* n){
    if (n->left == NULL){
        return n->value;
    }
    return getFirst(n->left);
}
TYPE removeFirst(BinarySearchTree* t){
    AVLnode* it = t->root;
    while (it->left != NULL){
        it = it->left;
    }
    TYPE tmp = it->value;
    removeAVLTree(t, it->value);
    return tmp;
}




void BSTinit(BinarySearchTree* tree){
    tree->size = 0;
    tree->root = NULL;
}

int h(AVLnode* current){
    if (current == NULL){
        return -1;
    }
    return current->height;
}
void setHeight(AVLnode* current){
    int lch = h(current->left);
    int rch = h(current->right);
    if (lch < rch){
        current->height = 1 + rch;
    }
    else{
        current->height = 1 + lch;
    }
}


int bf(AVLnode* current){
    return (h(current->right) - h(current->left));
}

AVLnode* rotateLeft(AVLnode* current){
    AVLnode* tmp = current->right->left;
    AVLnode* oldCurrent = current;
    current = current->right;
    current->left = oldCurrent;
    current->left->right = tmp;
    setHeight(current->left);
    setHeight(current);
    return current;
}

AVLnode* rotateRight(AVLnode* current){
    AVLnode* tmp = current->left->right;
    AVLnode* oldCurrent = current;
    current = current->left;
    current->right = oldCurrent;
    current->right->left = tmp;
    setHeight(current->right);
    setHeight(current);
    return current;
}


AVLnode* balance(AVLnode* current){
    int cbf = bf(current);
    if (cbf < -1){
        if (bf(current->left) > 0){
            current->left = rotateLeft(current->left);
        }
        return rotateRight(current);
    }
    else if(cbf > 1 && current->right->value != current->value){
        if (bf(current->right) < 0){
            current->right = rotateRight(current->right);
        }
        return rotateLeft(current);
    }
    setHeight(current);
    return current;
}



AVLnode* AVLnodeAdd(AVLnode* current, TYPE newValue){
    AVLnode* newnode;
    if (current == NULL){
        newnode = (AVLnode*)malloc(sizeof(AVLnode));
        newnode->value = newValue;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->height = 0;
        return newnode;
    }
    else if (newValue < current->value){
        current->left = AVLnodeAdd(current->left, newValue);
    }
    else{
        current->right = AVLnodeAdd(current->right, newValue);
    }
    return balance(current); 
}
void AVLadd(BinarySearchTree* tree, TYPE newValue){
    tree->root = AVLnodeAdd(tree->root, newValue);
    tree->size++;
}

int BSTsize(BinarySearchTree* tree){
    return tree->size;
}

int c(AVLnode* n ,TYPE d){
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

struct AVLnode* removeLeftMost(AVLnode* current){
    if (current->left == NULL){
        AVLnode* tmp = current->right;
        free(current);
        return tmp;
    }
    else{
        current->left = removeLeftMost(current->left);
    }
    return current;
}
AVLnode* AVLnodeRemove(AVLnode* current, TYPE d){
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
        current->left = AVLnodeRemove(current->left, d);
    }
    else{
        current->right = AVLnodeRemove(current->right, d);
    }
    return balance(current);
}
void removeAVLTree(BinarySearchTree* tree, TYPE d){
    if(BSTcontains(tree, d) == 1){
        tree->root = AVLnodeRemove(tree->root, d);
        tree->size--;
    }
}


void pn(AVLnode* current, int offset){
    if (current == NULL){
        return;
    }

    offset += 10;
    pn(current->right, offset);
 
    printf("\n");
    for (int i = 10; i < offset; i++){
        printf(" ");
    }
    printf("%d\n", current->value);
 
    pn(current->left, offset);
}
void print(struct BinarySearchTree* tree){
    printf("-------------------------------------------------------------------");
    pn(tree->root, 0);
    printf("-------------------------------------------------------------------");
    printf("\n\n");
}


void treeSort(int* myInts, int sizeMyInts){
    BinarySearchTree* t = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    BSTinit(t);

    for (int i = 0; i<sizeMyInts; i++){
        AVLadd(t, myInts[i]);
    }

    print(t);

    for (int i = 0; i<sizeMyInts; i++){
        myInts[i] = removeFirst(t);
    }
}

int main(){
    BinarySearchTree* t = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    BSTinit(t);

    int* myInts = (int*)malloc(sizeof(int)*12);
    int sizeMyInts = 12;

    myInts[0] = 7;
    myInts[1] = 4;
    myInts[2] = 9;
    myInts[3] = 8;
    myInts[4] = 2;
    myInts[5] = 5;
    myInts[6] = 1;
    myInts[7] = 11;
    myInts[8] = -5;
    myInts[9] = 0;
    myInts[10] = 14;
    myInts[11] = -3;

    printf("Before sort:\n");
    for (int i = 0; i<sizeMyInts; i++){
        printf("%d, ", myInts[i]);
    }
    printf("\n\n");

    treeSort(myInts, sizeMyInts);

    printf("After sort:\n");
    for (int i = 0; i<sizeMyInts; i++){
        printf("%d, ", myInts[i]);
    }
    printf("\n");

    free(myInts);
    return 0;
}