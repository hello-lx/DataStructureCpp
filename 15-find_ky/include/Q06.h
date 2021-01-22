#ifndef Q06_H
#define Q06_H
#include<iostream>
using namespace std;

/** 串
 * 存储结构：定长顺序存储(数组)、堆(动态)分配存储(链表)
 * 
 * 字符串匹配
 * 1. 暴力匹配
 * 2. KMP算法
 */

// 1. 暴力匹配
int hardMatch(string haystack, string needle);


// 2. KMP算法
void cal_next(char *str, int *next, int len);
int KMP(char *str, int slen, char *ptr, int plen);

#endif