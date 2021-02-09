#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#define MAX_STACK_SIZE 10

struct stack;
typedef struct stack Stack;

// creates and returns new empty stack
Stack *newStack();

// checks whether stack is empty
int isStackEmpty(Stack *stack);

// returns size of the stack
int getStackSize(Stack *stack);

/* 
    adds data to end of the stack
    returns -1 if the stack is full

*/
int push(Stack *stack, int data);

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