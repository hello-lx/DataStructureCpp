#include "Q04.h"
using namespace std;

// https://github.com/cjy513203427/C_Program_Base/blob/master/61.%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91/61.%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91/AVLTree.h

template<class K, class V>
bool AVLTree<K, V>::insert(const K& key, const V& value)
{
    // 1. 空树
    if(root == NULL){
        root = new AVLTNode<K, V>(key, value);
        return true;
    }

    // 2. 找到数据插入的位置
    AVLTNode<K, V>* parent = NULL, cur = root;
    while (cur)
    {
        if(cur->key < key)
        {
            parent = cur;
            cur = cur->right;
        }
        else if(cur->key > key)
        {
            parent = cur
            cur = cur->left;
        }
        else
        {
            return false;
        }
    }

    // 3. 插入数据
    cur = new AVLTNode<K, V>(key, value);
    cur->parent = parent;
    if(parent->key > key)
        parent->left = cur;
    else
        parent->right = cur;
    
    // 3. 检查添加新节点后是否平衡
    while (parent)
    {
        // 更新平衡因子
        if (cur == parent->left)
            parent->bf++;
        else if (cur == parent->right)
            parent->bf--;

        if(parent->bf == 0)
        {
            break;
        }
        else if (parent->bf == -1 || parent->bf == 1)
        {       // 回溯上升 更新祖父节点的平衡因子并检验合法性
            cur = parent;
            parent = cur->parent;
        }
        else
        {       // 2、-2 平衡因子不合法，需要进行旋转，降低高度
            if (parent->bf == -2)
            {
                if (cur->bf == -1)
                    _rotateRR(parent);
                else
                    _rotateLR(parent);
            }
            else if (parent->bf == 2)
            {
                if (cur->bf == 1)
                    _rotateLL(parent);
                else
                    _rotateRL(parent);
            }
            break;
        }
    }
    
}

/*
 *        LL（bf_x2=2,  bf_x4=1）                               （bf_x2=2,  bf_x5=1）
 *                 X1                             X2                     X1                                    X5   
 *               /    \                         /    \                 /    \                                /    \       
 *              X2     X3                     X4      X1              X2     X3                            x2      X1      
 *             / \               ===>        /       /  \            /  \                  ===>           /  \       \         
 *           X4   X5                        Y       X5   X3        X4    X5                              X4   Y      X3
 *          /                                                           /
 *         Y                                                           Y
 */
template<class K, class V>
void AVLTree<K, V>::_rotateLL(AVLTNode<K, V>*&  parent)
{
    // parent->X1  subL->X2   subLR->X5
    AVLTNode<K, V>* subL = parent->left;   // 构造左子树
    AVLTNode<K, V>* subLR = subL->right;   //subL的右子树
    AVLTNode<K, V>* ppNode = parent->parent;  // 标记为祖先节点
    parent->left = subLR;
    
    // 1. 构建parent子树 将parent和subLR链接起来
    if(subLR) 
        subLR->parent = parent;
    // 2. 构建subL子树 将subL与parent链接起来
    subL->right = parent;
    parent->parent = subL;
    // 3.将祖先节点与subL链接起来
    if(ppNode == NULL)
    {   //如果祖先为NULL，说明当前subL节点为根节点
        subL->parent = NULL;
        root = subL;
    }
    else
    {
        subL->parent = ppNode;
        if(ppNode->left == parent)
            ppNode->left = subL;
        else if(ppNode->right == parent)
            ppNode->right = subL;
    }

    // 4.重置平衡因子
    parent->bf = 0;
    subL->bf = 0;
    
    //5.更新subL为当前父节点
    parent = subL;
}


template<class K, class V>
void AVLTree<K, V>::_rotateLR(AVLTNode<K, V>*&  parent)
{
    AVLTNode<K, V>* pNode = parent;
    AVLTNode<K, V>* subR = pNode->right;
    AVLTNode<K, V>* subLR = subR->left;
    int bf = subLR->bf;

    _rotateLL(parent->right);
    _rotateRR(parent);

    if(bf == -1)            // LR(B型)
    {
        pNode->bf = 0;
        subR->bf = 1;
    }
    else if(bf == 1)        // LR(A型)
    {
        pNode->bf = -1;
        subR->bf = 0;
    }
    else                    // LR(C型)
    {
        pNode->bf = 0;
        subR->bf = 0;
    }
}


