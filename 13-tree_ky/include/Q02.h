#ifndef Q02_H
#define Q02_H

#include "base.h"
/**
 * 树应用一：并查集（双亲表示法）
 *    归并两条或多条树
 *   
 *   初始化： [ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9 ]
 *           [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1]
 *      （1）       （2）       （3）
 *        0          1          2
 *      / | \       / \        / \
 *     6  7  8     4   9      3   5
 *
 *     [ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9 ]
 *     [-1, -1, -1,  2,  1,  2,  0,  0,  0,  1]
 *   
 *   将树（二）合并至树（一）
 *      （1）
 *         0 
 *       /|\ \
 *      6 7 8 1
 *           / \
 *          4   9
 *     [ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9 ]
 *     [-1,  0, -1,  2,  1,  2,  0,  0,  0,  1]
 *   
 */

#define N 10

class TreeApp2
{
public:
    TreeApp2();
    ~TreeApp2();

    int findRecursion(int x);
    int findNonRecursion(int x);
    void unionTree(int, int);
    void print();
    void test();

private:
    int farther[N];
};

#endif