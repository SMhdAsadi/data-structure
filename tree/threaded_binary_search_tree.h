#ifndef THREDEDTHREE_H
#define THREDEDTHREE_H

struct th_tree;
typedef struct th_tree ThTree;

// creates and returns a new empty threaded binary search tree
ThTree *newThreadedTree();

// inserts data in the threaded binary search tree
void insert(ThTree *tree, int data);

// prints threaded binary search tree inorder without using stack
void printInorder(ThTree *tree);

// deletes entire threaded binary search tree and frees memory
void deletethreadedTree(ThTree *tree);

#endif