#include "stackBinTree.h"
/**
 *      二叉树非递归遍历
 */

LinkStack* initLinkStack(){
    LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
    stack->size = 0;
    stack->header = NULL;
    stack->header->next = NULL;
    return stack;
}

BinTreeStackNode* createBiTreeStackNode(CNode* node, int flag){
    BinTreeStackNode* newNode =(BinTreeStackNode*)malloc(sizeof(BinTreeStackNode));
    newNode->root = node;
    newNode->flag = flag;
    newNode->next = NULL;
}

int sizeLinkStack(LinkStack* stack){
    return stack->size;
}

void pushLinkStack(LinkStack* stack, BinTreeStackNode* stackNode){
    if(stack == NULL && stackNode == NULL)
        return;
    stackNode->next = stack->header->next;
    stack->header = stackNode;
    stack->size += 1;
}

BinTreeStackNode* topLinkStack(LinkStack* stack){
    return stack->header;
}

void popLinkStack(LinkStack* stack){
    if(stack==NULL)
        return;
    stack->header = stack->header->next;
    stack->size--;
}

// ###########################################################################################
void nonRecursion(CNode* root){
    // 创建栈
    LinkStack* stack = initLinkStack();
    // 把根节点扔到栈里面
    pushLinkStack(stack, (BinTreeStackNode*)createBiTreeStackNode(root, MY_FALSE));
    
    while (sizeLinkStack(stack) > 0)
    {
        BinTreeStackNode* node = (BinTreeStackNode*)topLinkStack(stack);
        popLinkStack(stack);

        if(node->root == NULL)
            continue;

        if(node->flag == MY_TRUE){
            printf("%c ", node->root->name);
        }
        else{
            pushLinkStack(stack, (BinTreeStackNode*)createBiTreeStackNode(node->root->rChild, MY_FALSE));
            pushLinkStack(stack, (BinTreeStackNode*)createBiTreeStackNode(node->root->lChild, MY_FALSE));
            node->flag == MY_TRUE;
            pushLinkStack(stack, node);
        }
    }
}
// ###########################################################################################

void binaryTree2(){
/**
 *               A
 *             /   \
 *            B     F
 *             \     \
 *              C     G
 *             / \   /
 *            D   E H
 * 
 * NLR: ABCDEFGH
 * LNR: BDCEAFHG
 * LRN: DECBHGFA
 */
    CNode nA = {'A', NULL, NULL};
    CNode nB = {'B', NULL, NULL};
    CNode nC = {'C', NULL, NULL};
    CNode nD = {'D', NULL, NULL};
    CNode nE = {'E', NULL, NULL};
    CNode nF = {'F', NULL, NULL};
    CNode nG = {'G', NULL, NULL};
    CNode nH = {'H', NULL, NULL};

    nA.lChild = &nB;
    nB.rChild = &nC;
    nC.lChild = &nD;
    nC.rChild = &nE;
    nA.rChild = &nF;
    nF.rChild = &nG;
    nG.lChild = &nH;

    nonRecursion(&nA);    
}
