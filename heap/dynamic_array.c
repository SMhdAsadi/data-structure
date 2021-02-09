#include "dynamic_array.h"
#include <stdio.h>
#include <malloc.h>

struct dynamic_array
{
    int *elements;
    int size;
    int capacity;
};

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
    array->capacity *= 2;
}

int indexIsValid(Array *array, int index)
{
    return index < array->size && index >= 0;
}

int isArrayEmpty(Array *array)
{
    return len(array) == 0;
}

int len(Array *array)
{
    return array->size;
}

void set(Array *array, int index, int data)
{
    if (indexIsValid(array, index))
        array->elements[index] = data;
}

int get(Array *array, int index)
{
    if (indexIsValid(array, index))
        return array->elements[index];

    return -1;
}

int swap(Array *array, int index1, int index2)
{
    if (indexIsValid(array, index1) && indexIsValid(array, index2))
    {
        int temp = get(array, index1);
        set(array, index1, get(array, index2));
        set(array, index2, temp);

        return 1;
    }

    return -1;
}

void addFirst(Array *array, int data)
{
    if (array->size == array->capacity)
        doubleTheCapacity(array);

    int length = len(array), previousItemData = 0;
    array->size++;
    for (int i = length; i > 0; i--)
    {
        previousItemData = get(array, i - 1);
        set(array, i, previousItemData);
    }

    set(array, 0, data);
}

void addLast(Array *array, int data)
{
    if (array->size == array->capacity)
        doubleTheCapacity(array);

    array->elements[array->size] = data;
    array->size++;
}

int add(Array *array, int index, int data)
{
    int length = len(array);
    if (index > length && index < 0)
        return -1;

    if (length == array->capacity)
        doubleTheCapacity(array);

    int previousItemData = 0;
    array->size++;
    for (int i = length; i >= index + 1; i--)
    {
        previousItemData = get(array, i - 1);
        set(array, i, previousItemData);
    }

    set(array, index, data);
    return 1;
}

int deleteFirst(Array *array)
{
    if (isArrayEmpty(array))
        return -1;

    int size = len(array), nextItemData = 0;
    for (int i = 0; i < size - 1; i++)
    {
        nextItemData = get(array, i + 1);
        set(array, i, nextItemData);
    }

    array->size--;
    return 1;
}

int deleteLast(Array *array)
{
    if (isArrayEmpty(array))
        return -1;

    array->size--;
    return 1;
}

int delete (Array *array, int index)
{
    if (!indexIsValid(array, index) || isArrayEmpty(array))
        return -1;

    int length = len(array), nextItemData = 0;
    for (int i = index; i < length; i++)
    {
        nextItemData = get(array, i + 1);
        set(array, i, nextItemData);
    }

    array->size--;
    return 1;
}

void deleteArray(Array *array)
{
    free(array->elements);
    free(array);
}

void printArray(Array *array)
{
    int length = len(array);
    printf("(");

    for (int i = 0; i < length - 1; i++)
        printf("%i, ", array->elements[i]);

    if (length > 0)
        printf("%i)\n", array->elements[length - 1]);
    else
        printf(")\n");
}