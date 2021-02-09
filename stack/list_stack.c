#include "list_stack.h"
#include <stdio.h>

struct stack
{
    LinkedList *list;
};
typedef struct stack Stack;

Stack *newStack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->list = newLinkedList();
    return stack;
}

int isStackEmpty(Stack *stack)
{
    return isListEmpty(stack->list);
}

int getStackSize(Stack *stack)
{
    return getListSize(stack->list);
}

void push(Stack *stack, int data)
{
    addToFirstOfList(stack->list, data);
}

int pop(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        return -1;
    }
    int data = getFirstListData(stack->list);
    deleteFromFirstOfList(stack->list);
    return data;
}

int peek(Stack *stack)
{
    if (isStackEmpty(stack))
    {
        return -1;
    }
    return getFirstListData(stack->list);
}

void printStack(Stack *stack)
{
    printf("Top -> ");
    ListNode *node = stack->list->head;
    while (node->next != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
}

void deleteStack(Stack *stack)
{
    deleteList(stack->list);
    free(stack);
}
