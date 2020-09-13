#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MY_TRUE 1
#define MY_FALSE 0

/**
 *      二叉树非递归遍历
 */

// 孩子节点
typedef struct CHILDNODE
{
    char name;
    struct CHILDNODE* lChild;
    struct CHILDNODE* rChild;
} CNode;

typedef struct BINTREESTACKNODE
{
    struct BINTREESTACKNODE* next;
    CNode* root;
    int flag;
} BinTreeStackNode;

typedef struct LINKSTACK
{
    BinTreeStackNode* header;
    int size=0;
} LinkStack;

int sizeLinkStack(LinkStack* stack);

// --------------------------- 分割线 --------------------------- 

LinkStack* initLinkStack();

BinTreeStackNode* createBiTreeStackNode(CNode* node, int flag);

void preOrderNonRecursion(CNode* root);

void midOrderNonRecursion(CNode* root);

void postOrderNonRecursion(CNode* root);

void binaryTree2();

/**
 * 井号创建二叉树
 * 例如： ABC###D##
 *              A
 *            /   \
 *           B     D
 *          / \   / \ 
 *         C   # #   #
 *        / \
 *       #   #
 */
CNode* createBiTree();

void recursion(CNode* root);

void testCreateBiTree();
#endif