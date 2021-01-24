#include "Q03.h"

// (1) 简单选择排序 time: O(n^2)   space: O(1)    不稳定  顺序存储(链式存储)
void selectSort(int A[], int n){
    // 选择一个最小的值，和第一个值进行交换
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=i+1; j<n; j++)
        {
            if(A[j] < A[min])
                min = j;
        }

        if(min != i)
        {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}


// (2) 堆排序: 小根堆  time: O(n*log2(n))   space: O(1)  不稳定  顺序存储(链式存储)
void buildMaxHeap(int A[], int n)  //建立最大堆
{
    for(int i=n/2-1; i>=0; i--)
        maxHeapIfy(A, i, n);
}

void maxHeapIfy(int A[], int i, int n)  //将i节点为根的堆中小的数依次上移,n表示堆中的数据个数
{
    int l = 2*i+1;  // 左儿子
    int r = 2*i+2;  // 右儿子
    int largest = i;  // 假设当前最大值为父节点i

    if (l < n && A[l] > A[largest])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;
    
    if(largest != i)
    {
        swap(A[largest], A[i]);
        maxHeapIfy(A, largest, n);
    }
}

void heapSort(int A[], int n)  //堆排序算法
{
    // 1、建堆
    buildMaxHeap(A, n);
    // 2、交换和下沉
    for(int i=n-1; i>0; i--)
    {
        swap(A[i], A[0]);
        maxHeapIfy(A, 0, i);
    }
}
