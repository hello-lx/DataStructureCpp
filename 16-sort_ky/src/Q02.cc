#include "Q02.h"

// (1) 冒泡排序    time: O(n^2) space: O(1)  稳定  顺序存储+链式存储
void bubbleSort(int A[], int n){
    for(int i=0; i<n; i++)
    {
        bool flag = false;  // 当剩下的元素都为有序时，不需要再继续排序了
        for(int j=n-1; j>i; j--)  // 将最小的值排到前面去
            if(A[j-1] > A[j]){
                int temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
                flag = true;
            }
        if(flag == false)
            return;
    }
}


// (2) 快速排序  time: O(nlog2(n)) O(n^2)  space: O(log2(n)) O(n)  不稳定  顺序存储+链式存储
int Partition(int A[], int low, int high){
    int pivot = A[low];
    while (low < high)
    {
        while (low<high && A[high]>=pivot)
            high--;
        while (low<high && A[low]<=pivot)
            low++;
        A[high] = A[low];
    }
    
    A[low] = pivot;

    return low;
}

void quickSort(int A[], int low, int high){
    if(low<high){
        int pivotpos = Partition(A, low, high);
        quickSort(A, low, pivotpos-1);
        quickSort(A, pivotpos+1, high);
    }
}
