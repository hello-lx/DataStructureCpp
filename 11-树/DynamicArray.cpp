#include "DynamicArray.h"

// 先序遍历
void preOrderRecursion(cNode* root){
    if (root == nullptr)
        return;
    
    printf("%c", root->name);
    preOrderRecursion(root->lChild);
    preOrderRecursion(root->rChild);
}

// 中序遍历
void midOrderRecursion(cNode* root){
    if(root == nullptr)
        return;
    
    midOrderRecursion(root->lChild);
    printf("%c", root->name);
    midOrderRecursion(root->rChild);
}

// 后序遍历
void postOrderRecursion(cNode* root){
    if(root == nullptr)
        return;
    
    postOrderRecursion(root->lChild);
    postOrderRecursion(root->rChild);
    printf("%c", root->name);
}

// 计算叶子节点
void calculateLeafNum(cNode* root, int& numLeaf){
    if(root == NULL)
        return;
    if(root->lChild == NULL && root->rChild == NULL)
        numLeaf += 1;
    calculateLeafNum(root->lChild, numLeaf);
    calculateLeafNum(root->rChild, numLeaf);
}

// 计算树的高度（或深度）
int calculateTreeHeight(cNode* root){
    if(root == NULL)
        return 0;
    int left = calculateTreeHeight(root->lChild);
    int right = calculateTreeHeight(root->rChild);
    
    return left > right? left + 1: right  + 1;
}

// 拷贝二叉树
cNode* copyBinaryTree(cNode* root){
    if(root == NULL)
        return NULL;
    
    // 后序遍历
    cNode* lChild = copyBinaryTree(root->lChild);
    cNode* rChild = copyBinaryTree(root->rChild);
    
    cNode* newNode = (cNode*)malloc(sizeof(cNode));
    newNode->name = root->name;
    newNode->lChild = lChild;
    newNode->rChild = rChild;
    
    return newNode;
}

void freeBinaryTree(cNode *root){
    if(root == NULL)
        return;
    
    freeBinaryTree(root->lChild);
    freeBinaryTree(root->rChild);
    
    free(root);
}

void binaryTree(){
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
    // 创建二叉树
    cNode nA = {'A', NULL, NULL};
    cNode nB = {'B', NULL, NULL};
    cNode nC = {'C', NULL, NULL};
    cNode nD = {'D', NULL, NULL};
    cNode nE = {'E', NULL, NULL};
    cNode nF = {'F', NULL, NULL};
    cNode nG = {'G', NULL, NULL};
    cNode nH = {'H', NULL, NULL};

    nA.lChild = &nB;
    nB.rChild = &nC;
    nC.lChild = &nD;
    nC.rChild = &nE;
    nA.rChild = &nF;
    nF.rChild = &nG;
    nG.lChild = &nH;

    printf("先序遍历：\n");
    printf("ABCDEFGH\n");
    preOrderRecursion(&nA);
    printf("\n\n");

    printf("中序遍历：\n");
    printf("BDCEAFHG\n");
    midOrderRecursion(&nA);
    printf("\n\n");

    printf("后序遍历：\n");
    printf("DECBHGFA\n");
    postOrderRecursion(&nA);
    printf("\n\n");

    int leafNum = 0;
    calculateLeafNum(&nA, leafNum);
    printf("叶子节点数量：%d\n\n", leafNum);

    int treeHeight = calculateTreeHeight(&nA);
    printf("树的高度：%d\n\n", treeHeight);
    
    printf("先序遍历(拷贝树)：\n");
    printf("ABCDEFGH\n");
    cNode* newTree = copyBinaryTree(&nA);
    preOrderRecursion(newTree);
    printf("\n\n");

    printf("释放二叉树：\n");
    freeBinaryTree(newTree);
    printf("已释放\n");
    preOrderRecursion(newTree);
    printf("\n\n");
}
