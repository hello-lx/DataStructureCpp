#include "stackBinTree.h"
/**
 *      二叉树非递归遍历
 */

LinkStack* initLinkStack(){
    LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
    stack->size = 0;
    stack->header = NULL;
    // stack->header->next = NULL;
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
    stackNode->next = stack->header;
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
void preOrderNonRecursion(CNode* root){
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

        // printf("MY_TRUE: %d,   MY_FALSE: %d", MY_TRUE, MY_FALSE);
        if(node->flag == MY_TRUE){
            printf("%c", node->root->name);
        }
        else{
            pushLinkStack(stack, (BinTreeStackNode*)createBiTreeStackNode(node->root->rChild, MY_FALSE));
            pushLinkStack(stack, (BinTreeStackNode*)createBiTreeStackNode(node->root->lChild, MY_FALSE));
            node->flag = MY_TRUE;
            pushLinkStack(stack, node);
        }
    }
}

void midOrderNonRecursion(CNode* root){
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

        // printf("MY_TRUE: %d,   MY_FALSE: %d", MY_TRUE, MY_FALSE);
        if(node->flag == MY_TRUE){
            printf("%c", node->root->name);
        }
        else{
            pushLinkStack(stack, (BinTreeStackNode*)createBiTreeStackNode(node->root->rChild, MY_FALSE));
            node->flag = MY_TRUE;
            pushLinkStack(stack, node);
            pushLinkStack(stack, (BinTreeStackNode*)createBiTreeStackNode(node->root->lChild, MY_FALSE));
        }
    }
}

void postOrderNonRecursion(CNode* root){
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

        // printf("MY_TRUE: %d,   MY_FALSE: %d", MY_TRUE, MY_FALSE);
        if(node->flag == MY_TRUE){
            printf("%c", node->root->name);
        }
        else{
            node->flag = MY_TRUE;
            pushLinkStack(stack, node);
            pushLinkStack(stack, (BinTreeStackNode*)createBiTreeStackNode(node->root->rChild, MY_FALSE));
            pushLinkStack(stack, (BinTreeStackNode*)createBiTreeStackNode(node->root->lChild, MY_FALSE));
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

    printf("先序遍历：\n");
    printf("ABCDEFGH\n");
    preOrderNonRecursion(&nA);
    printf("\n\n");

    printf("中序遍历：\n");
    printf("BDCEAFHG\n");
    midOrderNonRecursion(&nA);
    printf("\n\n");

    printf("后序遍历：\n");
    printf("DECBHGFA\n");
    postOrderNonRecursion(&nA);
    printf("\n\n");
}


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
CNode* createBiTree(){
    fflush(stdin);
    char ch;
    scanf("%c", &ch);
    CNode* node;
    CNode *lChild, *rChild;

    if(ch == '#'){
        node = NULL;
    }
    else{
        lChild = createBiTree();
        rChild = createBiTree();
        node->name = ch;
        node->lChild = lChild;
        node->rChild = rChild;
    }

    return node;
}

void recursion(CNode* root){
    if(root == NULL)
        return;
    
    printf("%c", root->name);
    recursion(root->lChild);
    recursion(root->rChild);
}

void testCreateBiTree(){
    CNode* root = createBiTree();
    printf("\n\n");
    recursion(root);
    printf("\n\n");
}