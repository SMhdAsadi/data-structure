/*
    custom linkedlist used for hashtable
    this linkedlist stores nodes that have name and age in them
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct list;
typedef struct list List;

// creates and returns new empty linkedlist
List *newList();

// checks whether linkedlist is empty
int isEmpty(List *list);

// adds (key, value) to beginning of the linkedlist
void addNode(List *list, char *key, int value);

/*
    finds and retuns value of a node of specified key
    returns -1 if list is empty of key not found
*/
int getListValue(List *list, char *key);

/*
    deletes the node with specified key
    returns -1 if not found or list is empty
*/
int deleteNode(List *list, char *key);

// deletes linkedlist and frees memory
void deleteList(List *list);

// prints linkedlist on the stdout
void printList(List *list);

#endif