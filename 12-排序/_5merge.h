#ifndef _5MERGE_H
#define _5MERGE_H

#include <iostream>
using namespace std;

/**
 *      归并排序
 * 
 *      方法描述。。。。
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

void testMergeSort();

#endif