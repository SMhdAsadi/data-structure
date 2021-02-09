/*
    in this circular queue we use array to store values
    at first, front and rear are both -1
    after adding first value 
        * front shows index of front item
        * rear shows index of rear item

    - in proccess of dequeue if rear and front are the same,
      there is one item so after dequeue we have empty queue,
      so both front and rear come back to -1
*/

#include "array_circular_queue.h"
#include <stdio.h>
#include <malloc.h>

struct c_queue
{
    int array[MAX_QUEUE_SIZE];
    int front, rear;
};

CircularQueue *newCircularQueue()
{
    CircularQueue *queue = malloc(sizeof(CircularQueue));
    queue->front = queue->rear = -1;

    return queue;
}

int isCQueueEmpty(CircularQueue *queue)
{
    return queue->front == -1;
}

int isCQueueFull(CircularQueue *queue)
{
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

int enqueue(CircularQueue *queue, int data)
{
    if (isCQueueFull(queue))
        return -1;

    if (queue->front == -1)
        queue->front = 0;

    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->array[queue->rear] = data;
    return 1;
}

int dequeue(CircularQueue *queue)
{
    if (isCQueueEmpty(queue))
        return -1;

    int data = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;

    return data;
}

int peek(CircularQueue *queue)
{
    if (isCQueueEmpty(queue))
        return -1;

    return queue->array[queue->front];
}

void printCQueue(CircularQueue *queue)
{
    printf("Front -> ");

    if (!isCQueueEmpty(queue))
    {
        for (int i = queue->front; i != queue->rear; i = (i + 1) % MAX_QUEUE_SIZE)
            printf("%d ", queue->array[i]);

        printf("%d ", queue->array[queue->rear]);
    }

    printf("<- Rear\n");
}

void deleteCQueue(CircularQueue *queue)
{
    free(queue);
}