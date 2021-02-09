#ifndef LIST_DEQUE_H
#define LIST_DEQUE_H

#include "../linkedlist/linkedlist.h"

struct deque;
typedef struct deque Deque;

// creates and returns a new empty deque
Deque *newDeque();

// checks whether deque is empty or not
int isDequeEmpty(Deque *deque);

// inserts data to beginning of the deque
void insertFirst(Deque *deque, int data);

// inserts data to end of the deque
void insertLast(Deque *deque, int data);

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
int peekfirst(Deque *deque);

/*
    returns last item of deque
    returns -1 if deque is empty
*/
int peekLast(Deque *deque);

// deletes entire deque and frees memory
int deleteDeque(Deque *deque);

// prints deque on the stdout
void printDeque(Deque *deque);

#endif