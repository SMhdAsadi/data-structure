#include "bubble.h"

void descendingBubbleSort(int *array, int length);
void ascendingBubbleSort(int *array, int length);
void descendingOptimizedBubbleSort(int *array, int length);
void ascendingOptimizedBubbleSort(int *array, int length);

void bubbleSort(int *array, int length, Order order)
{
    if (order == DESC)
        descendingBubbleSort(array, length);
    else
        ascendingBubbleSort(array, length);
}

void descendingBubbleSort(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] < array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

void ascendingBubbleSort(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

void optimizedBubbleSort(int *array, int length, Order order)
{
    if (order == DESC)
        descendingOptimizedBubbleSort(array, length);
    else
        ascendingOptimizedBubbleSort(array, length);
}

void descendingOptimizedBubbleSort(int *array, int length)
{
    int swapped = 0;
    for (int i = 0; i < length; i++)
    {
        swapped = 0;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}

void ascendingOptimizedBubbleSort(int *array, int length)
{
    int swapped = 0;
    for (int i = 0; i < length; i++)
    {
        swapped = 0;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
}