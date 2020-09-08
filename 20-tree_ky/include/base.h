#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using namespace std;

// 定义各种数的数据结构

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

// template<typename T>
// struct BinTN   // binary tree node
// {
//         T name;
//         BinTN<T> *left;
//         BinTN<T> *right;
//         BinTN(T x=T()): name(x), left(NULL), right(NULL){}
// };



// template<typename T>
// class BTreeArr
// {
// private:
//         T data[];
//         int count;

// public:
//         BTreeArr(int count);
//         ~BTreeArr();

        
// };



#endif