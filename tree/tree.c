#include "tree.h"
#include "treenode_queue.h"
#include <stdio.h>
#include <malloc.h>

Tree *newTree()
{
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;

    return tree;
}

Tree *newTreeWithNode(TNode *root)
{
    Tree *tree = malloc(sizeof(Tree));
    tree->root = root;

    return tree;
}

TNode *newNode(int data)
{
    TNode *node = malloc(sizeof(TNode));
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

int isTreeEmpty(Tree *tree)
{
    return tree->root == NULL;
}

int getNodeCount(TNode *node)
{
    if (node == NULL)
        return 0;

    return 1 + getNodeCount(node->left) + getNodeCount(node->right);
}

int addLeft(TNode *node, int data)
{
    if (node->left != NULL)
        return 0;

    TNode *new_node = newNode(data);
    node->left = new_node;
    return 1;
}

int addRight(TNode *node, int data)
{
    if (node->right != NULL)
        return 0;

    TNode *new_node = newNode(data);
    node->right = new_node;
    return 1;
}

void printSubTreeInOrder(TNode *node)
{
    if (node != NULL)
    {
        printSubTreeInOrder(node->left);
        printf("%i, ", node->data);
        printSubTreeInOrder(node->right);
    }
}

void printSubTreePreOrder(TNode *node)
{
    if (node != NULL)
    {
        printf("%i, ", node->data);
        printSubTreePreOrder(node->left);
        printSubTreePreOrder(node->right);
    }
}

void printSubTreePostOrder(TNode *node)
{
    if (node != NULL)
    {
        printSubTreePostOrder(node->left);
        printSubTreePostOrder(node->right);
        printf("%i, ", node->data);
    }
}

void printSubTreeLevelOrder(Tree *tree)
{
    Queue *queue = newQueue(getNodeCount(tree->root));

    TNode *currentNode = tree->root;
    while (currentNode != NULL)
    {
        printf("%i, ", currentNode->data);
        if (currentNode->left != NULL)
            enqueue(queue, currentNode->left);
        if (currentNode->right != NULL)
            enqueue(queue, currentNode->right);

        currentNode = dequeue(queue);
    }

    deleteQueue(queue);
}

void printTree(Tree *tree, int mode)
{
    /*
        mode 0: preorder
        mode 1: inorder
        mode 2: postorder
        mode 3: level order
    */
    printf("[");
    switch (mode)
    {
    case 0:
        printSubTreePreOrder(tree->root);
        break;

    case 1:
        printSubTreeInOrder(tree->root);
        break;

    case 2:
        printSubTreePostOrder(tree->root);
        break;

    case 3:
        printSubTreeLevelOrder(tree);
        break;

    default:
        printSubTreeInOrder(tree->root);
        break;
    }
    printf("]\n");
}

void deleteSubTree(TNode *node)
{
    if (node != NULL)
    {
        deleteSubTree(node->left);
        deleteSubTree(node->right);
        free(node);
    }
}

int deleteLeft(TNode *node)
{
    if (node->left == NULL)
        return 0;

    TNode *leftSubTree = node->left;
    node->left = NULL;

    deleteSubTree(leftSubTree);
    return 1;
}

int deleteRight(TNode *node)
{
    if (node->right == NULL)
        return 0;

    TNode *rightSubTree = node->right;
    node->right = NULL;

    deleteSubTree(rightSubTree);
    return 1;
}

void deleteTree(Tree *tree)
{
    deleteSubTree(tree->root);
    free(tree);
}

int getHeight(TNode *node)
{
    if (node == NULL)
        return 0;

    if (node->left == NULL && node->right == NULL)
        return 1;

    return max(1 + getHeight(node->left), 1 + getHeight(node->right));
}

int isFullSubTree(TNode *node)
{
    if (node == NULL)
        return 1;
    if (node->left == NULL && node->right == NULL)
        return 1;
    if (node->left != NULL && node->right != NULL)
        return isFullSubTree(node->left) && isFullSubTree(node->right);

    return 0;
}

int isCompleteSubTree(TNode *node, int treeNodeCount, int index)
{
    if (node == NULL)
        return 1;

    if (index > treeNodeCount - 1)
        return 0;

    return isCompleteSubTree(node->left, treeNodeCount, 2 * index + 1) &&
           isCompleteSubTree(node->right, treeNodeCount, 2 * index + 2);
}

int isPerfectSubTree(TNode *node, int treeDepth, int currentLevel)
{
    if (node == NULL)
        return 1;

    // if it is a leaf on the last level
    if (node->left == NULL && node->right == NULL && treeDepth == currentLevel)
        return 1;

    if (node->left != NULL && node->right != NULL)
        return isPerfectSubTree(node->left, treeDepth, currentLevel + 1) &&
               isPerfectSubTree(node->right, treeDepth, currentLevel + 1);

    // if this is a leaf not on the last row or has one child
    return 0;
}

int isBalancedSubTree(TNode *node)
{
    if (node == NULL)
        return 1;

    int differenceInHeight = getHeight(node->left) - getHeight(node->right);
    return differenceInHeight < 2 && differenceInHeight > -2;
}

int isFullTree(Tree *tree)
{
    return isFullSubTree(tree->root);
}

int isPerfectTree(Tree *tree)
{
    return isPerfectSubTree(tree->root, getHeight(tree->root), 1);
}

int isCompleteTree(Tree *tree)
{
    return isCompleteSubTree(tree->root, getNodeCount(tree->root), 0);
}

int isBalancedTree(Tree *tree)
{
    return isBalancedSubTree(tree->root);
}