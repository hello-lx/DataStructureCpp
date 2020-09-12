#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
using namespace std;


/**
 *      二叉树递归遍历
 */

typedef struct STACK
{
    CNode *header;
    int size=0;
} Stack;

// 孩子节点
typedef struct CHILDNODE
{
    char name;
    struct CHILDNODE* lChild;
    struct CHILDNODE* rChild;
} CNode;

typedef struct  LINKNODE
{
    struct LINKNODE* next;
} LinkNode;

typedef struct BINTREESTACKNODE
{
    LinkNode * node;
    BinTreeStackNode* root;
    int flag;
} BinTreeStackNode;

void binaryTree();

#endif