#ifndef Q02_H
#define Q02_H
#include<iostream>
using namespace std;

// 分块查找: 块中的元素是无序的，前一块的所有元素都小于(或大于)后一块的所有元素
struct index
{
    int key;
    int start;
    int end;
} index[4];

int search(int key, int a[]);

void blockSearch();

#endif