#include "Q03.h"

// (1) 简单选择排序 time: O(n^2)   space: O(1)    不稳定  顺序存储(链式存储)
void selectSort(int A[], int n){
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i+1; j<n; j++)
            if(A[j] < A[min])
                min=j;
        if(min != i)
        {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}


// (2) 堆排序: 大根堆  time: O(1) O(n*log2(n))   space: O(1) O(n^2)        不稳定  顺序存储(链式存储)
void AdjustDown(int A[], int k, int len){
    A[0] = A[k];
    for(int i=2*k; i<=len; i*=2){
        if(i<len && A[i] < A[i+1])
            i++;
        
        if(A[0] >= A[i])
            break;
        else
        {
            A[k] = A[i];
            k = i;
        }
    }

    A[k] = A[0];
}

void AdjustUp(int A[], int k, int len){
    A[0] = A[k];
    int i=k/2;
    while(i>0 && A[i]<A[0]){
        A[k] = A[i];
        k = i;
        i = k/2;
    }
    A[k] = A[0];
}

void buildMaxHeap(int A[], int len){
    for(int i=len/2; i>0; i--)
        AdjustDown(A, i, len);
}

void HeapSort(int A[], int len){
    buildMaxHeap(A, len);
    for(int i=len; i>1; i--){
        int temp = A[i];
        A[i] = A[1];
        A[1] = temp;
        AdjustDown(A, i, i-1);
    }
}