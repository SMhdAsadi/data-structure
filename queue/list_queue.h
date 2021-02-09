#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include "../linkedlist/linkedlist.h"

#define MAX_QUEUE_SIZE 10

struct list_queue;
typedef struct list_queue Queue;

// creates and returns a new empty queue
Queue *newQueue();

// puts data to end of the queue
void enqueue(Queue *queue, int data);

/*
    returns and deletes first item of queue
    returns -1 if queue is empty
*/
int dequeue(Queue *queue);

/*
    returns first item of queue
    returns -1 if queue is empty
*/
int peek(Queue *queue);

// deletes queue and frees memory
void deleteQueue(Queue *queue);

// prints queue on the stdout
void printQueue(Queue *queue);

#endif