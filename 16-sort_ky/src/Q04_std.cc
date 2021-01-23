#include "Q04.h"

void MergeSort(int A[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}

int *B = (int*)malloc((N+1) * sizeof(int));
void Merge(int A[], int low, int mid, int high){
    for(int k=low; k<=high; k++)
        B[k] = A[k];
    
    int i, j, k;
    for(i=low, j=mid+1, k=i; i<mid && j <= high; k++)
    {
        if(B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }

    while (i <= mid)
        A[k++] = B[i++];

    while (j <= high)
        A[k++] = B[j++];
}

void test04(int n){
    int A[] = {};
    int low, mid, high;
    low = 0;
    high = n-1;
    mid = (low + high) / 2;

    // Merge(A, B, low, mid, high);
}

