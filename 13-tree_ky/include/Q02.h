#ifndef Q02_H
#define Q02_H

// #include "base.h"
/**
 * 树应用一：并查集（双亲表示法）
*/

#define N 5

class TreeApp2
{
public:
    TreeApp2();
    ~TreeApp2();

    int findRecursion(int x);
    int findNonRecursion(int x);
    void unionTree(int, int);
    void print();

private:
    int farther[N];
    int height[N];
};

#endif