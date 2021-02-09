#include "selection.h"

void ascendingSelectionSort(int *array, int length);
void descendingSelectionSort(int *array, int length);

void selectionSort(int *array, int length, Order order)
{
    if (order == ASC)
        ascendingSelectionSort(array, length);
    else
        descendingSelectionSort(array, length);
}

void descendingSelectionSort(int *array, int length)
{
    int maxIndex;
    for (int i = 0; i < length - 1; i++)
    {
        maxIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[maxIndex] < array[j])
                maxIndex = j;
        }

        swap(&array[i], &array[maxIndex]);
    }
}

void ascendingSelectionSort(int *array, int length)
{
    int minIndex;
    for (int i = 0; i < length - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (array[minIndex] > array[j])
                minIndex = j;
        }

        swap(&array[i], &array[minIndex]);
    }
}