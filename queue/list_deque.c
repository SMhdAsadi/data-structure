#include "list_deque.h"
#include <stdio.h>
#include <malloc.h>

struct deque
{
    LinkedList *list;
};

Deque *newDeque()
{
    Deque *deque = malloc(sizeof(Deque));
    deque->list = newLinkedList();

    return deque;
}

int isDequeEmpty(Deque *deque)
{
    return isListEmpty(deque->list);
}

void insertFirst(Deque *deque, int data)
{
    addToFirstOfList(deque->list, data);
}

void insertLast(Deque *deque, int data)
{
    addToLastOfList(deque->list, data);
}

int deleteFirst(Deque *deque)
{
    if (isDequeEmpty(deque))
        return -1;

    int data = getFirstListData(deque->list);
    if (deleteFromFirstOfList(deque->list) == -1)
        return -1;

    return data;
}

int deleteLast(Deque *deque)
{
    if (isDequeEmpty(deque))
        return -1;

    int data = getLastListData(deque->list);
    if (deleteFromLastOfList(deque->list) == -1)
        return -1;

    return data;
}

int peekFirst(Deque *deque)
{
    if (isDequeEmpty(deque))
        return -1;

    return getFirstListData(deque->list);
}

int peekLast(Deque *deque)
{
    if (isDequeEmpty(deque))
        return -1;

    return getLastListData(deque->list);
}

void deleteDeque(Deque *deque)
{
    if (deque != NULL)
    {
        deleteList(deque->list);
        free(deque);
    }
}

void printDeque(Deque *deque)
{
    printf("Deque ");
    printList(deque->list);
}