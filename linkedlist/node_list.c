#include <stdio.h>
#include <malloc.h>
#include "node_list.h"


ListNode *newListNode(TNode *treeNode)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->tNode = treeNode;
    node->next = NULL;

    return node;
}

LinkedList *newList()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;

    return list;
}

int isListEmpty(LinkedList *list)
{
    return list->head == NULL;
}

ListNode *getLastListNode(LinkedList *list)
{
    if (isListEmpty(list))
    {
        return NULL;
    }

    ListNode *currentNode = list->head;
    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    return currentNode;
}

ListNode *getSecondLastListNode(LinkedList *list)
{
    // when we have less than 2 nodes
    if (isListEmpty(list) || list->head->next == NULL)
    {
        return NULL;
    }

    ListNode *currentNode = list->head;
    while (currentNode->next->next != NULL)
    {
        currentNode = currentNode->next;
    }

    return currentNode;
}

void addToFirst(LinkedList *list, TNode *node)
{
    if (isListEmpty(list))
    {
        list->head = newListNode(node);
        return;
    }

    ListNode *newNode = newListNode(node);
    newNode->next = list->head;
    list->head = newNode;
}

void addToLast(LinkedList *list, TNode *node)
{
    if (isListEmpty(list))
    {
        list->head = newListNode(node);
        return;
    }

    ListNode *lastNode = getLastListNode(list);
    lastNode->next = newListNode(node);
}

int deleteFromFirst(LinkedList *list)
{
    if (isListEmpty(list))
    {
        return -1;
    }

    ListNode *firstNode = list->head;
    list->head = list->head->next;
    free(firstNode);
    return 1;
}

int deleteFromLast(LinkedList *list)
{
    if (isListEmpty(list))
    {
        return -1;
    }

    // if list contains only one element
    if (list->head->next == NULL)
    {
        ListNode *deletedNode = list->head;
        list->head = NULL;
        free(deletedNode);
        return 1;
    }

    ListNode *secondLastNode = getSecondLastListNode(list);
    ListNode *deletedNode = secondLastNode->next;
    secondLastNode->next = NULL;
    free(deletedNode);
    return 1;
}

TNode *getFirst(LinkedList *list)
{
    if (isListEmpty(list))
    {
        return NULL;
    }

    return list->head->tNode;
}

TNode *getLast(LinkedList *list)
{
    if (isListEmpty(list))
    {
        return NULL;
    }

    return getLastListNode(list)->tNode;
}

void deleteNodes(ListNode *node)
{
    if (node != NULL)
    {
        deleteNodes(node->next);
        free(node);
    }
}

void deleteList(LinkedList *list)
{
    deleteNodes(list->head);
    free(list);
}