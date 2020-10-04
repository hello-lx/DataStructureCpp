#ifndef Q04_H
#define Q04_H
#include<iostream>
using namespace std;
#define N 100


/**
 *      4. 归并排序
 */

// time: O(n*log2(n))  space: O(n)       稳定    顺序存储和链式存储
void MergeSort(int A[], int low, int high);

void Merge(int A[], int low, int mid, int high);

void test04(int n);

#endif