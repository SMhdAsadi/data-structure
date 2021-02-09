#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#define MAX_QUEUE_SIZE 10

struct queue;
typedef struct queue Queue;

// creates and returns a new empty queue
Queue *newQueue();

// tests weather queue is empty
int isQueueEmpty(Queue *queue);

// tests weather queue is full
int isQueueFull(Queue *queue);

/*
    puts data in last position of the queue
    returns -1 if queue is full
*/
int enqueue(Queue *queue, int data);

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

// prints queue on the stdout
void printQueue(Queue *queue);

// deletes queue and frees memory
void deleteQueue(Queue *queue);

#endif