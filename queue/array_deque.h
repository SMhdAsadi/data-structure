#ifndef ARRAY_DEQUE_H
#define ARRAY_DEQUE_H

#define MAX_QUEUE_SIZE 10

struct deque;
typedef struct deque Deque;

// creates and returns a new empty deque
Deque *newDeque();

// checks whether deque is empty or not
int isDequeEmpty(Deque *deque);

/*
    inserts data to beginning of the deque
    returns -1 if deque is full
*/
int insertFirst(Deque *deque, int data);

/*
    inserts data to end of the deque
    returns -1 if deque is full
*/
int insertLast(Deque *deque, int data);

/*
    deletes first item of deque
    returns -1 if deque is empty
*/
int deleteFirst(Deque *deque);

/*
    deletes last item of deque
    returns -1 if deque is empty
*/
int deleteLast(Deque *deque);

/*
    returns first item of deque
    returns -1 if deque is empty
*/
int peekFirst(Deque *deque);

/*
    returns last item of deque
    returns -1 if deque is empty
*/
int peekLast(Deque *deque);

// deletes entire deque and frees memory
void deleteDeque(Deque *deque);

// prints deque on the stdout
void printDeque(Deque *deque);

#endif