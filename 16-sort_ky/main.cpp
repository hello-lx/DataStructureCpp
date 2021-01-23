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

void test01()
{
    int A[] = {-1, 9, 3, 2, 7, 6, 4, 1, 5};
    int size = sizeof(A) / sizeof(int);
    // printArr(A, size);
    // insertSort(A, size);
    // printArr(A, size);

    printArr(A, size);
    BInsertSort(A, size);
    printArr(A, size);

    
}

void test02()
{}

void test03()
{}

void test04()
{}

void test05()
{}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    test03();
    test04();
    test05();
    
    return 0;
}

