#include "linkedlist.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct node
{
    char *key;
    int value;
    struct node *next;
} Node;

struct list
{
    Node *head;
};

Node *newNode(char *key, int value)
{
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;

    return node;
}

List *newList()
{
    List *list = malloc(sizeof(List));
    list->head = NULL;

    return list;
}

int isEmpty(List *list)
{
    return list->head == NULL;
}

void addNode(List *list, char *key, int value)
{
    Node *node = newNode(key, value);

    if (isEmpty(list))
        list->head = node;
    else
    {
        node->next = list->head;
        list->head = node;
    }
}

int getListValue(List *list, char *key)
{
    if (isEmpty(list))
        return -1;

    Node *currentNode = list->head;

    while (currentNode != NULL)
    {
        if (strcmp(currentNode->key, key) == 0)
            return currentNode->value;

        currentNode = currentNode->next;
    }

    return -1;
}

int deleteNode(List *list, char *key)
{
    if (isEmpty(list))
        return -1;

    Node *currentNode = list->head;

    // if it is first item
    if (strcmp(list->head->key, key) == 0)
    {
        Node *firstNode = list->head;
        list->head = firstNode->next;
        free(firstNode);
        return 1;
    }

    // if it is not first item
    while (currentNode->next != NULL)
    {
        if (strcmp(currentNode->next->key, key) == 0)
        {
            Node *deletedNode = currentNode->next;
            currentNode->next = deletedNode->next;
            free(deletedNode);
            return 1;
        }
        currentNode = currentNode->next;
    }

    return -1;
}

void deleteNodes(Node *node)
{
    if (node != NULL)
    {
        deleteNodes(node->next);
        free(node);
    }
}

void deleteList(List *list)
{
    deleteNodes(list->head);
    free(list);
}

void printList(List *list)
{
    printf("[");

    Node *node = list->head;

    if (isEmpty(list))
        printf(" ]\n");
    else
    {
        while (node->next != NULL)
        {
            printf("(%s, %i), ", node->key, node->value);
            node = node->next;
        }
        printf("(%s, %i)]\n", node->key, node->value);
    }
}