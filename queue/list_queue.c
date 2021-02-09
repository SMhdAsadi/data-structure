#include "list_queue.h"
#include <stdio.h>
#include <malloc.h>

struct list_queue
{
    LinkedList *list;
};

Queue *newQueue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->list = newLinkedList();

    return queue;
}

void enqueue(Queue *queue, int data)
{
    addToLastOfList(queue->list, data);
}

int dequeue(Queue *queue)
{
    int data = getFirstListData(queue->list);
    deleteFromFirstOfList(queue->list);

    return data;
}

int peek(Queue *queue)
{
    return getFirstListData(queue->list);
}

void deleteQueue(Queue *queue)
{
    deleteList(queue->list);
    free(queue);
}

void printQueue(Queue *queue)
{
    printf("Queue ");
    printList(queue->list);
}