#include <stdio.h>
#include <malloc.h>

#define MAX_QUEUE_SIZE 10

typedef struct _deque
{
    int array[MAX_QUEUE_SIZE];
    int front, rear;
} Deque;


Deque *newDeque()
{
    Deque *deque = malloc(sizeof(Deque));
    deque->front = -1;
    deque->rear = -1;

    return deque;
}

int isDequeFull(Deque *deque)
{
    return (deque->rear + 1) % MAX_QUEUE_SIZE == deque->front;
}

int isDequeEmpty(Deque *deque)
{
    return deque->front == -1;
}

int insertFirst(Deque *deque, int data)
{
    if (isDequeFull(deque))
    {
        return -1;
    }
    if (isDequeEmpty(deque))
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else
    {
        deque->front = (deque->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }

    deque->array[deque->front] = data;
    return 1;
}

int insertLast(Deque *deque, int data)
{
    if (isDequeFull(deque))
    {
        return -1;
    }
    if (isDequeEmpty(deque))
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else
    {
        deque->rear = (deque->rear + 1) % MAX_QUEUE_SIZE;
    }
    deque->array[deque->rear] = data;
    return 1;
}

int deleteFirst(Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        return -1;
    }
    int data = deque->array[deque->front];
    deque->front = (deque->front + 1) % MAX_QUEUE_SIZE;
    return data;
}

int deleteLast(Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        return -1;
    }
    int data = deque->array[deque->rear];
    deque->rear = (deque->rear - 1) % MAX_QUEUE_SIZE;
    return data;
}

int peekFirst(Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        return -1;
    }
    return deque->array[deque->front];
}

int peekLast(Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        return -1;
    }
    return deque->array[deque->rear];
}

void deleteDeque(Deque *deque)
{
    free(deque);
}

void printDeque(Deque *deque)
{
    printf("Front -> ");
    for (int i = deque->front; i != deque->rear; i = (i + 1) % MAX_QUEUE_SIZE)
    {
        printf("%i, ", deque->array[i]);
    }
    if (deque->rear != -1)
    {
        printf("%i", deque->array[deque->rear]);
    }
    printf(" <- Rear\n");
}