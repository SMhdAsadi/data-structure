#include <stdio.h>
#include <malloc.h>

typedef struct list_node
{
    int data;
    struct list_node *prev;
    struct list_node *next;
} DListNode;

typedef struct DLinkedList
{
    DListNode *head;
} DLinkedList;


DListNode *newDListNode(int data)
{
    DListNode *node = malloc(sizeof(DListNode));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

DLinkedList *newDLinkedList()
{
    DLinkedList *list = malloc(sizeof(DLinkedList));
    list->head = NULL;

    return list;
}

int isDListEmpty(DLinkedList *list)
{
    return list->head == NULL;
}

DListNode *getLastDNode(DLinkedList *list)
{
    if (isDListEmpty(list))
    {
        return NULL;
    }

    DListNode *node = list->head;
    while (node->next != NULL)
    {
        node = node->next;
    }
    return node;
}

void addToFirstOfDList(DLinkedList *list, int data)
{
    DListNode *node = newDListNode(data);
    if (isDListEmpty(list))
    {
        list->head = node;
        return;
    }

    node->next = list->head;
    node->next->prev = node;
    list->head = node;
}

void addToLastOfDList(DLinkedList *list, int data)
{
    DListNode *newNode = newDListNode(data);
    if (isDListEmpty(list))
    {
        list->head = newNode;
        return;
    }

    DListNode *lastNode = getLastDNode(list);
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

int deleteFromFirstOfDList(DLinkedList *list)
{
    if (isDListEmpty(list))
    {
        return 0;
    }

    DListNode *firstNode = list->head;
    list->head = firstNode->next;
    list->head->prev = NULL;
    free(firstNode);
    return 1;
}

int deleteFromLastOfDList(DLinkedList *list)
{
    if (isDListEmpty(list))
    {
        return -1;
    }

    DListNode *lastNode = getLastDNode(list);
    if (lastNode->prev == NULL) // There is just one node
    {
        list->head = NULL;
        free(lastNode);
        return 1;
    }

    DListNode *secondLastNode = lastNode->prev;
    secondLastNode->next = NULL;
    free(lastNode);
    return 1;
}

int getFirstDListData(DLinkedList *list)
{
    if (isDListEmpty(list))
    {
        return -1;
    }

    return list->head->data;
}

int getLastDListData(DLinkedList *list)
{
    if (isDListEmpty(list))
    {
        return -1;
    }

    return getLastDNode(list)->data;
}

void deleteNodes(DListNode *node)
{
    if (node != NULL)
    {
        deleteNodes(node->next);
        free(node);
    }
}

void deleteDList(DLinkedList *list)
{
    deleteNodes(list->head);
    free(list);
}

void printDList(DLinkedList *list)
{
    printf("[");
    DListNode *node = list->head;

    while (node->next != NULL)
    {
        printf("%i, ", node->data);
        node = node->next;
    }
    if (!isDListEmpty(list))
    {
        printf("%i]\n", node->data);
    }
    else
    {
        printf("]\n");
    }
    
}

void printDListReverse(DLinkedList *list)
{
    printf("[");
    DListNode *node = getLastDNode(list);

    while (node->prev != NULL)
    {
        printf("%i, ", node->data);
        node = node->prev;
    }
    if (!isDListEmpty(list))
    {
        printf("%i]\n", node->data);
    }
    else
    {
        printf("]\n");
    }
}