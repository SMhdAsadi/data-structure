#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

struct dlinkedlist;
typedef struct dlinkedlist DLinkedList;

// creates and returns a new empty doubly linkedlist
DLinkedList *newDLinkedList();

/*
    checks if the doubly linkedlist is empty
    returns 1 if the list is empty, 0 if not empty
*/
int isDListEmpty(DLinkedList *list);

// returns the size of doubly linkedlist
int getDListSize(DLinkedList *list);

// adds data to start of the doubly linkedlist
void addToFirstOfDList(DLinkedList *list, int data);

// adds data to end of the doubly linkedlist
void addToLastOfDList(DLinkedList *list, int data);

/*
    adds data into index of the doubly linked list
    returns -1 if index is invalid
*/
int addToDList(DLinkedList *list, int index, int data);

/*
    deletes first item of doubly linkedlist
    returns -1 if list is empty
*/
int deleteFromFirstOfDList(DLinkedList *list);

/*
    deletes last item of doubly linkedlist
    returns -1 if list is empty
*/
int deleteFromLastOfDList(DLinkedList *list);

/*
    deletes item at index position of the doubly linkedlist
    returns -1 if list is empty or index is invalid
*/
int deleteFromDList(DLinkedList *list, int index);

/*
    returns first item data of doubly linkedlist
    returns -1 if the list is empty
*/
int getFirstDListData(DLinkedList *list);

/*
    returns last item data of doubly linkedlist
    returns -1 if the list is empty
*/
int getLastDListData(DLinkedList *list);

/*
    returns item at index position of doubly linkedlist
    returns -1 if list is empty or index is invalid
*/
int getDListData(DLinkedList *list, int index);

// deletes doubly linkedlist and frees memory
void deleteDList(DLinkedList *list);

// prints doubly linkedlist on the stdout
void printDList(DLinkedList *list);

// prints doubly linkedlist in reverse order on the stdout
void printDListReverse(DLinkedList *list);

#endif