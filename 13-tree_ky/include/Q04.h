#ifndef Q03_H
#define Q03_H

#include "base.h"
/**
 * (二叉)树应用三：平衡二叉树
 * 平衡二叉树(AVL Tree)首先要满足二叉树的定义,如下
    二叉排序树或者是一棵空树，或者是具有下列性质的二叉树：
    若左子树不空，则左子树上所有结点的值均小于它的根结点的值；
    若右子树不空，则右子树上所有结点的值均大于它的根结点的值；
    左、右子树也分别为二叉排序树；
    没有键值相等的节点。
    平衡度是左子树高度减去右子树高度，平衡度只能是-1,+1,0
 * 
 * 
 * https://www.cnblogs.com/Java-Starter/p/10192034.html
*/

template<class K, class V>
struct AVLTNode //  平衡树节点
{
   K key;  // 树权值
   V value; 
   int bf;

   AVLTNode<K, V>* parent;
   AVLTNode<K, V>* left;
   AVLTNode<K, V>* right;

   AVLTNode(const K& _key=K(), const V& _value=V()): key(_key),
      value(_value), bf(0), left(NULL), right(NULL){}
   
};


#endif