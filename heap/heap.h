#ifndef HEAP_H
#define HEAP_H
#include "dynamic_array.h"

#define DEFAULT_HEAP_SIZE 10

enum heap_type
{
    MIN_HEAP,
    MAX_HEAP
};
typedef enum heap_type HeapType;

struct heap;
typedef struct heap Heap;

// creates and returns new empty heap
Heap *newHeap(HeapType type);

// inserts data into the heap
void insert(Heap *heap, int data);

/*
    deletes and returns top item of the heap out
    returns -1 if heap is empty
*/
int deleteRoot(Heap *heap);

// prints heap on the stdout
void printHeap(Heap *heap);

// deletes heap and frees memory
void deleteHeap(Heap *heap);

#endif