#ifndef Q43_H
#define Q43_H

#include <iostream>
#include <string>
#include "base.h"
using namespace std;


/*
4.3-综合题03： 二叉树自下而上、从右到左的层次遍历算法

void InvertLevel(Tree1* bt){
    Stack s;
    Queue q;
    StackNodeTree1* n;
    if(bt != NULL){
        InitStack(s);
        InitQueue(q);
        EnQueue(q);  // 进队列
        while(IsEmpty(q) == false){
            DeQueue(q, n);  // 出队列
            Push(s, n);  // 进栈
            if(p->lChild)
                EnQueue(q, n->lChild);
            if(p->rChild)
                EnQueue(q, n->rChild);
        }

        while(IsEmpty(s) == false){
            Pop(s, n);
            visi(p->data);
        }
    }
}
*/

/*
4.3-综合题05： 链式二叉树，用非递归求二叉树的高度？
采用层次遍历算法，设置level记录当前节点的所在层数，设置变量last指向当前层最右节点，
每次层次遍历出队时与last指针比较，若两者相等，那么层数+1, 并让last指向下一层最右结点

// 非递归
int BtDepth(BiTree T){
    if(!T) return 0
    int front=-1, rear=-1;      // front 最近一个节点出队列的位置   rear 最近一个节点入队列的位置，当前层最右节点
    int last=0, level=0;        // last指向第一个节点的位置
    BiTree Q[MaxSize];
    Q[++rear] = T;
    BiTree p;
    while(front < rear){        // 队不空，则循环
        p = Q[++front];         // 出队
        if(p->lChild)
            Q[++rear] = p->lChild;
        if(p->rChild)
            Q[++rear] = p->rChild;
        if(front == last){
            level++;
            last = rear;        // last 指向下层最右边的节点
        }
    }

    return level;
}

// 递归
int BtDepth(BiTree T){
    if(T == NULL)
        return 0;   // 空树
    
    ldep = BiDepth(T->lChild);  // 左子树高度
    rdep = BiDepth(T->rChild);  // 右子树高度
    if(ldep > rdep)
        return ldep + 1;  // 树的高度 = 子树最大高度 + 根节点
    else
        return rdep + 1;
}

*/

/*
4.3-综合题06： 二叉树中各节点值不同，已知先序结果数组A[1...N]和中序结果数组B[1...N]，重新建立二叉树链表

*/

/*
4.3-综合题07： 链式二叉树，判断是否为完全二叉树

*/

/*
4.3-综合题08： 链式二叉树，计算所有双分支节点个数

*/


/*
4.3-综合题09： 链式二叉树，把所有结点的左右子树进行交换

*/


/*
4.3-综合题10： 链式二叉树，求先序遍历序列中第k(1 <= k <= 树结点个数)个节点的值

*/


/*
4.3-综合题11： 链式二叉树，对于每个每个元素值为x的结点，删去已它为根的子树，并释放相应的空间

*/

/*
4.3-综合题12： 二叉树，查找值为x的结点，并打印值为x的结点的所有祖先。假设值为x的结点不多于一个

*/


/*
4.3-综合题17： 判断两颗二叉树是否相似
所谓二叉树T1和T2相似，指T1和T2都是空的二叉树或只有一个根结点; 或T1的左子树和T2的左子树相似且T1的右子树和T2的右子树相似
*/


/*
4.3-综合题19： 设计WPL算法： 二叉树带权路径长度（WPL）是二叉树中所有带权路径长度之和.  二叉树结点属性： left weight right  (weight > 0)
                
*/

/*
4.3-综合题20：设计算法：将给定的表达式树(二叉树)转化为等价的中缀表达式(通过括号反映操作符的计算次序)并输出。
例如：   (a+b)*(c*(-d)) 和 (a*b) + (-(c-d))
           *                          +
        /     \                    /      \
       +       *                  *        -
      / \     / \                / \        \
     a   b   c   -              a   b        -
                  \                         / \
                   d                       c   d
二叉树结点定义：
typedef struct node{
    char data[10];
    struct node *left, *right;
} BTree;
*/


#endif