#ifndef AVLTREE_H
#define AVLTREE_H

#define max(a, b) ((a > b) ? a : b)

struct avl;
typedef struct avl AVL;

// creates and returns a new empty AVL
AVL *newAVL();

// checks whether AVL is empty or not
int isAVLEmpty(AVL *tree);

// inserts data to AVL tree, and rebalance tree if needed
void insertToAVL(AVL *tree, int data);

// deletes data from AVL tree, and rebalance tree if needed
void deleteFromAVL(AVL *tree, int data);

/*
    prints AVL tree on the stdout
    mode 0: preorder
    mode 1: inorder
    mode 2: postorder
*/
void printTree(AVL *tree, int mode);

// deletes AVL tree and frees memory
void deleteTree(AVL *tree);

#endif