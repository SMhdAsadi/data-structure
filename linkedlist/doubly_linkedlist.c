#include "doubly_linkedlist.h"
#include <stdio.h>
#include <malloc.h>

typedef struct list_node
{
    int data;
    struct list_node *prev;
    struct list_node *next;
} DListNode;

struct dlinkedlist
{
    DListNode *head;
};

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

int getDListSize(DLinkedList *list)
{
    if (isDListEmpty(list))
        return -1;

    int size = 0;
    DListNode *currentNode = list->head;
    while (currentNode != NULL)
    {
        size++;
        currentNode = currentNode->next;
    }

    return size;
}

DListNode *getLastDNode(DLinkedList *list)
{
    if (isDListEmpty(list))
        return NULL;

    DListNode *node = list->head;
    while (node->next != NULL)
        node = node->next;

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

int addToDList(DLinkedList *list, int index, int data)
{
    if (index == 0)
    {
        addToFirstOfDList(list, data);
        return 1;
    }

    if (isDListEmpty(list) || index < 0)
        return -1;

    DListNode *beforeNode = list->head;
    int i = 1;
    while (beforeNode != NULL && i < index)
    {
        beforeNode = beforeNode->next;
        i++;
    }

    if (index == i)
    {
        DListNode *newNode = newDListNode(data);
        newNode->next = beforeNode->next;
        newNode->prev = beforeNode;
        if (beforeNode->next != NULL)
            beforeNode->next->prev = newNode;
        beforeNode->next = newNode;
        return 1;
    }

    return -1;
}

int deleteFromFirstOfDList(DLinkedList *list)
{
    if (isDListEmpty(list))
        return 0;

    DListNode *firstNode = list->head;
    list->head = firstNode->next;
    list->head->prev = NULL;
    free(firstNode);
    return 1;
}

int deleteFromLastOfDList(DLinkedList *list)
{
    if (isDListEmpty(list))
        return -1;

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

int deleteFromDList(DLinkedList *list, int index)
{
    if (index == 0)
        return deleteFromFirstOfDList(list);

    if (index < 0 || isDListEmpty(list))
        return -1;

    DListNode *beforeNode = list->head;
    int i = 1;
    while (beforeNode != NULL && i < index)
    {
        beforeNode = beforeNode->next;
        i++;
    }

    if (i == index)
    {
        DListNode *deletedNode = beforeNode->next;
        if (deletedNode->next != NULL)
            deletedNode->next->prev = beforeNode;
        beforeNode->next = deletedNode->next;
        free(deletedNode);
        return 1;
    }

    return -1;
}

int getFirstDListData(DLinkedList *list)
{
    if (isDListEmpty(list))
        return -1;

    return list->head->data;
}

int getLastDListData(DLinkedList *list)
{
    if (isDListEmpty(list))
        return -1;

    return getLastDNode(list)->data;
}

int getDListData(DLinkedList *list, int index)
{
    if (index == 0)
        return getFirstDListData(list);

    if (index < 0 || isDListEmpty(list))
        return -1;

    DListNode *currentNode = list->head;
    int i = 0;
    while (currentNode != NULL && i < index)
    {
        currentNode = currentNode->next;
        i++;
    }

    if (i == index && currentNode != NULL)
        return currentNode->data;

    return -1;
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
        printf("%i]\n", node->data);
    else
        printf("]\n");
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
        printf("%i]\n", node->data);
    else
        printf("]\n");
}