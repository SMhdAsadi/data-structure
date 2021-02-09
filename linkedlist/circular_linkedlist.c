#include "circular_linkedlist.h"
#include <stdio.h>
#include <malloc.h>

typedef struct listnode
{
    int data;
    struct listnode *next;
} CListNode;

struct _circular_linkedlist
{
    CListNode *head;
};

CLinkedList *newCLinkedList()
{
    CLinkedList *linkedList = malloc(sizeof(CLinkedList));
    linkedList->head = NULL;

    return linkedList;
}

CListNode *newCListNode(int data)
{
    CListNode *node = malloc(sizeof(CListNode));
    node->data = data;
    node->next = node;

    return node;
}

int isCListEmpty(CLinkedList *list)
{
    return list->head == NULL;
}

int getCListSize(CLinkedList *list)
{
    if (isCListEmpty(list))
        return 0;

    CListNode *node = list->head;
    int size = 0;
    while (node != NULL)
    {
        node = node->next;
        size++;
    }

    return size;
}

CListNode *getLastCListNode(CLinkedList *list)
{
    if (isCListEmpty(list))
        return NULL;

    CListNode *currentNode = list->head;

    while (currentNode->next != list->head)
        currentNode = currentNode->next;

    return currentNode;
}

CListNode *getSecondLastCListNode(CLinkedList *list)
{
    if (isCListEmpty(list) || list->head == list->head->next)
        return NULL;

    CListNode *currentNode = list->head;

    while (currentNode->next->next != list->head)
        currentNode = currentNode->next;

    return currentNode;
}

int getFirstCListData(CLinkedList *list)
{
    if (isCListEmpty(list))
        return -1;

    return list->head->data;
}

int getLastCListData(CLinkedList *list)
{
    if (isCListEmpty(list))
        return -1;

    return getLastCListNode(list)->data;
}

int getCListData(CLinkedList *list, int index)
{
    if (index == 0)
        return getFirstCListData(list);

    if (index < 0 || isCListEmpty(list))
        return -1;

    CListNode *currentNode = list->head;
    int i = 0;
    while (i < index)
    {
        currentNode = currentNode->next;
        i++;
        if (currentNode == list->head)
            return -1;
    }

    if (i == index)
        return currentNode->data;

    return -1;
}

void addToFirstOfCList(CLinkedList *list, int data)
{
    CListNode *node = newCListNode(data);
    if (isCListEmpty(list))
    {
        list->head = node;
        return;
    }

    CListNode *lastNode = getLastCListNode(list);
    node->next = list->head;
    list->head = node;
    lastNode->next = node;
}

void addToLastOfCList(CLinkedList *list, int data)
{
    CListNode *node = newCListNode(data);
    if (isCListEmpty(list))
    {
        list->head = node;
        return;
    }

    getLastCListNode(list)->next = node;
    node->next = list->head;
}

int addToCList(CLinkedList *list, int index, int data)
{
    if (index == 0)
    {
        addToFirstOfCList(list, data);
        return 1;
    }

    if (index < 0 || isCListEmpty(list))
        return -1;

    CListNode *beforeNode = list->head;
    int i = 1;
    while (i < index)
    {
        beforeNode = beforeNode->next;
        i++;
        if (beforeNode == list->head)
            return -1;
    }

    if (i == index)
    {
        if (beforeNode->next == list->head)
        {
            addToLastOfCList(list, data);
            return 1;
        }

        CListNode *newNode = newCListNode(data);
        newNode->next = beforeNode->next;
        beforeNode->next = newNode;
        return 1;
    }

    return -1;
}

int deleteFromFirstOfCList(CLinkedList *list)
{
    if (isCListEmpty(list))
        return -1;

    if (list->head->next == list->head)
    {
        CListNode *deletedNode = list->head;
        list->head = NULL;
        free(deletedNode);
        return 1;
    }
    CListNode *deletedNode = list->head, *lastNode = getLastCListNode(list);
    list->head = list->head->next;
    lastNode->next = list->head;
    deletedNode->next = NULL;
    free(deletedNode);

    return 1;
}

int deleteFromLastOfCList(CLinkedList *list)
{
    if (isCListEmpty(list))
        return -1;

    if (list->head->next == list->head)
    {
        CListNode *deletedNode = list->head;
        list->head = NULL;
        free(deletedNode);
        return 1;
    }

    CListNode *secondLastNode, *lastNode;
    secondLastNode = getSecondLastCListNode(list);
    lastNode = secondLastNode->next;

    secondLastNode->next = list->head;
    free(lastNode);
}

int deleteFromCList(CLinkedList *list, int index)
{
    if (index == 0)
        return deleteFromFirstOfCList(list);

    if (index < 0 || isCListEmpty(list))
        return -1;

    CListNode *beforeNode = list->head;
    int i = 1;
    while (i < index)
    {
        beforeNode = beforeNode->next;
        i++;
        if (beforeNode == list->head)
            return -1;
    }

    if (i == index)
    {
        if (beforeNode->next == list->head)
            return deleteFromLastOfCList(list);

        CListNode *deletedNode = beforeNode->next;
        beforeNode->next = deletedNode->next;
        free(deletedNode);
        return 1;
    }

    return -1;
}

void deleteCListNodes(CListNode *node)
{
    if (node != NULL)
    {
        deleteCListNodes(node->next);
        free(node);
    }
}

void deleteCList(CLinkedList *list)
{
    if (list != NULL)
    {
        if (!isCListEmpty(list))
            getLastCListNode(list)->next = NULL;

        deleteCListNodes(list->head);
        free(list);
    }
}

void printCList(CLinkedList *list)
{
    printf("[");

    if (!isCListEmpty(list))
    {
        CListNode *node = list->head;

        while (node->next != list->head)
        {
            printf("%i, ", node->data);
            node = node->next;
        }

        printf("%i", node->data);
    }
    printf("]\n");
}