#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

struct stack
{
    int array[MAX_STACK_SIZE];
    int top;
};
typedef struct stack Stack;

Stack *newStack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->top = -1;

    return stack;
}

int getStackSize(Stack *stack)
{
    return stack->top + 1;
}

int isStackFull(Stack *stack)
{
    return getStackSize(stack) == MAX_STACK_SIZE;
}

int isStackEmpty(Stack *stack)
{
    return !getStackSize(stack);
}

int push(Stack *stack, int value)
{
    if (!isStackFull(stack))
    {
        stack->top++;
        stack->array[stack->top] = value;
        return 1;
    } 
    else
    {
        return -1;
    }
}

int pop(Stack *stack)
{
    if (!isStackEmpty(stack))
    {
        return stack->array[stack->top--];
    }
    else
    {
        exit(1);
    }
}

int peek(Stack *stack)
{
    if(!isStackEmpty(stack))
    {
        return stack->array[stack->top];
    }
    else
    {
        exit(1);
    }
}

void printStack(Stack *stack)
{
    for(int i = 0; i < getStackSize(stack) - 1; i++)
    {
        printf("%d, ", stack->array[i]);
    }
    printf("%d <- Top\n", stack->array[stack->top]);
}

void deleteStack(Stack *stack)
{
    free(stack);
}