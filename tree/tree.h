#ifndef TREE_H
#define TREE_H

#define max(a, b) ((a > b) ? a : b)

#ifndef TNODE_STRUCT
#define TNODE_STRUCT
typedef struct _node
{
    int data;
    struct _node *left;
    struct _node *right;
} TNode;
#endif

typedef struct _tree
{
    TNode *root;
} Tree;


Tree *newTree();
TNode *newNode(int data);
int isTreeEmpty(Tree *tree);
int addLeft(TNode *node, int data);
int addRight(TNode *node, int data);

/*
    mode 0: preorder
    mode 1: inorder
    mode 2: postorder
    mode 3: level order
*/
void printTree(Tree *tree, int mode);
int deleteLeft(TNode *node);
int deleteRight(TNode *node);
void deleteTree(Tree *tree);

int isFullTree(Tree *tree);
int isPerfectTree(Tree *tree);
int isCompleteTree(Tree *tree);
int isBalancedTree(Tree *tree);

#endif