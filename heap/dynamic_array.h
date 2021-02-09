#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

typedef struct _dynamic_array
{
    int *elements;
    int size;
    int capacity;
} Array;

Array *newArray(int capacity);
void set(Array *array, int index, int data);
int get(Array *array, int index);
void add(Array *array, int data);
void deleteArray(Array *array);
int len(Array *array);
void swap(Array *array, int index1, int index2);
void deleteLast(Array *array);

#endif