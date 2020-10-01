#ifndef Q03_H
#define Q03_H

/**
 * 树应用二：二叉排序树(二叉查找树)
 * 树的左节点小于右节点
 * 
 *                          45
 *                         /  \
 *                        12  53
 *                       /  \   \
 *                      3   37  100
 *                         /    /
 *                        24   61
 *                               \
 *                               90
 *                              /
 *                             78
 * 
 * https://www.cnblogs.com/sench/p/7783331.html
*/


class BSTNode{   // Binary Search Tree Node
public:
    int key;   // 节点值
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
    
    // 构造函数
    BSTNode(): parent(nullptr){}
    BSTNode(int k, BSTNode* l, BSTNode* r, BSTNode* p): key(k), left(l), right(r), parent(p){}
};


class BSTree
{
public:
    BSTree(): root(nullptr){}
    ~BSTree();

    BSTNode* getRoot() { return root; }

    /* 前序、中序、后序遍历 */
    void preOrder(BSTNode* node);
    void inOrder(BSTNode* node);
    void postOrder(BSTNode* node);
    
    void insert(BSTNode* rootNode, BSTNode* node);
    void insert(int key);

    /* 查找二叉树中键值为key的节点并返回 */
    BSTNode* search(BSTNode* node, int key);

    /* 查找二叉树中键值key最小的节点并返回 */
    BSTNode* minimum(BSTNode* node);

    /* 查找二叉树中键值key最大的节点并返回 */
    BSTNode* maximum(BSTNode* node);

    /* 查找二叉树节点node的后继节点 */
    BSTNode* successor(BSTNode* node);

    /* 查找二叉树节点node的前驱节点 */
    BSTNode* predecessor(BSTNode* node);

    /* 移除节点 */
    BSTNode* remove(BSTNode* node);

    /* 查找二叉树节点node的前驱节点 */
    void destroy(BSTNode* node);

private:
    BSTNode* root;
};


#endif