#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "tree.h"

// adds data in proper position in binary search tree
void addToBST(Tree *tree, int data);

// searches for data in tree, returns 1 if found 0 if not found
int search(Tree *tree, int data);

// deletes the node with data, returns 1 if deleted 0 if not found
int deleteFromBST(Tree *tree, int data);

#endif