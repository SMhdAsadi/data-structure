#ifndef COMMON_H
#define COMMON_H

/*
    the order for sorting
    ASC
    DESC
*/
typedef enum 
{
    ASC,
    DESC
} Order;


void swap(int *a, int *b);
void printArray(int *array, int length);

#endif