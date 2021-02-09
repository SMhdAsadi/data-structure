#ifndef CIRCULAR_LINKEDLIST_H
#define CIRCULAR_LINKEDLIST_H

struct _circular_linkedlist;
typedef struct _circular_linkedlist CLinkedList;

// creates and returns new empty circular linkedlist
CLinkedList *newCLinkedList();

// checks if circular linkedlist is empty
int isCListEmpty(CLinkedList *list);

// returns the size of the list
int getCListSize(CLinkedList *list);

// returns the first item of the circular linkedlist, -1 if the list is empty
int getFirstCListData(CLinkedList *list);

// returns the last item of the circular linkedlist, -1 if the list is empty
int getLastCListData(CLinkedList *list);

/*
    returns the itme at index position of circular linkedlist
    returns -1 if list is empty of index is invalid
*/
int getCListData(CLinkedList *list, int index);

// adds data to beginning of the circular linkedlist
void addToFirstOfCList(CLinkedList *list, int data);

// adds data to end of the circular linkedlist
void addToLastOfCList(CLinkedList *list, int data);

// adds data to index position of the circular linkedlist, returns -1 if index is invalid
int addToCList(CLinkedList *list, int index, int data);

// deletes first item of the circular linkedlist, returns -1 if list is empty
int deleteFromFirstOfCList(CLinkedList *list);

// deletes last item of the circular linkedlist, returns -1 if the list is empty
int deleteFromLastOfCList(CLinkedList *list);

/*
    deletes item at index position of the circular linkedlist
    returns -1 if the list is empty or index is invalid
*/
int deleteFromCList(CLinkedList *list, int index);

// deletes entire circular linkedlist and frees memory
void deleteCList(CLinkedList *list);

// prints out circular linkedlist on the stdout
void printCList(CLinkedList *list);

#endif