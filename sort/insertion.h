#ifndef INSERTION_H
#define INSERTION_H
#include "common.h"

/*
    parameters:
        array: an int array to be sorted
        length: the length of the array
        order: the order to sort, including DESC and ASC
*/
void insertionSort(int *array, int length, Order order);

#endif