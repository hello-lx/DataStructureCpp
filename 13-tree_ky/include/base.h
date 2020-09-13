#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using namespace std;

#define MY_TRUE 1
#define MY_FALSE 0

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

// ------------------------------------------------- Tree1 --------------------------------------------------------------
// 1. 孩子链式二叉树
typedef struct LINKCHILDNODE{  // 二叉树孩子链式节点
        char name;
        int id;
        struct LINKCHILDNODE *lChild;
        struct LINKCHILDNODE *rChild;
} LCNode;

typedef struct STACKNODETREE1{
        STACKNODETREE1* next;
        LCNode* root;
        int flag;
} StackNodeTree1;

class StackTree1{
public:
        StackTree1();
        ~StackTree1();
        
        void push(StackNodeTree1* node);
        void pop();
        StackNodeTree1* top();
        int size();
        void print();
        void clear();
        bool isEmpty();

private:
        int len=0;
        StackNodeTree1 *header=nullptr;
};

class Tree1
{
public:
        Tree1();//创建树
        ~Tree1();//销毁树
        LCNode* searchNode(LCNode* node, int nodeId);//搜索结点
        void testSearchNode();//搜索结点
        bool addNode(int nodeId, int direction, LCNode* newNode); // 添加后，仍然保持二叉树的形状
        void showTree(LCNode* node);     
        bool deleteNode(LCNode* root, int nodeId); // 删除后，仍然保持二叉树的形状
        LCNode* leafNode(LCNode* root, int nodeId);

        LCNode* getRootNode();

        void preOrderRecursion(LCNode *node);//前序递归遍历
        void midOrderRecursion(LCNode *node);//中序递归遍历
        void postOrderRecursion(LCNode *node);//后序递归遍历
        
        StackNodeTree1* createStackNode(LCNode* node, int flag);
        void preOrderNonRecursion(LCNode *node);//前序非递归遍历
        void midOrderNonRecursion(LCNode *node);//中序非递归遍历
        void postOrderNonRecursion(LCNode *node);//后序非递归遍历

        void testTraversal(LCNode* node);

        LCNode* getRoot();
private:
        LCNode* root;
        string NLR, LNR, LRN;
};

// ------------------------------------------------- Tree2 --------------------------------------------------------------
// 2. 双亲链接二叉树

// ------------------------------------------------- Tree3 --------------------------------------------------------------
// 3. 孩子顺序二叉树

// ------------------------------------------------- Tree4 --------------------------------------------------------------
// 4. 双亲顺序二叉树

#endif