#ifndef HEAP_H
#define HEAP_H
#include "dynamic_array.h"

#define DEFAULT_HEAP_SIZE 10

typedef enum _heap_type {MIN_HEAP, MAX_HEAP} HeapType;

typedef struct _heap
{
    Array *array;
    HeapType type;
} Heap;

Heap *newHeap(HeapType type);
void insert(Heap *heap, int data);
void deleteRoot(Heap *heap, int data);
void printHeap(Heap *heap);
void deleteHeap(Heap *heap);

#endif