#ifndef THREDEDTHREE_H
#define THREDEDTHREE_H


typedef struct _th_node
{
    int data;
    struct _th_node *left;
    struct _th_node *right;
    int leftThread;
    int rightThread;
} Node;

typedef struct _th_tree
{
    Node *root;
} ThTree;


ThTree *newThreadedTree();
void insert(ThTree *tree, int data);
void printInorder(ThTree *tree);
void deletethreadedTree(ThTree *tree);

#endif