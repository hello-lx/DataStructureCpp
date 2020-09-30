#ifndef Q03_H
#define Q03_H

#include "base.h"
/**
 * 树应用二：二叉排序树
 * 树的左节点小于右节点
*/

class BinBalanceTree
{
public:
    BinBalanceTree();
    ~BinBalanceTree();

    // 小于根节点，查找左子树；大于根节点，查找右子树
    find(int x);
    

private:
    int x;
};


#endif