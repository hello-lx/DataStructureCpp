#ifndef Q03_H
#define Q03_H
#include<iostream>
using namespace std;

/**
 *      3. 选择排序
 *          (1) 简单选择排序
 *          (2) 堆排序: 完全二叉树    大根堆  小根堆
 */

// (1) 简单选择排序 time: O(n^2)   space: O(1)    不稳定  顺序存储和链式存储
void selectSort(int A[], int n);

// (2) 堆排序: 大根堆  time: O(n*log2(n))   space: O(1)  不稳定  顺序存储(链式存储)
void AdjustDown(int A[], int k, int len);  // 输出

void AdjustUp(int A[], int len);  // 插入

void buildMaxHeap(int A[], int len);

void HeapSort(int A[], int len);

#endif