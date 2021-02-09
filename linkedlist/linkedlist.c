#include "linkedlist.h"
#include <stdio.h>
#include <malloc.h>

LinkedList *newLinkedList()
{
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    linkedList->head = NULL;

    return linkedList;
}

ListNode *newListNode(int data)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;

    return node;
}

int isListEmpty(LinkedList *list)
{
    return list->head == NULL;
}

int getListSize(LinkedList *list)
{
    if (isListEmpty(list))
        return 0;

    int size = 1;
    ListNode *node = list->head;
    while (node->next != NULL)
    {
        node = node->next;
        size++;
    }
    return size;
}

ListNode *getLastListNode(LinkedList *list)
{
    if (isListEmpty(list))
        return NULL;

    ListNode *node = list->head;
    while (node->next != NULL)
        node = node->next;

    return node;
}

ListNode *getSecondLastListNode(LinkedList *list)
{
    if (isListEmpty(list) || list->head->next == NULL)
        return NULL;

    ListNode *node = list->head;
    while (node->next->next != NULL)
        node = node->next;

    return node;
}

int getListData(LinkedList *list, int index)
{
    if (isListEmpty(list))
        return -1;

    int currentIndex = 0;
    ListNode *currentNode = list->head;

    while (currentNode->next != NULL && currentIndex < index)
    {
        currentNode = currentNode->next;
        currentIndex++;
    }

    if (currentIndex == index)
        return currentNode->data;

    return -1;
}

int getFirstListData(LinkedList *list)
{
    if (isListEmpty(list))
        return -1;

    return list->head->data;
}

int getLastListData(LinkedList *list)
{
    if (isListEmpty(list))
        return -1;

    return getLastListNode(list)->data;
}

void addToFirstOfList(LinkedList *list, int data)
{
    ListNode *node = newListNode(data);
    if (isListEmpty(list))
        list->head = node;
    else
    {
        node->next = list->head;
        list->head = node;
    }
}

void addToLastOfList(LinkedList *list, int data)
{
    ListNode *node = newListNode(data);
    if (isListEmpty(list))
        list->head = node;
    else
    {
        ListNode *lastNode = getLastListNode(list);
        lastNode->next = node;
    }
}

int addToList(LinkedList *list, int index, int data)
{
    if (index == 0)
    {
        addToFirstOfList(list, data);
        return 1;
    }

    ListNode *currentNode = list->head;
    if (currentNode == NULL)
        return -1;

    for (int i = 0; i < index - 1; i++)
    {
        currentNode = currentNode->next;
        if (currentNode == NULL)
            return -1;
    }

    ListNode *newNode = newListNode(data);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return 1;
}

int deleteFromFirstOfList(LinkedList *list)
{
    if (isListEmpty(list))
        return -1;

    ListNode *deletedNode = list->head;
    list->head = list->head->next;
    free(deletedNode);
    return 1;
}

int deleteFromLastOfList(LinkedList *list)
{
    if (isListEmpty(list))
        return -1;

    ListNode *secondLastNode = getSecondLastListNode(list);
    ListNode *lastNode = secondLastNode->next;
    secondLastNode->next = NULL;
    free(lastNode);
}

int deleteFromList(LinkedList *list, int index)
{
    if (index == 0)
        return deleteFromFirstOfList(list);

    if (isListEmpty(list))
        return -1;

    ListNode *currentNode = list->head;
    for (int i = 0; i < index - 1; i++)
    {
        currentNode = currentNode->next;
        if (currentNode == NULL)
            return -1;
    }

    if (currentNode->next == NULL)
        return -1;

    ListNode *deletedNode = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(deletedNode);
    return 1;
}

void deleteListNodes(ListNode *node)
{
    if (node != NULL)
    {
        deleteListNodes(node->next);
        free(node);
    }
}

void deleteList(LinkedList *list)
{
    if (list != NULL)
    {
        deleteListNodes(list->head);
        free(list);
    }
}

void printList(LinkedList *list)
{
    printf("[");
    if (isListEmpty(list))
        printf(" ]\n");
    else
    {
        ListNode *currentNode = list->head;
        while (currentNode->next != NULL)
        {
            printf("%d, ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("%d]\n", currentNode->data);
    }
}