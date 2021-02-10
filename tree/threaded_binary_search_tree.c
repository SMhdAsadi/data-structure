#include "threaded_binary_search_tree.h"
#include <stdio.h>
#include <malloc.h>

typedef struct _th_node
{
    int data;
    struct _th_node *left;
    struct _th_node *right;
    int leftThread;
    int rightThread;
} Node;

struct th_tree
{
    Node *root;
};

Node *newNode(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    node->leftThread = node->rightThread = 1;

    return node;
}

ThTree *newThreadedTree()
{
    ThTree *tree = malloc(sizeof(ThTree));
    tree->root = NULL;

    return tree;
}

Node *getParentNode(Node *root, int data)
{
    // Searching for a Node with given value
    Node *currentNode = root;
    Node *parentNode = NULL;
    while (currentNode != NULL)
    {
        // If key already exists, return
        if (data == currentNode->data)
            return root;

        parentNode = currentNode; // Update parent pointer

        if (data < currentNode->data) // Moving on left subtree.
        {
            if (currentNode->leftThread == 0)
                currentNode = currentNode->left;
            else
                break;
        }
        else // Moving on right subtree.
        {
            if (currentNode->rightThread == 0)
                currentNode = currentNode->right;
            else
                break;
        }
    }

    return parentNode;
}

void insert(ThTree *tree, int data)
{
    Node *root = tree->root;
    Node *parentNode = getParentNode(root, data);
    Node *node = newNode(data);

    if (parentNode == NULL)
    {
        root = node;
        node->left = NULL;
        node->right = NULL;
    }
    else if (data < parentNode->data)
    {
        node->left = parentNode->left;
        node->right = parentNode;
        parentNode->leftThread = 0;
        parentNode->left = node;
    }
    else
    {
        node->left = parentNode;
        node->right = parentNode->right;
        parentNode->rightThread = 0;
        parentNode->right = node;
    }

    tree->root = root;
}

// Returns inorder successor using rightThread
Node *getNextInorderNode(Node *node)
{
    // If rightThread is set, we can quickly find
    if (node->rightThread == 1)
        return node->right;

    // Else return leftmost child of right subtree
    node = node->right;
    while (node->leftThread == 0)
        node = node->left;

    return node;
}

// Printing the threaded tree
void printInorder(ThTree *tree)
{
    Node *root = tree->root;

    printf("[");
    if (root == NULL)
    {
        printf(" ]\n");
        return;
    }

    // Reach leftmost node
    Node *node = root;
    while (node->leftThread == 0)
        node = node->left;

    while (node != NULL)
    {
        printf("%i ", node->data);
        node = getNextInorderNode(node);
    }

    printf("]\n");
}

void deleteNodes(Node *node)
{
    if (node != NULL)
    {
        if (node->leftThread == 0)
            deleteNodes(node->left);
        if (node->rightThread == 0)
            deleteNodes(node->right);
        free(node);
    }
}

void deletethreadedTree(ThTree *tree)
{
    deleteNodes(tree->root);
    free(tree);
}