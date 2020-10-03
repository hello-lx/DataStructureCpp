#ifndef Q04_H
#define Q04_H

#include <iostream>
using namespace std;
/**
 * (二叉)树应用三：平衡二叉树 —— 讨论的是关于平衡二叉排序树，插入新的节点后出现不平衡的情况后，如何调整树节点位置的问题，使其回归平衡
 * 平衡二叉树(AVL Tree)首先要满足二叉树的定义,如下
    二叉排序树或者是一棵空树，或者是具有下列性质的二叉树：
    若左子树不空，则左子树上所有结点的值均小于它的根结点的值；
    若右子树不空，则右子树上所有结点的值均大于它的根结点的值；
    左、右子树也分别为二叉排序树；
    没有键值相等的节点。
    """ 平衡度是左子树高度减去右子树高度，平衡度只能是-1,+1,0  """

 *        LL（bf_x2=2,  bf_x4=1）                               （bf_x2=2,  bf_x4=-1）
 *                 X1                             X2                     X1                                    X2   
 *               /    \                         /    \                 /    \                                /    \       
 *              X2    X3                      X4      X1              X2     X3                            x4      X1      
 *             / \               ===>        /       /  \            /  \                  ===>              \    /  \         
 *           X4   X5                        Y      X5    X3        X4    X5                                   Y  X5   X3
 *          /                                                        \
 *         Y                                                          Y
 * 
 *        LR（bf_x2=2,  bf_x5=-1）                                    （bf_x2=2,  bf_x5=1）
 *                 X1                             X5                          X1                           X5    
 *               /    \                         /    \                      /    \                       /    \ 
 *             X2      X3                      X2     X1                  X2      X3                   X2      X1
 *            /  \               ==>          /      /  \                /  \             ==>         /  \       \
 *          X4    X5                        X4      Y    X3            X4    X5                     X4    Y       X3
 *                  \                                                       /                          
 *                   Y                                                     Y                          
 * 
 *        
 *        RL（bf_x3=-2, bf_x4=1）（和上面类似）
 *               X1          
 *             /    \        
 *           X2      X3      
 *                  /  \     
 *                X4    X5   
 *               /                               
 *              Y                                
 * 
 *        RR （bf_x3=-2, bf_x5=-1）           
 *                X1                           
 *              /    \                         
 *            X2      X3                       
 *                   /  \                       
 *                 X4    X5                       
 *                         \                       
 *                          Y                       
 * 
 * https://www.cnblogs.com/Java-Starter/p/10192034.html
*/

// 平衡树节点
template<class K, class V>
struct AVLTNode 
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


template<class K, class V>
class AVLTree
{
protected:
   AVLTNode<K, V> root;  // 根节点

public:
   AVLTree(): root(NULL){}

   bool insert(const K& key, const V& value);

   void inOrder(){
      _inOrder();
      cout << endl;
   }

   void preOrder(){
      _preOrder();
      cout << endl;
   }

   void postOrder(){
      _postOrder();
      cout << endl;
   }

   bool isBalance(){
      return _isBalance();
   }

   int height(){
      return _height();
   }

protected:
	//左改组LL型
	void _rotateLL(AVLTNode<K, V>*&  parent);
	//右改组RR型
	void _rotateRR(AVLTNode<K, V>*&  parent);
	//右改组RL型
	void _rotateRL(AVLTNode<K, V>*&  parent);
	//左改组LR型
	void _rotateLR(AVLTNode<K, V>*&  parent);
	//中序遍历
	void _inOrder(AVLTNode<K, V>* node);
	//前序遍历
	void _preOrder(AVLTNode<K, V>* node);
	//后序遍历
	void _postOrder(AVLTNode<K, V>* node);
	//检查二叉排序树是否平衡
	bool _isBalance(AVLTNode<K, V>* node);
	int _height(AVLTNode<K, V>* node);
};

#endif