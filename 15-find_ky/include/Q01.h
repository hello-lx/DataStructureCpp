#ifndef Q01_H
#define Q01_H
#include<iostream>
using namespace std;

// 顺序表
typedef struct SeqList
{
    int *elem;
    int length;
} SeqList;

SeqList* createSeqList(int size);

// 折半查找： 一定是顺序表
void binarySearch();


#endif