#include <stdio.h>
#include <malloc.h>
#include "node_queue.h"


Queue *newQueue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->list = newList();

    return queue;
}

void enqueue(Queue *queue, TNode *node)
{
    addToLast(queue->list, node);
}

TNode *dequeue(Queue *queue)
{
    TNode *node = getFirst(queue->list);
    deleteFromFirst(queue->list);

    return node;
}

TNode *peek(Queue *queue)
{
    return getFirst(queue->list);
}

void deleteQueue(Queue *queue)
{
    deleteList(queue->list);
    free(queue);
}