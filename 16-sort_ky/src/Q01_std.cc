#include "Q01.h"

// (1) 直接插入排序   O(n^2)   稳定   顺序存储+链式存储
void insertSort(int A[], int n){  // A[0] == NULL
    int i, j;
    for(int i=2; i<=n; i++){
        A[0] = A[i];
        // 向后移一位
        for(j=i-1; A[0]<A[j]; j--)
            A[j+1] = A[j];
        A[j+1] = A[0];
    }
}


// (2) 折半插入排序   O( n^2 )   稳定   顺序存储
void BInsertSort(int A[], int n){  // A[0] == NULL
    int i, j;
    int low, high, mid;
    for(i=2; i<=n; i++){
        A[0] = A[i];

        low = 1; high = i-1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if(A[mid] > A[0])
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        for(j=i-1; j>=high+1; j--)
            A[j+1] = A[j];
        A[high+1] = A[0];
    }
}


// (3) 希尔排序(缩小增量排序)   将序列分成dk个小批量数据，然后对每个小批量数据进行插入排序，dk -= 1, 再进行相同的插入排序，直到 dk = 1
// O( n^2 )   不稳定   顺序存储
void ShellSort(int A[], int n){  // A[0] == NULL
    int dk, i, j;
    for(dk=n/2; dk>=1; dk=dk/2)
        for(i=dk+1; i<=n; ++i)
            if(A[i] < A[i-dk]){
                A[0] = A[i];
                for(j=i-dk; j>0 && A[0]<A[j]; j-=dk)
                    A[j+dk] = A[j];
                A[j+dk] = A[0];
            }
}