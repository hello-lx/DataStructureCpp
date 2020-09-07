#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using namespace std;

// 定义各种数的数据结构

template<typename T>
struct BinTN   // binary tree node
{
        T name;
        BinTN<T> *left;
        BinTN<T> *right;
        BinTN(T x=T()): name(x), left(NULL), right(NULL){}
};

#endif