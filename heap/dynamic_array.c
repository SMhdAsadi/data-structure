#include <stdio.h>
#include <malloc.h>

typedef struct _dynamic_array
{
    int *elements;
    int size;
    int capacity;
} Array;

Array *newArray(int capacity)
{
    Array *array = malloc(sizeof(Array));
    array->elements = calloc(capacity, sizeof(array->elements[0]));
    array->size = 0;
    array->capacity = capacity;

    return array;
}

void doubleTheCapacity(Array *array)
{
    array->elements = realloc(array->elements, array->capacity * 2 * sizeof(array->elements[0]));
}

int len(Array *array)
{
    return array->size;
}

void set(Array *array, int index, int data)
{
    if (index < array->size && index >= 0)
    {
        array->elements[index] = data;
    }
}

int get(Array *array, int index)
{
    if (index < array->size && index >= 0)
    {
        return array->elements[index];
    }

    return -1;
}

void swap(Array *array, int index1, int index2)
{
    if (index1 < array->size && index2 < array->size)
    {
        int temp = get(array, index1);
        set(array, index1, get(array, index2));
        set(array, index2, temp);
    }
}

void add(Array *array, int data)
{
    if (array->size == array->capacity)
    {
        doubleTheCapacity(array);
    }

    array->elements[array->size] = data;
    array->size++;
}

void deleteLast(Array *array)
{
    if (len(array) > 0)
    {
        array->size--;
    }
}

void deleteArray(Array *array)
{
    free(array->elements);
    free(array);
}

