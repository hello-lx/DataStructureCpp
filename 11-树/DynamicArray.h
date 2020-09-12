#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
using namespace std;


/**
 *      二叉树递归遍历
 */

// 双亲节点
struct pNode
{
    int data;
    pNode *parent;
};

// 孩子节点
typedef struct CHILDNODE
{
    char name;
    struct CHILDNODE* lChild;
    struct CHILDNODE* rChild;
} cNode;

void binaryTree();

void preOrderRecursion(cNode* root);

void midOrderRecursion(cNode* root);

void postOrderRecursion(cNode* root);

int calculateTreeHeight(cNode* root);

cNode* copyBinaryTree(cNode* root);

void freeBinaryTree(cNode *root);
#endif