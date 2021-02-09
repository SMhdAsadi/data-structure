#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct _node
{
    int data;
    int height;
    struct _node *left;
    struct _node *right;
} Node;

typedef struct _avl
{
    Node *root;
} AVL;

AVL *newAVL();
int isAVLEmpty(AVL *tree);
void insertToAVL(AVL *tree, int data);
void deleteFromAVL(AVL *tree, int data);

/*
    mode 0: preorder
    mode 1: inorder
    mode 2: postorder
    mode 3: level order
*/
void printTree(AVL *tree, int mode);
void deleteTree(AVL *tree);

#endif