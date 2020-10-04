#ifndef Q02_H
#define Q02_H
#include<iostream>
using namespace std;

/**
 *      2. 交换排序
 *          (1) 冒泡排序
 *          (2) 快速排序
 */

// (1) 冒泡排序    time: O(n^2) space: O(1)  稳定  顺序存储+链式存储
void bubbleSort(int A[], int n);

// (2) 快速排序  time: O(nlog2(n)) O(n^2)  space: O(log2(n)) O(n)  不稳定  顺序存储+链式存储
int Partition(int A[], int low, int high);

void quickSort(int A[], int low, int high);

#endif