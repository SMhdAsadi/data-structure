#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "../linkedlist/linkedlist.h"

struct priority_queue;
typedef struct priority_queue PriorityQueue;

// creates and returns a new empty priority queue
PriorityQueue *newPriorityQueue();

// puts data at the end of priority queue
void enqueue(PriorityQueue *queue, int data);

/*
    returns and deletes first item of priority queue
    returns -1 if queue is empty 
*/
int dequeue(PriorityQueue *queue);

/*
    returns first item of priority queue
    returns -1 if queue is empty
*/
int peek(PriorityQueue *queue);

// deletes entire priority queue and frees memory
void deletePriorityQueue(PriorityQueue *queue);

// prints priority queue on the stdout
void printPriorityQueue(PriorityQueue *queue);

#endif