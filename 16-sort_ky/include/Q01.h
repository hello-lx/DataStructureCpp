#ifndef Q01_H
#define Q01_H
#include<iostream>
using namespace std;

/**
 *      1. 插入排序
 *          (1) 直接插入排序
 *          (2) 折半插入排序
 *          (3) 希尔排序
 */

// (1) 直接插入排序   O( n^2 )   稳定   顺序存储+链式存储
void insertSort(int A[], int n);

// (2) 折半插入排序   O( n^2 )   稳定   顺序存储
void BInsertSort(int A[], int n);

// (3) 希尔排序(缩小增量排序)
void ShellSort(int A[], int n);


#endif