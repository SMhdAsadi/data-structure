#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

struct dynamic_array;
typedef struct dynamic_array Array;

// creates and returns a new empty dynamic array
Array *newArray(int capacity);

// checks whether dynamic array is empty
int isArrayEmpty(Array *array);

// returns length of the dynamic array
int len(Array *array);

/*
    swap items at index1 and index2
    returns -1 if at least one of indexes are invalid
*/
int swap(Array *array, int index1, int index2);

// updates value of array at position index to data
void set(Array *array, int index, int data);

/*
    returns item at index position
    returns -1 if index is invalid
*/
int get(Array *array, int index);

// adds data to start of the dynamic array
void addFirst(Array *array, int data);

// adds data to end of the dynamic array
void addLast(Array *array, int data);

/*
    adds data to specified index of the dynamic array
    returns -1 if the index is invalid
*/
int add(Array *array, int index, int data);

/*
    deletes first item of the dynamic array
    returns -1 if array is empty
*/
int deleteFirst(Array *array);

/*
    deletes last item of the dynamic array
    returns -1 if array is empty
*/
int deleteLast(Array *array);

/*
    deletes item at position index of the dynamic array
    returns -1 if array is empty or index is invalid
*/
int delete (Array *array, int index);

// deletes the entire array and frees memory
void deleteArray(Array *array);

// prints array on the stdout
void printArray(Array *array);

#endif