/*
    in this queue we use array to store values
    at first, front and rear are both -1
    after adding first value 
        * front shows index of front item
        * rear shows index of rear item

    - when front goes after rear it means queue is empty,
      so both front and rear come back to -1
*/

#include "treenode_queue.h"
#include <stdio.h>
#include <malloc.h>

struct queue
{
    TNode **array;
    int front, rear;
    int size;
};

Queue *newQueue(int size)
{
    Queue *queue = malloc(sizeof(Queue));
    queue->array = calloc(size, sizeof(queue->array[0]));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;

    return queue;
}

int isQueueEmpty(Queue *queue)
{
    return queue->front == -1;
}

int isQueueFull(Queue *queue)
{
    return queue->rear == queue->size - 1;
}

int enqueue(Queue *queue, TNode *node)
{
    if (isQueueFull(queue))
        return -1;

    if (queue->front == -1)
        queue->front++;

    queue->rear++;
    queue->array[queue->rear] = node;
    return 1;
}

TNode *dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
        return NULL;

    TNode *node = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;

    return node;
}

void deleteQueue(Queue *queue)
{
    free(queue);
}