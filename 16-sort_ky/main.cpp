#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Q01.h>
#include <Q02.h>
#include <Q03.h>
#include <Q04.h>
#include <Q05.h>

void printArr(int A[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout << A[i] << ' ';
    }
    cout << endl;
}

void printVec(vector<int> &A, int size)
{
    for(int i=0; i<size; i++)
    {
        cout << A[i] << ' ';
    }
    cout << endl;
}

void test01()
{
    int A[] = {-1, 9, 3, 2, 7, 6, 4, 1, 5};
    int size = sizeof(A) / sizeof(int);
    // printArr(A, size);
    // insertSort(A, size);
    // printArr(A, size);

    // printArr(A, size);
    // BInsertSort(A, size);
    // printArr(A, size);

    // printArr(A, size);
    // ShellSort(A, size);
    // printArr(A, size);
}

void test02()
{
    int A[] = {9, 3, 2, 7, 6, 4, 1, 5};
    int size = sizeof(A) / sizeof(int);
    
    // printArr(A, size);
    // bubbleSort(A, size);
    // printArr(A, size);

    // printArr(A, size);
    // int low=0, high=size-1;
    // quickSort(A, low, high);
    // printArr(A, size);
}

void test03()
{
    int A[] = {9, 3, 2, 7, 6, 4, 1, 5};
    int size = sizeof(A) / sizeof(int);

    // printArr(A, size);
    // selectSort(A, size);
    // printArr(A, size);

    // printArr(A, size);
    // heapSort(A, size);
    // printArr(A, size);
}

void test04()
{
    int data[] = {9,6,7,22,20,33,16,20};
    const int length = 8;
    int result[length];
    cout << "Before sorted:" << endl;
    for(int i = 0;i < length;++i)
        cout << data[i] << "  ";
    cout << endl;
    cout << "After sorted:" << endl;
    merge_sort(data,0,length-1,result);
    for(int i = 0;i < length;++i)
        cout << data[i] << "  ";
    cout << endl;

    return;
}

void test05()
{
    int data[] = {9,6,7,22,20,33,16,20};
    const int length = 8;

    printArr(data, length);
    radixsort(data, length);    
    printArr(data, length);
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    test03();
    // test04();
    test05();
    
    return 0;
}

