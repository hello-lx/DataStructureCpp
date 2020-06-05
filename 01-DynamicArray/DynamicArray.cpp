#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

Dynary_Array* initArr(){
    Dynary_Array* myArr = (Dynary_Array*)malloc(sizeof(Dynary_Array));
    myArr->size = 0;
    myArr->capacity = 20;

    myArr->pAddr = (int*)malloc(sizeof(int) * myArr->capacity);

    return myArr;
}


Dynary_Array* addArr(Dynary_Array* arr, int value){
    if(arr == NULL)
        return NULL;
    
    if(arr->size == arr->capacity){
        int* newSpace = (int*)malloc(sizeof(int) * arr->capacity * 2);
        memcpy(newSpace, arr->pAddr, sizeof(int)*arr->capacity);
        free(arr->pAddr);
        arr->pAddr =  newSpace;
        arr->capacity = 2 * arr->capacity;
    }
    
    arr->pAddr[arr->size] = value;
    arr->size++;

    return arr;
}


Dynary_Array* removeArrByPos(Dynary_Array* arr, int pos){
    if(arr->size == 0)
        return NULL;
    if(pos < 0 || pos > arr->size)
        return NULL;
    
    for(int i=pos; i<arr->size-1; i++)
        arr->pAddr[i] = arr->pAddr[i+1];
    
    arr->size--;
    
    return arr;
}


Dynary_Array* removeArrByValue(Dynary_Array* arr, int val){
    if(arr->size == 0)
        return NULL;
    
    int pos = findArr(arr, val);

    if(pos == -1)
        return NULL;
    
    for(int i=pos; i<arr->size-1; i++)
        arr->pAddr[i] = arr->pAddr[i+1];
    
    arr->size--;

    return arr;
}


Dynary_Array* editArr(Dynary_Array* arr, int pos, int val){
    if(arr == NULL || pos < 0 || pos > arr->size)
        return NULL;
    
    arr->pAddr[pos] = val;

    return arr;
}


void printArr(Dynary_Array* arr){
    if (arr->pAddr == NULL)
        return;

    for(int i=0; i<arr->size; i++)
        cout << (int)arr->pAddr[i] << '\t';
    cout << endl;
}


int findArr(const Dynary_Array* arr, int val){
    int pos = -1;

    if(arr == NULL)
        return pos;
    
    for(int i=0; i<arr->size; i++)
        if(arr->pAddr[i] == val){
            pos = i;
            break;
        }
    
    return pos;
}


void Clear_Array(Dynary_Array* arr){
    if(arr == NULL)
        return;
    arr->size = 0;
}


int  At_Array(Dynary_Array* arr, int pos){
    if (arr == NULL)
        return -1;
    return arr->pAddr[pos];
}