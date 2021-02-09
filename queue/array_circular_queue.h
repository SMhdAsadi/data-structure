#ifndef ARRAY_CIRCULAR_QUEUE_H
#define ARRAY_CIRCULAR_QUEUE_H

#define MAX_QUEUE_SIZE 10

struct c_queue;
typedef struct c_queue CircularQueue;

// creates and returns a new empty circular queue
CircularQueue *newCircularQueue();

// checks whether circular queue is empty or not
int isCQueueEmpty(CircularQueue *queue);

// checks whether circular queue is full or not
int isCQueueFull(CircularQueue *queue);

/*
   puts the data to end of circular queue
   returns -1 if queue is full
*/
int enqueue(CircularQueue *queue, int data);

/*
    deletes and returns first item of circular queue
    returns -1 if queue is empty
*/
int dequeue(CircularQueue *queue);

/*
    returns first item of circular queue
    returns -1 if queue is empty
*/
int peek(CircularQueue *queue);

// prints circular queue on the stdout
void printCQueue(CircularQueue *queue);

// deletes circular queue and frees memory
void deleteCQueue(CircularQueue *queue);

#endif