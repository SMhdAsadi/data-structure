#include <stdio.h>
#include <malloc.h>

typedef struct listnode
{
    int data;
    struct listnode *next;
} CListNode;

typedef struct _circular_linkedlist
{
    CListNode *head;
} CLinkedList;

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

CListNode *getLastCListNode(CLinkedList *list)
{
    if (isCListEmpty(list))
    {
        return NULL;
    }
    CListNode *currentNode = list->head;

    while (currentNode->next != list->head)
    {
        currentNode = currentNode->next;
    }

    return currentNode;
}

CListNode *getSecondLastCListNode(CLinkedList *list)
{
    if (isCListEmpty(list) || list->head == list->head->next)
    {
        return NULL;
    }

    CListNode *currentNode = list->head;

    while (currentNode->next->next != list->head)
    {
        currentNode = currentNode->next;
    }

    return currentNode;
}

int getFirstListData(CLinkedList *list)
{
    if (isCListEmpty(list))
    {
        return -1;
    }

    return list->head->data;
}

int getLastListData(CLinkedList *list)
{
    if (isCListEmpty(list))
    {
        return -1;
    }

    return getLastCListNode(list)->data;
}

void addToFirstOfCList(CLinkedList *list, int data)
{
    CListNode *node = newCListNode(data);
    if (isCListEmpty(list))
    {
        list->head = node;
        return;
    }

    node->next = list->head;
    list->head = node;
    getLastCListNode(list)->next = node;
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

int deleteFromFirstOfCList(CLinkedList *list)
{
    if (isCListEmpty(list))
    {
        return -1;
    }

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
    {
        return -1;
    }

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
        {
            getLastCListNode(list)->next = NULL;   
        }
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