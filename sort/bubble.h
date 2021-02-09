#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "common.h"

/*
    parameters:
        array: an int array to be sorted
        length: the length of the array
        order: the order to sort, including DESC and ASC
*/
void bubbleSort(int *array, int length, Order order);

/*
    optimized version of bubble sort efficient for arrays that are already sorted

    parameters:
        array: an int array to be sorted
        length: the length of the array
        order: the order to sort, including DESC and ASC
*/
void optimizedBubbleSort(int *array, int length, Order order);

#endif