#include "Q43.h"


// 4.3-综合题03： 二叉树自下而上、从右到左的层次遍历算法
void hw03(){
/**                  A
 *                 /   \
 *                B     C
 *               / \   / \
 *              D   E F   G  
 */

    vector<char> names = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    vector<int> data = {1, 2, 3, 4, 5, 6, 7};
    BiTree* tree = new BiTree(names, data);
    
    SNode *sn;
    LinkStack* stack = new LinkStack();
    LinkQueue* q = new LinkQueue();
    
    // q->push();
}


// 4.3-综合题05： 链式二叉树，用非递归求二叉树的高度？
void hw05(){
}


// 4.3-综合题06： 二叉树中各节点值不同，已知先序结果数组A[1...N]和中序结果数组B[1...N]，重新建立二叉树链表
void hw06(){
}


// 4.3-综合题07： 链式二叉树，判断是否为完全二叉树
void hw07(){
}


// 4.3-综合题08： 链式二叉树，计算所有双分支节点个数
void hw08(){
}


// 4.3-综合题09： 链式二叉树，把所有结点的左右子树进行交换
void hw09(){
}


// 4.3-综合题10： 链式二叉树，求先序遍历序列中第k(1 <= k <= 树结点个数)个节点的值
void hw10(){
}


// 4.3-综合题11： 链式二叉树，对于每个每个元素值为x的结点，删去已它为根的子树，并释放相应的空间
void hw11(){
}


// 4.3-综合题12： 二叉树，查找值为x的结点，并打印值为x的结点的所有祖先。假设值为x的结点不多于一个
void hw12(){
}


// 4.3-综合题17： 判断两颗二叉树是否相似
void hw17(){
}


// 4.3-综合题19： 设计WPL算法： 二叉树带权路径长度（WPL）是二叉树中所有带权路径长度之和.  二叉树结点属性： left weight right  (weight > 0)
void hw19(){
}


// 4.3-综合题20：设计算法：将给定的表达式树(二叉树)转化为等价的中缀表达式(通过括号反映操作符的计算次序)并输出。
void hw20(){
}

