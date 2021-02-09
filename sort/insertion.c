#include "insertion.h"

void ascendingInsertionSort(int *array, int length);
void descendingInsertionSort(int *array, int length);

void insertionSort(int *array, int length, Order order)
{
    if (order == ASC)
        ascendingInsertionSort(array, length);
    else
        descendingInsertionSort(array, length);
}

void ascendingInsertionSort(int *array, int length)
{
    if (length < 2)
        return;

    for (int i = 1; i < length; i++)
    {
        int j = i - 1;
        while (j >= 0 && array[j] > array[j + 1])
        {
            swap(&array[j], &array[j + 1]);
            j--;
        }
    }
}

void descendingInsertionSort(int *array, int length)
{
    if (length < 2)
        return;

    for (int i = 1; i < length; i++)
    {
        int j = i - 1;
        while (j >= 0 && array[j] < array[j + 1])
        {
            swap(&array[j], &array[j + 1]);
            j--;
        }
    }
}