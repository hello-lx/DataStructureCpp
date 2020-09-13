#ifndef _1BUBBLE_H
#define _1BUBBLE_H

#include <iostream>
using namespace std;

/**
 *      冒泡排序
 */

typedef struct DYNARY_ARRAY
{
    /* data */
    int* pAddr;
    int size;
    int capacity;
} Dynary_Array;

Dynary_Array* addArr(Dynary_Array* arr, int value);

Dynary_Array* removeArr(Dynary_Array* arr, int pos);

Dynary_Array* editArr(Dynary_Array* arr, int pos, int val);

void printArr(Dynary_Array* arr);

int findArr(const Dynary_Array* arr, int val);

void testBubbleSort();
#endif