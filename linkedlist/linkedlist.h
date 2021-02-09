#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct listNode
{
    int data;
    struct listNode *next;
};
typedef struct listNode ListNode;

struct linkedlist
{
    ListNode *head;
};
typedef struct linkedlist LinkedList;

// creates and returns a new linked list
LinkedList *newLinkedList();

// checks if the list is empty
int isListEmpty(LinkedList *list);

// returns size of the list
int getListSize(LinkedList *list);

// returns data on the index, -1 if index is invalid
int getListData(LinkedList *list, int index);

// returns first data on the list, -1 if list is empty
int getFirstListData(LinkedList *list);

// returns last data on the list, -1 if list is empty
int getLastListData(LinkedList *list);

// adds data to start of the list
void addToFirstOfList(LinkedList *list, int data);

// adds date to end of the list
void addToLastOfList(LinkedList *list, int data);

// adds data to the index positino in the list, returns -1 if index is invalid
int addToList(LinkedList *list, int index, int data);

// deletes first item of the list, returns -1 if list is empty
int deleteFromFirstOfList(LinkedList *list);

// deletes last item of the list, returns -1 if list is empty
int deleteFromLastOfList(LinkedList *list);

// deletes item at index, returns -1 if index is invalid
int deleteFromList(LinkedList *list, int index);

// deletes list and frees memory
void deleteList(LinkedList *list);

// prints out the list on stdout
void printList(LinkedList *list);

#endif