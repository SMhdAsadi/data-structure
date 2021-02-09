#include <malloc.h>
#include "binary_search_tree.h"

void addToBST(Tree *tree, int data)
{
    if (isTreeEmpty(tree))
    {
        tree->root = newNode(data);
        return;
    }

    TNode *currentNode = tree->root;
    while ((data < currentNode->data && currentNode->left != NULL) || 
           (data > currentNode->data && currentNode->right != NULL))
    {
        currentNode = data < currentNode->data ? currentNode->left : currentNode->right;
    }

    data < currentNode->data ? addLeft(currentNode, data) : addRight(currentNode, data);
}

int hasSubTreeValue(TNode *node, int data)
{
    if (node == NULL)
    {
        return 0;
    }

    if (node->data == data)
    {
        return 1;
    }
    if (node->data < data)
    {
        return hasSubTreeValue(node->right, data);
    }
    return hasSubTreeValue(node->left, data);
}

int search(Tree *tree, int data)
{
    if (isTreeEmpty(tree))
    {
        return 0;
    }

    return hasSubTreeValue(tree->root, data);
}

TNode *getLowestNode(TNode *node)
{
    TNode *currentNode = node;
    while (currentNode != NULL && currentNode->left != NULL)
    {
        currentNode = currentNode->left;
    }
    return currentNode;
}

TNode *deleteNode(TNode *node, int data)
{
    if (node == NULL) return node;

    // if data is not found yet
    if (data < node->data)
    {
        node->left = deleteNode(node->left, data);
        return node;
    }

    if (data > node->data)
    {
        node->right = deleteNode(node->right, data);
        return node;
    }

    // if data is found

    // if node has no children
    if (node->right == NULL && node->left == NULL)
    {
        free(node);
        return NULL;
    }

    // if node has just right child
    if (node->left == NULL)
    {
        TNode *temp = node->right;
        free(node);
        return temp;
    }

    // if node has just left child
    if (node->right == NULL)
    {
        TNode *temp = node->left;
        free(node);
        return temp;
    }

    // if node has both left and right child
    TNode *LowestInRightSubTree = getLowestNode(node->right);
    node->data = LowestInRightSubTree->data;
    node->right = deleteNode(node->right, node->data);

    return node;
}

int deleteFromBST(Tree *tree, int data)
{
    if (isTreeEmpty(tree))
    {
        return 0;
    }

    tree->root = deleteNode(tree->root, data);
    return 1;
}