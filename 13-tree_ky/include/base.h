#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using namespace std;

/** 定义各种树的数据结构
 * 树存储结构：
        * 双亲表示法       寻找双亲节点效率高，寻找孩子节点效率低
        * 孩子表示法       寻找双亲节点效率低，寻找孩子节点效率高
        * 孩子兄弟表示法    寻找双亲节点效率低，寻找孩子节点效率高，方便实现树转换为二叉树
 
 * 二叉树：
 * 类型：
        * 普通二叉树
        * 二叉排序树：左树的节点小于根节点，右树的节点大于根节点
        * 完全二叉树：每个节点都与高度为h的满二叉树中编号1~N的节点一一对应
        * 例如：1～5的完全二叉树：  1
        *                      /  \
        *                     2    3
        *                    / \
        *                   4   5
        * 满二叉树：每一层的叶子节点均满
        * 平衡二叉树：树上任意节点的左子树和右子树的深度差小于1
        * 非空二叉树：(1) N0 = N2 + 1;  (2)第k层最多有2^(k-1)个节点(k>=1);  
 * 二叉树存储结构：
        * 顺序存储
        * 链式存储
*/

class Node
{
public:
        Node();
        Node *SearchNode(int nodeIndex);
        void DeleteNode();
        void PreorderTraversal();
        void InorderTraversal();
        void PostorderTraversal();

        int index;
        int data;

        Node* pLChild;
        Node* pRChild;
        Node* pParent;
};

class Tree
{
public:

        Tree();//创建树
        ~Tree();//销毁树
        Node *SearchNode(int nodeIndex);//搜索结点
        bool AddNode(int nodeIndex, int direction, Node* pNode);//添加结点
        void showTree(Node* node);
        bool DeleteNode(int nodeIndex, Node* pNode);//删除结点
        Node* getRootNode();

        void PreorderTraversal();//前序遍历
        void InorderTraversal();//中序遍历
        void PostorderTraversal();//后序遍历

private:
        Node * m_pRoot;
};



#endif