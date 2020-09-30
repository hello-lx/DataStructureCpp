#ifndef Q02_H
#define Q02_H

// #include "base.h"
/**
 * 树应用一：并查集（双亲表示法）
*/

#define N 1001

class TreeApp1
{
public:
    TreeApp1();
    ~TreeApp1();

    int findRecursion(int x);
    int findNonRecursion(int x);
    void unionTree(int, int);
    void test();

private:
    int farther[N];
    int height[N];
};

#endif