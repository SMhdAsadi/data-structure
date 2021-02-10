#ifndef TREE_H
#define TREE_H

#define max(a, b) ((a > b) ? a : b)

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node TNode;

struct tree
{
    TNode *root;
};
typedef struct tree Tree;

// creates and returns a new empty tree
Tree *newTree();

// creates and returns a new tree that has a root
Tree *newTreeWithNode(TNode *root);

// creates and returns a new node with this data
TNode *newNode(int data);

// checks whether tree is empty or not
int isTreeEmpty(Tree *tree);

/*
    adds a new node to left child of specified node
    does nothing and returns 0 if node has left child
*/
int addLeft(TNode *node, int data);

/*
    adds a new node to right child of specified node
    does nothing and returns 0 if node has right child
*/
int addRight(TNode *node, int data);

/*
    prints tree in vaious methods
    mode 0: preorder
    mode 1: inorder
    mode 2: postorder
    mode 3: level order
*/
void printTree(Tree *tree, int mode);

/*
    deletes left child of node
    returns 0 if node has no left child
*/
int deleteLeft(TNode *node);

/*
    deletes right child of node
    returns 0 if node has no right child
*/
int deleteRight(TNode *node);

// deletes entire tree and frees memory
void deleteTree(Tree *tree);

// checks whether tree is full or not
int isFullTree(Tree *tree);

// checks whether tree is perfect or not
int isPerfectTree(Tree *tree);

// checks whether tree is complete or not
int isCompleteTree(Tree *tree);

// checks whether tree is balanced or not
int isBalancedTree(Tree *tree);

#endif