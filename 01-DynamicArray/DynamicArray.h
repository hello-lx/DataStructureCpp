#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct DYNARY_ARRAY
{
    /* data */
    int* pAddr;
    int size;
    int capacity;
} Dynary_Array;

Dynary_Array* initArr();

Dynary_Array* addArr(Dynary_Array* arr, int value);

Dynary_Array* removeArrByPos(Dynary_Array* arr, int pos);

Dynary_Array* removeArrByValue(Dynary_Array* arr, int val);

Dynary_Array* editArr(Dynary_Array* arr, int pos, int val);

void printArr(Dynary_Array* arr);

int findArr(const Dynary_Array* arr, int val);

void Clear_Array(Dynary_Array* arr);

#endif