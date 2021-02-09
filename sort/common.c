#include <stdio.h>
#include "common.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *array, int length)
{
    printf("[");
    for (int i = 0; i < length - 1; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("%i]\n", array[length - 1]);
}