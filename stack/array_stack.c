#include "array_stack.h"
#include <stdio.h>
#include <malloc.h>

struct stack
{
    int array[MAX_STACK_SIZE];
    int top;
};

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
    return getStackSize(stack) == 0;
}

int push(Stack *stack, int data)
{
    if (isStackFull(stack))
        return -1;
    else
    {
        stack->top++;
        stack->array[stack->top] = data;
        return 1;
    }
}

int pop(Stack *stack)
{
    if (isStackEmpty(stack))
        return -1;
    else
        return stack->array[stack->top--];
}

int peek(Stack *stack)
{
    if (isStackEmpty(stack))
        return -1;
    else
        return stack->array[stack->top];
}

void printStack(Stack *stack)
{
    int size = getStackSize(stack);
    if (size == 0)
        printf("empty stack\n");
    else
    {
        for (int i = 0; i < size - 1; i++)
            printf("%d, ", stack->array[i]);
        printf("%d <- Top\n", stack->array[stack->top]);
    }
}

void deleteStack(Stack *stack)
{
    free(stack);
}