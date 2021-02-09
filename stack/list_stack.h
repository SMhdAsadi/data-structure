#ifndef LIST_STACK_H
#define LIST_STACK_H

#include "../linkedlist/linkedlist.h"

struct stack;
typedef struct stack Stack;

// creates and returns new empty stack
Stack *newStack();

// checks whether stack is empty
int isStackEmpty(Stack *stack);

// returns size of the stack
int getStackSize(Stack *stack);

// adds data to end of stack
void push(Stack *stack, int data);

/*
    deletes and returns last item of stack
    returns -1 if stack is empty
*/
int pop(Stack *stack);

/*
    returns last item of stack
    returns -1 if stack is empty
*/
int peek(Stack *stack);

// prints stack on the stdout
void printStack(Stack *stack);

// deletes stack and frees memory
void deleteStack(Stack *stack);

#endif