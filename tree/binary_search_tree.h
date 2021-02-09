#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "tree.h"

void addToBST(Tree *tree, int data);
int search(Tree *tree, int data);
int deleteFromBST(Tree *tree, int data);

#endif