template<class K, class V>
void AVLTree<K, V>::_rotateRR(AVLTNode<K, V>*&  parent)
{
   // parent->X1  subL->X2   subLR->X5
    AVLTNode<K, V>* subR = parent->right;   // 构造左子树
    AVLTNode<K, V>* subRL = subL->left;   //subL的右子树
    AVLTNode<K, V>* ppNode = parent->parent;  // 标记为祖先节点
    parent->right = subRL;
    
    // 1. 构建parent子树 将parent和subLR链接起来
    if(subRL) 
        subRL->parent = parent;
    // 2. 构建subL子树 将subL与parent链接起来
    subR->left = parent;
    parent->parent = subR;
    // 3.将祖先节点与subL链接起来
    if(ppNode == NULL)
    {   //如果祖先为NULL，说明当前subL节点为根节点
        subR->parent = NULL;
        root = subR;
    }
    else
    {
        subR->parent = ppNode;
        if(ppNode->left == parent)
            ppNode->left = subR;
        else if(ppNode->right == parent)
            ppNode->right = subR;
    }

    // 4.重置平衡因子
    parent->bf = 0;
    subL->bf = 0;
    
    //5.更新subL为当前父节点
    parent = subR;
}


/* 
 *        LR（bf_x2=2,  bf_x4=-1）                                    （bf_x2=2,  bf_x5=-1）
 *                 X1                             X2                          X1                           X5    
 *               /    \                         /    \                      /    \                       /    \ 
 *             X2      X3                      X4     X1                  X2      X3                   X2      X1
 *            /  \               ==>            \    /  \                /  \             ==>         /  \       \
 *          X4    X5                             Y  X5  X3             X4    X5                     X4    Y       X3
 *            \                                                                \                      
 *             Y                                                                Y                          
 */
template<class K, class V>
void AVLTree<K, V>::_rotateLR(AVLTNode<K, V>*&  parent)
{   // parent->X1  subL->X2  subLR->X5
    AVLTNode<K, V>* subL = parent->left;
    AVLTNode<K, V>* subLR = subL->right;
    AVLTNode<K, V>* ppNode = parent->parent;
    parent->left = subLR;

    // 1. 构建parent子树 将parent和subLR链接起来
    if(subLR)
        subLR->parent = parent;
    // 2. 构建subL子树 将subL与parent链接起来
    subL->right = parent;
    parent->parent = subL;


}


template<class K, class V>
void AVLTree<K, V>::_rotateRL(AVLTNode<K, V>*&  parent)
{}


template<class K, class V>
int AVLTree<K, V>::_height(AVLTNode<K, V>* node)
{
    if(node == NULL)
        return 0;
    int high = 0;
    int left = _height(node->left);
    int right = _height(node->right);

    if(left > right)
        high = left;
    else
        high = right;

    if(node != root) 
        return 1 + high;
    else
        return high;
}


template<class K, class V>
bool AVLTree<K, V>::_isBalance(AVLTNode<K, V>* node)
{
    if(root == NULL)
        return true;
    
    int bf = _height(node->left) - _height(node->right);
    if(root->bf != bf)
    {
        cout << "No balance:" << root->key << endl;
        return false;
    }
    return abs(bf) < 2 && _isBalance(node->left) && _isBalance(node->right);
}


// 重新调整后，中序遍历的结果不变
template<class K, class V>
void AVLTree<K, V>::_inOrder(AVLTNode<K, V>* node)
{
    if(node==NULL)
        return;
    _inOrder(node->left);
    cout << node->key;
    _inOrder(node->right)
}


template<class K, class V>
void AVLTree<K, V>::_preOrder(AVLTNode<K, V>* node)
{
    if(node==NULL)
        return;
    cout << node->key;
    _preOrder(node->left);
    _preOrder(node->right)
}


template<class K, class V>
void AVLTree<K, V>::_postOrder(AVLTNode<K, V>* node)
{
    if(node==NULL)
        return;
    cout << node->key;
    _postOrder(node->left);
    _postOrder(node->right)
}
