#include "heap.h"
#include "dynamic_array.h"
#include <stdio.h>
#include <malloc.h>

struct heap
{
    Array *array;
    HeapType type;
};

Heap *newHeap(HeapType type)
{
    Heap *heap = malloc(sizeof(Heap));
    heap->array = newArray(DEFAULT_HEAP_SIZE);
    heap->type = type;

    return heap;
}

void heapify(Heap *heap, int index)
{
    int size = len(heap->array);

    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    int extermum_index = index;
    if (leftIndex < size)
    {
        int leftChildData = get(heap->array, leftIndex);

        if (heap->type == MAX_HEAP)
        {
            if (leftChildData > get(heap->array, extermum_index))
                extermum_index = leftIndex;
        }
        else if (leftChildData < get(heap->array, extermum_index))
            extermum_index = leftIndex;
    }

    if (rightIndex < size)
    {
        int rightChildData = get(heap->array, rightIndex);

        if (heap->type == MAX_HEAP)
        {
            if (rightChildData > get(heap->array, extermum_index))
                extermum_index = rightIndex;
        }
        else if (rightChildData < get(heap->array, extermum_index))
            extermum_index = rightIndex;
    }

    if (extermum_index != index)
    {
        swap(heap->array, extermum_index, index);
        heapify(heap, extermum_index);
    }
}

void insert(Heap *heap, int data)
{
    addLast(heap->array, data);

    for (int i = len(heap->array) - 1; i >= 0; i--)
        heapify(heap, i);
}

int deleteRoot(Heap *heap)
{
    int size = len(heap->array);
    if (size == 0)
        return -1;

    int value = get(heap->array, 0);
    swap(heap->array, 0, size - 1);
    deleteLast(heap->array);

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(heap, i);

    return value;
}

void printHeap(Heap *heap)
{
    int size = len(heap->array);
    printf("Heap [");
    for (int i = 0; i < size - 1; i++)
        printf("%i, ", get(heap->array, i));

    if (size != 0)
        printf("%i]\n", get(heap->array, size - 1));
    else
        printf("]\n");
}

void deleteHeap(Heap *heap)
{
    deleteArray(heap->array);
    free(heap);
}