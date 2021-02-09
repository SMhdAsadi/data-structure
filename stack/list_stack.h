#ifndef LIST_STACK_H
#define LIST_STACK_H

#include "../linkedlist/linkedlist.c"

struct stack;
typedef stack Stack;

Stack *newStack();
int isStackEmpty(Stack *stack);
int getStackSize(Stack *stack);
void push(Stack *stack, int data);
int pop(Stack *stack);
int peek(Stack *stack);
void printStack(Stack *stack);
void deleteStack(Stack *stack);

#endif