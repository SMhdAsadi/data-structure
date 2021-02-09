#include "merge.h"

void ascendingMergeSort(int *array, int start, int end);
void descendingMergeSort(int *array, int start, int end);
void ascendingMerge(int *array, int leftStart, int leftEnd, int rightEnd);
void descendingMerge(int *array, int leftStart, int leftEnd, int rightEnd);
void copyArray(int *src, int start, int end, int *dest);
void addToArray(int *array, int *arrayPointer, int *copyPointer, int number);

void mergeSort(int *array, int length, Order order)
{
    if (order == ASC)
        ascendingMergeSort(array, 0, length - 1);
    else
        descendingMergeSort(array, 0, length - 1);
}

void descendingMergeSort(int *array, int start, int end)
{
    if (end <= start)
        return;

    int middle = (start + end) / 2;
    descendingMergeSort(array, start, middle);
    descendingMergeSort(array, middle + 1, end);

    descendingMerge(array, start, middle, end);
}

void ascendingMerge(int *array, int leftStart, int leftEnd, int rightEnd)
{
    int rightStart = leftEnd + 1;
    int leftSize = leftEnd - leftStart + 1;
    int rightSize = rightEnd - rightStart + 1;

    int leftCopy[leftSize], rightCopy[rightSize];
    copyArray(array, leftStart, leftEnd, leftCopy);
    copyArray(array, rightStart, rightEnd, rightCopy);

    int leftPointer = 0, rightPointer = 0, arrayPointer = leftStart;

    while (leftPointer < leftSize && rightPointer < rightSize)
    {
        if (leftCopy[leftPointer] <= rightCopy[rightPointer])
            addToArray(array, &arrayPointer, &leftPointer, leftCopy[leftPointer]);
        else
            addToArray(array, &arrayPointer, &rightPointer, rightCopy[rightPointer]);
    }

    while (leftPointer < leftSize)
        addToArray(array, &arrayPointer, &leftPointer, leftCopy[leftPointer]);

    while (rightPointer < rightSize)
        addToArray(array, &arrayPointer, &rightPointer, rightCopy[rightPointer]);
}

void ascendingMergeSort(int *array, int start, int end)
{
    if (end <= start)
        return;

    int middle = (start + end) / 2;
    ascendingMergeSort(array, start, middle);
    ascendingMergeSort(array, middle + 1, end);

    ascendingMerge(array, start, middle, end);
}

void descendingMerge(int *array, int leftStart, int leftEnd, int rightEnd)
{
    int rightStart = leftEnd + 1;
    int leftSize = leftEnd - leftStart + 1;
    int rightSize = rightEnd - rightStart + 1;

    int leftCopy[leftSize], rightCopy[rightSize];
    copyArray(array, leftStart, leftEnd, leftCopy);
    copyArray(array, rightStart, rightEnd, rightCopy);

    int leftPointer = 0, rightPointer = 0, arrayPointer = leftStart;

    while (leftPointer < leftSize && rightPointer < rightSize)
    {
        if (leftCopy[leftPointer] >= rightCopy[rightPointer])
            addToArray(array, &arrayPointer, &leftPointer, leftCopy[leftPointer]);
        else
            addToArray(array, &arrayPointer, &rightPointer, rightCopy[rightPointer]);
    }

    while (leftPointer < leftSize)
        addToArray(array, &arrayPointer, &leftPointer, leftCopy[leftPointer]);

    while (rightPointer < rightSize)
        addToArray(array, &arrayPointer, &rightPointer, rightCopy[rightPointer]);
}

void copyArray(int *src, int start, int end, int *dest)
{
    int destIndex = 0;
    for (int i = start; i <= end; i++)
    {
        dest[destIndex] = src[i]; 
        destIndex++;
    }
}

void addToArray(int *array, int *arrayPointer, int *copyPointer, int number)
{
    array[*arrayPointer] = number;
    (*arrayPointer)++;
    (*copyPointer)++;
}