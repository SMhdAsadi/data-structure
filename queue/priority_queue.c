#include "priority_queue.h"
#include <stdio.h>
#include <malloc.h>

struct priority_queue
{
    LinkedList *list;
};

PriorityQueue *newPriorityQueue()
{
    PriorityQueue *queue = malloc(sizeof(PriorityQueue));
    queue->list = newLinkedList();

    return queue;
}

int findEnqueueIndex(PriorityQueue *queue, int data)
{
    if (isListEmpty(queue->list))
        return 0;

    ListNode *currentNode = queue->list->head;
    int i = 0;
    while (currentNode != NULL)
    {
        if (data > currentNode->data)
            return i;

        currentNode = currentNode->next;
        i++;
    }

    return i;
}

void enqueue(PriorityQueue *queue, int data)
{
    int index = findEnqueueIndex(queue, data);
    addToList(queue->list, index, data);
}

int dequeue(PriorityQueue *queue)
{
    int data = getFirstListData(queue->list);
    deleteFromFirstOfList(queue->list);
    return data;
}

int peek(PriorityQueue *queue)
{
    return getFirstListData(queue->list);
}

void deletePriorityQueue(PriorityQueue *queue)
{
    if (queue != NULL)
    {
        deleteList(queue->list);
        free(queue);
    }
}

void printPriorityQueue(PriorityQueue *queue)
{
    printf("Priority Queue ");
    printList(queue->list);
}