#ifndef Q04_H
#define Q04_H
#include<iostream>
using namespace std;


/**
 *      4. 归并排序
 */

// time: O(n*log2(n))  space: O(n)       稳定    顺序存储和链式存储
void merge_sort(int *data, int start, int end, int *result);
void merge(int *data,int start,int end,int *result);
#endif