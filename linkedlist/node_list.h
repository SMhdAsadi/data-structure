#ifndef NODELIST_H
#define NODELIST_H

#ifndef TNODE_STRUCT
#define TNODE_STRUCT
typedef struct _node
{
    int data;
    struct _node *left;
    struct _node *right;
} TNode;
#endif

typedef struct _listnode
{
    TNode *tNode;
    struct _listnode *next;
} ListNode;

typedef struct _list
{
    ListNode *head;
} LinkedList;


LinkedList *newList();
int isListEmpty(LinkedList *list);
void addToFirst(LinkedList *list, TNode *node);
void addToLast(LinkedList *list, TNode *node);
int deleteFromFirst(LinkedList *list);
int deleteFromLast(LinkedList *list);
TNode *getFirst(LinkedList *list);
TNode *getLast(LinkedList *list);
void deleteList(LinkedList *list);

#endif