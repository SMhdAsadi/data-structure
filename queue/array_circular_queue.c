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

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

struct c_queue
{
    int array[MAX_QUEUE_SIZE];
    int front, rear;
};
typedef struct c_queue CircularQueue;

CircularQueue *newCircularQueue()
{
    CircularQueue *queue = malloc(sizeof(CircularQueue));
    queue->front = queue->rear = -1;

    return queue;
}

int isQueueEmpty(CircularQueue *queue)
{
    return queue->front == -1;
}

int isQueueFull(CircularQueue *queue)
{
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

int enqueue(CircularQueue *queue, int data)
{
    if (isQueueFull(queue))
    {
        return -1;
    }
    if (queue->front == -1)
    {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->array[queue->rear] = data;
    return 1;
}

int dequeue(CircularQueue *queue)
{
    if (isQueueEmpty(queue))
    {
        return -1;
    }

    int data = queue->array[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;   
    }
    return data;
}

int peek(CircularQueue *queue)
{
    if (isQueueEmpty(queue))
    {
        return -1;
    }
    return queue->array[queue->front];
}

void printQueue(CircularQueue *queue)
{
    printf("Front -> ");
    
    if (!isQueueEmpty(queue))
    {
        for (int i = queue->front; i != queue->rear; i = (i + 1) % MAX_QUEUE_SIZE)
        {
            printf("%d ", queue->array[i]);
        }
        printf("%d ", queue->array[queue->rear]);
    }
    
    printf("<- Rear\n");
}

void deleteQueue(CircularQueue *queue)
{
    free(queue);
}