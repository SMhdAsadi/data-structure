#include "quick.h"
#include <stdlib.h>

void ascendingQuickSort(int *array, int start, int end);
void descendingQuickSort(int *array, int start, int end);
int ascendingPartition(int *array, int start, int end);
int descendingPartition(int *array, int start, int end);

void quickSort(int *array, int length, Order order)
{
    if (order == ASC)
        ascendingQuickSort(array, 0, length - 1);
    else
        descendingQuickSort(array, 0, length - 1);
}

void ascendingQuickSort(int *array, int start, int end)
{
    if (start < end)
    {
        int pivotIndex = ascendingPartition(array, start, end);
        ascendingQuickSort(array, start, pivotIndex - 1);
        ascendingQuickSort(array, pivotIndex + 1, end);
    }
}

int ascendingPartition(int *array, int start, int end)
{
    int randomIndex = rand() % (end - start + 1) + start;
    swap(&array[randomIndex], &array[end]);

    int pivotIndex = end;
    int pivot = array[pivotIndex];

    int storeIndex = start;
    for (int i = start; i < end; i++)
    {
        if (array[i] <= pivot)
        {
            swap(&array[storeIndex], &array[i]);
            storeIndex++;
        }
    }
    swap(&array[storeIndex], &array[pivotIndex]);
    return storeIndex;
}

void descendingQuickSort(int *array, int start, int end)
{
    if (start < end)
    {
        int pivotIndex = descendingPartition(array, start, end);
        descendingQuickSort(array, start, pivotIndex - 1);
        descendingQuickSort(array, pivotIndex + 1, end);
    }
}

int descendingPartition(int *array, int start, int end)
{
    int randomIndex = rand() % (end - start + 1) + start;
    swap(&array[randomIndex], &array[end]);
    
    int pivotIndex = end;
    int pivot = array[pivotIndex];

    int storeIndex = start;
    for (int i = start; i < end; i++)
    {
        if (array[i] >= pivot)
        {
            swap(&array[i], &array[storeIndex]);
            storeIndex++;
        }
    }
    swap(&array[storeIndex], &array[pivotIndex]);
    return storeIndex;
}