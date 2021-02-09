#ifndef NODEQUEUE_H
#define NODEQUEUE_H
#include "../linkedlist/node_list.h"

typedef struct _queue
{
    LinkedList *list;
} Queue;

Queue *newQueue();
void enqueue(Queue *queue, TNode *node);
TNode *dequeue(Queue *queue);
TNode *peek(Queue *queue);
void deleteQueue(Queue *queue);

#endif