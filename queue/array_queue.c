/*
    in this queue we use array to store values
    at first, front and rear are both -1
    after adding first value 
        * front shows index of front item
        * rear shows index of rear item

    - when front goes after rear it means queue is empty,
      so both front and rear come back to -1
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

struct queue
{
    int array[MAX_QUEUE_SIZE];
    int front, rear;
};
typedef struct queue Queue;

Queue *newQueue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;

    return queue;
}

int isQueueEmpty(Queue *queue)
{
    return queue->front == -1;
}

int isQueueFull(Queue *queue)
{
    return queue->rear == MAX_QUEUE_SIZE - 1;
}

int enqueue(Queue *queue, int data)
{
    if (isQueueFull(queue))
    {
        return -1;
    }
    if (queue->front == -1)
    {
        queue->front++;
    }
    queue->rear++;
    queue->array[queue->rear] = data;
    return 1;
}

int dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        return -1;
    }
    int data = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    return data;
}

int peek(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        return -1;
    }
    return queue->array[queue->front];
}

void printQueue(Queue *queue)
{
    printf("Front -> ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->array[i]);
    }
    printf("<- Rear\n");
}

void deleteQueue(Queue *queue)
{
    free(queue);
}