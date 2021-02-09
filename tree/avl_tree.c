#include <stdio.h>
#include <malloc.h>

#define max(a, b) ((a > b) ? a : b)

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


Node *newNode(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->height = 1;
    node->left = node->right = NULL;

    return node;
}

AVL *newAVL()
{
    AVL *tree = malloc(sizeof(AVL));
    tree->root = NULL;

    return tree;
}

int isAVLEmpty(AVL *tree)
{
    return tree->root == NULL;
}

int getHeight(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

void updateHeight(Node *node)
{
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

int getBalanceFactor(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

int isHeavyLeft(Node *node)
{
    return getBalanceFactor(node) > 1;
}

int isHeavyRight(Node *node)
{
    return getBalanceFactor(node) < -1;
}

/*
    rotate X with Y in this diagram
                X
              a   Y
                 b c
*/
Node *leftRotation(Node *X)
{
    Node *Y = X->right;
    Node *b = Y->left;

    Y->left = X;
    X->right = b;

    updateHeight(X);
    updateHeight(Y);

    return Y;
}


/*
    rotate X with Y in this diagram
              X
            Y   a
           b c
*/
Node *rightRotation(Node *X)
{
    Node *Y = X->left;
    Node *c = Y->right;

    Y->right = X;
    X->left = c;

    updateHeight(X);
    updateHeight(Y);

    return Y;
}

Node *reBalance(Node *node)
{
    // if it is LL
    if (isHeavyLeft(node) && getBalanceFactor(node->left) >= 0)
    {
        return rightRotation(node);
    }

    // if it is LR
    if (isHeavyLeft(node) && getBalanceFactor(node->left) < 0)
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    // if it is RR
    if (isHeavyRight(node) && getBalanceFactor(node->right) <= 0)
    {
        return leftRotation(node);
    }

    // if it is RL
    if (isHeavyRight(node) && getBalanceFactor(node->left) > 0)
    {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    return node;
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
    {
        return newNode(data);
    }

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else // key is in tree already
    {
        return node;
    }

    updateHeight(node);
    return reBalance(node);
}

void insertToAVL(AVL *tree, int data)
{
    tree->root = insert(tree->root, data);
}

Node *getLowestNode(Node *node)
{
    Node *currentNode = node;
    while (currentNode != NULL && currentNode->left != NULL)
    {
        currentNode = currentNode->left;
    }
    return currentNode;
}

Node *delete(Node *node, int data)
{
    if (node == NULL)
    {
        return node;
    }

    if (data < node->data)
    {
        node->left = delete(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = delete(node->right, data);
    }
    else
    {
        // if node has no children
        if (node->right == NULL && node->left == NULL)
        {
            free(node);
            node = NULL;
        }

        // if node has just right child
        if (node->left == NULL)
        {
            Node *temp = node->right;
            *node = *temp;
            free(temp);
        }

        // if node has just left child
        if (node->right == NULL)
        {
            Node *temp = node->left;
            *node = *temp;
            free(temp);
        }

        // if node has both left and right child
        Node *LowestInRightSubTree = getLowestNode(node->right);
        node->data = LowestInRightSubTree->data;
        node->right = delete(node->right, node->data);
    }

    if (node == NULL)
    {
        return node;
    }

    updateHeight(node);
    return reBalance(node);
}

void deleteFromAVL(AVL *tree, int data)
{
    tree->root = delete(tree->root, data);
}

void printSubTreeInOrder(Node *node)
{
    if (node != NULL)
    {
        printSubTreeInOrder(node->left);
        printf("%i, ", node->data);
        printSubTreeInOrder(node->right);
    }
}

void printSubTreePreOrder(Node *node)
{
    if (node != NULL)
    {
        printf("%i, ", node->data);
        printSubTreePreOrder(node->left);
        printSubTreePreOrder(node->right);
    }
}

void printSubTreePostOrder(Node *node)
{
    if (node != NULL)
    {
        printSubTreePostOrder(node->left);
        printSubTreePostOrder(node->right);
        printf("%i, ", node->data);
    }
}


void printTree(AVL *tree, int mode)
{
   printf("[");
   switch(mode)
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

    // case 3:
    //     printSubtreeLevelOrder(tree->root);
    //     break
    
    default:
        printSubTreeInOrder(tree->root);
        break;
   }
   printf("]\n");
}

void deleteSubTree(Node *node)
{
    if (node != NULL)
    {
        deleteSubTree(node->left);
        deleteSubTree(node->right);
        free(node);
    }
}

void deleteTree(AVL *tree)
{
    deleteSubTree(tree->root);
}