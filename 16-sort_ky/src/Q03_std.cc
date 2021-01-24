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


// (2) 堆排序: 小根堆  time: O(n*log2(n))   space: O(1)  不稳定  顺序存储(链式存储)
void buildMaxHeap(int A[], int n)  //建立最大堆
{
    // 从最后一个非叶子节点（n/2-1）开始自底向上构建，
    for (int i = n / 2-1; i >= 0; i--)  //从（n/2-1）调用一次maxHeapIfy就可以得到最大堆
         maxHeapIfy(A, i, n);
}

void maxHeapIfy(int A[], int i,int n)  //将i节点为根的堆中小的数依次上移,n表示堆中的数据个数
{
    int l = 2 * i + 1;   //i的左儿子
    int r = 2 * i + 2;  //i的右儿子
    int largest = i;   //先设置父节点和子节点三个节点中最大值的位置为父节点下标

    if (l < n && A[l] > A[largest])
         largest = l;
    
    if (r < n && A[r] > A[largest])
         largest = r;

    if (largest != i)    //最大值不是父节点，交换
    {
         swap(A[i],A[largest]);
         maxHeapIfy(A, largest, n);  //递归调用，保证子树也是最大堆
    }
}

void heapSort(int A[], int n)  //堆排序算法
{
    buildMaxHeap(A, n);  //先建立堆
    for (int i = n-1; i >0; i--)
    {
        // 将根节点(最大值)与数组待排序部分的最后一个元素交换,这样最终得到的是递增序列
        swap(A[0], A[i]);
        // 待排序数组长度减一,只要对换到根节点的元素进行排序，将它下沉就好了。
        maxHeapIfy(A, 0, i);
    }
}
