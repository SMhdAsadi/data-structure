#ifndef TREENODE_QUEUE_H
#define TREENODE_QUEUE_H

#include "tree.h"

struct queue;
typedef struct queue Queue;

// creates and returns a new empty queue
Queue *newQueue();

// tests whether queue is empty
int isQueueEmpty(Queue *queue);

// tests weather queue is full
int isQueueFull(Queue *queue);

/*
    puts data in last position of the queue
    returns -1 if queue is full
*/
int enqueue(Queue *queue, TNode *node);

/*
    returns and deletes first item of queue
    returns NULL if queue is empty
*/
TNode *dequeue(Queue *queue);

// deletes queue and frees memory
void deleteQueue(Queue *queue);

#endif