#include "Q02.h"

// (1) 冒泡排序    time: O(n^2) space: O(1)  稳定  顺序存储+链式存储
void bubbleSort(int A[], int n){
    for(int i=0; i<n; i++)
    {
        bool flag = false;
        for(int j=n-1; j>i; j--)
        {
            if(A[j-1] > A[j])
            {
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                flag = true;
            }
        }

        // 全部已经排序完毕
        if(flag == false)
        {
            break;
        }
    }
}


// (2) 快速排序  time: O(nlog2(n)) O(n^2)  space: O(log2(n)) O(n)  不稳定  顺序存储+链式存储
int Partition(int A[], int low, int high){
    // 分别将低位指针先从左向右走和高位指针从右向左走，等两者周到同一位置的时候结束，
    // 在走的过程中不停的交换低位指针比基准大和高位指针比基准小的位置，最后交换低指针和基准的位置

    int temp;
    int left = low;
    int pivot = A[low];   // 基准，将右边比它小的值移到左边，将左边比它大的值移到右边
    while (low < high)    
    {
        // ### 若基准从左开始，则此处需要先右后左；否则相反 ###
        while (low<high && A[high]>=pivot)
            high--;
        while (low<high && A[low]<=pivot)
            low++;
        if(low < high)
        {
            temp = A[high];
            A[high] = A[low];
            A[low] = temp;
        }
    }
    
    temp = A[low];
    A[low] = pivot;
    A[left] = temp;
    return low;
}

void quickSort(int A[], int low, int high){
    if (low >= high)
        return;

    if(low<high){
        int pivotpos = Partition(A, low, high);
        quickSort(A, low, pivotpos-1);
        quickSort(A, pivotpos+1, high);
    }
}
