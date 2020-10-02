#include "Q03.h"
#include <iostream>
using namespace std;


BSTree::~BSTree()
{
    if(root != nullptr)
    {
        destroy(root);
    }
}


BSTNode* BSTree::getRoot()
{
    return root;
}


// 前序递归
void BSTree::preOrder(BSTNode* node)
{
    if(node != nullptr)
    {
        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}


// 中序递归
void BSTree::inOrder(BSTNode* node)
{
    if(node == nullptr)
        return;

    inOrder(node->left);
    cout << node->key << " ";
    inOrder(node->right);
}


// 后序递归
void BSTree::postOrder(BSTNode* node)
{
    if(node == nullptr)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->key << " ";
}


void BSTree::insert(BSTNode* rootNode, BSTNode* node)
{
    BSTNode* y = nullptr;  // insert node parent
    BSTNode* x = rootNode;

    // 找到要插的位置
    while (x != nullptr)
    {
        y = x;
        if (node->key > x->key)
            x = x->right;
        else
            x = x->left;
    }
    
    // 插入节点
    node->parent = y;
    if (y == nullptr)
        this->root = node;
    else if (y->key > node->key)
        y->left = node;
    else
        y->right = node;
}


void BSTree::insert(int key)
{
    BSTNode* node = new BSTNode(key, nullptr, nullptr, nullptr);
    insert(root, node);
}


BSTNode* BSTree::search(BSTNode* node, int key)
{
    // 非递归
    // BSTNode* x = node;
    // while (x != nullptr)
    // {
    //     if (x->key == key)
    //         break;
    //     else if (x->key > key)
    //         x = x->left;
    //     else
    //         x = x->right;        
    // }
    // return x;


    // 递归
    if(node == nullptr || node->key == key)
        return node;
    
    if(node->key > key)
        return search(node->left, key);
    else
        return search(node->right, key);
}


BSTNode* BSTree::minimum(BSTNode* node)
{
    // 递归
    if(node->left == nullptr)
        return node;
    return minimum(node->left);

    // 非递归
    // BSTNode* x = node;
    // BSTNode* y = nullptr;
    // while (x != nullptr)
    // {
    //     y = x;
    //     x = x->left;
    // }

    // return y;    
}


BSTNode* BSTree::maximum(BSTNode* node)
{
    // 递归
    if(node->right == nullptr)
        return node;
    return maximum(node->right);
    
    // 非递归
    // maximum(node);
    // BSTNode* x = node;
    // BSTNode* y = nullptr;
    // while (x != nullptr)
    // {
    //     y = x;
    //     x = x->right;
    // }

    // return y;    
}

// 结点node的后继结点是所有键值大于node的结点中的最小结点，也就是node的右子树的最小结点。
BSTNode* BSTree::successor(BSTNode* node)
{
    // 若结点node的右子树非空，则右子树的最小结点即为node的后继结点；
    // 若结点node的右子树为空:
    //              若结点node为左孩子，则node的后继结点即为其父结点；
    //              若结点node为右孩子，则查找node的最低的父结点，且该父结点要有左孩子，此最低父结点即为node的后继结点。
    
    if(node->right != nullptr)
        return minimum(node->right);
    
    BSTNode* x  = node;
    BSTNode* px = x->parent;
    while (px != NULL && x == px->right)
    {
        x = px;
        px = px->parent;
    }

    return px; // 当 node == root，pnode = nullptr
}

// 结点node的前驱结点是所有键值小于node的结点中的最大结点，也就是node的左子树的最大结点；
BSTNode* BSTree::predecessor(BSTNode* node)
{
    // 若结点node的左子树非空，则左子树的最大结点即为node的前驱结点；
    // 若结点node的左子树为空: 
    //              若node为右孩子，则node的前驱结点为node的父结点；
    //              若node为左孩子，则查找结点node的最低的父结点，且该父结点要有右孩子，此最低父结点即为node的前驱结点。
    
    if (node->left != nullptr)
        return maximum(node);
    
    BSTNode* x = node;
    BSTNode* px = x->parent;
    while (px != nullptr && x == px->left)
    {
        x = px;
        px = px->parent;
    }
    
    return px;
}


/**
 * 假设要删除的结点为*p(p为指向要删除结点的指针)，其双亲结点为*f，不失一般性，可设*p是*f的左孩子。
 * 
 *（1）若*p结点为叶子结点，即PL和PR均为空，则只需修改f->left为空即可；
 * 
 *（2）若*p结点只有左子树PL或者只有右子树PR，这只需令PL和PR直接成为f的左孩子即可；
 * 
 *（3）若*p结点的左子树和右子树均不为空，在删去*p之后，为保持其他元素之间的相对位置不变，可以有两种做法：
 * 
 * 　（3.1）做法一：令*s为*p的左子树PL的最右结点，则令*p的左子树PL为*f的左子树，*p的右子树PR为*s的右子树；
 * 
 * 　（3.2）做法二：令*p的直接前驱（或直接后继）替代*p，然后再从二叉排序树中删除它的直接前驱（或直接后继）。
 */
BSTNode* BSTree::remove(BSTNode* node, int key)
{
    BSTNode* n = search(node, key);
    // printf("%d\n", n->key);
    
    if(n != nullptr)
    {
        if(n->left == nullptr && n->right == nullptr)  // 叶子节点
        {
            if(n->parent == nullptr)  // 根节点
                return n;
            else if(n->parent->left == n)  // 判断删除的节点是在左孩子还是右孩子
                n->parent->left = nullptr;
            else
                n->parent->right = nullptr;
        }
        else if(n->left == nullptr)  // 左子树为空
        {
            if(n->parent == nullptr)
            {
                this->root = n->right;
                n->right->parent = nullptr;
            }
            else if(n->parent->left == n)
                n->parent->left = n->right;
            else
                n->parent->right = n->right;
        }
        else if(n->right == nullptr)  // 右子树为空
        {
            if(n->parent == nullptr)
            {
                this->root = n->left;
                n->left->parent = nullptr;
            }
            else if(n->parent->left == n)
                n->parent->left = n->left;
            else
                n->parent->right = n->left;
        }
        else  // n 的左右子树均不为空， 采用 “做法一”
        {
            // 将节点n的右孩子接到节点n的前驱节点后
            BSTNode* lnode = n->left;
            while (lnode->right)
                lnode = lnode->right;

            lnode->right = n->right;
            n->right->parent = lnode;
            
            
            if (n->parent == nullptr)  // 直接将左孩子设置为根节点
            {
                this->root = n->left;
                this->root->parent = nullptr;
            }
            else if(n->parent->left == n)     // 节点n在父亲的左节点上
            {
                n->parent->left = n->left;
                n->left->parent = n->parent;
            }
            else                              // 节点n在父亲的右节点上
            {
                n->parent->right = n->left;
                n->left->parent = n->parent;
            }
        }
    }

    return n;
}

// 
void BSTree::destroy(BSTNode* node)
{
    if(node == nullptr)
        return;
    
    destroy(node->left);
    destroy(node->right);
    delete node;
}