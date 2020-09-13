#include <iostream>
#include <string>
#include "base.h"

using namespace std;

// Node::Node(){
//         index = 0;
//         data = 0;
//         pLChild = NULL;
//         pRChild = NULL;
//         pParent = NULL;
// }


// void Node::DeleteNode(){
//         if(this->pLChild != NULL)
//                 this->pLChild->DeleteNode();
//         if(this->pRChild != NULL)
//                 this->pRChild->DeleteNode();
        
//         // 多余的？
//         if(this->pParent != NULL){
//                 if(this->pParent->pLChild == this)
//                         this->pParent->pLChild == NULL;
//                 if(this->pParent->pRChild == this)
//                         this->pParent->pRChild == NULL;
//         }

//         delete this;
// }


// Node *Node::SearchNode(int nodeIndex){
        
//         cout << this->index << '\t' << nodeIndex << endl;

//         if(this->index == nodeIndex)
//                 return this;
        
        
//         Node *temp = NULL;

//         if(this->pLChild != NULL){
//                 if(this->pLChild->index == nodeIndex)
//                 {
//                         return this->pLChild;
//                 }
//                 else
//                 {
//                         temp = this->pLChild->SearchNode(nodeIndex);
//                         if(temp != NULL)
//                                 return temp;
//                 }
//         }
        
//         if(this->pRChild != NULL){

//                 if(this->pRChild->index == nodeIndex)
//                 {
//                         return this->pRChild;
//                 }
//                 else
//                 {
//                         temp = this->pRChild->SearchNode(nodeIndex);
//                         if(temp != NULL)
//                                 return temp;    
//                 }
//         }

//         return NULL;
// }

// ------------------------------------------------- 分割线 --------------------------------------------------------------

// Tree1::Tree1(){
//         root = new Node();
// }


// Tree1::~Tree1()
// {
//         root->DeleteNode();
// }

// Node *Tree1::SearchNode(int nodeIndex){
//         return root->SearchNode(nodeIndex);
// }


// bool Tree1::AddNode(int nodeIndex, int direction, Node* pNode)
// {
//         Node* temp = SearchNode(nodeIndex);
        
//         if(temp == NULL)
//         {
//                 cout << "temp is null" << endl;
//                 return false;
//         }

//         Node* node = new Node();
//         if(node == NULL)
//                 return false;

//         node->index = pNode->index;
//         node->data = pNode->data;
//         node->pParent = temp;

//         if(direction == 0)
//                 temp->pLChild = node;
//         else
//                 temp->pRChild = node;
        
//         return true;
// }

// bool Tree1::DeleteNode(int nodeIndex, Node* pNode)
// {
//         Node *temp = SearchNode(nodeIndex);

//         if(temp == NULL)
//                 return false;

//         if(temp != NULL)
//                 pNode->data = temp->data;
        
//         temp->DeleteNode();

//         return pNode;
// }

// void Tree1::showTree(Node* node){
//         if(node == NULL)
//                 return;

//         cout << node->index << '\t' << node->data <<endl;
//         if(node->pLChild == NULL)
//                 cout << "pLChild is null" << endl;
//         if(node->pRChild == NULL)
//                 cout << "pRChild is null" << endl;
//         // cout << node->pLChild <<  '\t'  << node->pRChild << endl;
//         showTree(node->pLChild);
//         showTree(node->pRChild);
// }

// Node* Tree::getRootNode(){
//         return this->root;
// }

// ------------------------------------------------- Tree1 --------------------------------------------------------------
StackTree1::StackTree1(){}

StackTree1::~StackTree1(){
        if(header == NULL)
                return;
        free(header);
        len = 0;
}

void StackTree1::push(StackNodeTree1* node){
        if(header == NULL && node == NULL)
                return;

        node->next = header;
        header = node;
        len++;
}

void StackTree1::pop(){
        if(header==NULL)
                return;
        // StackNodeTree1* node = header;
        header = header->next;
        len--;
}

StackNodeTree1* StackTree1::top(){
        if(header==NULL)
                return NULL;
        return header;
}

int StackTree1::size(){
        return len;
}

void StackTree1::clear(){
        if(header == NULL)
                return;
        header = NULL;
        len=0;
}

bool StackTree1::isEmpty(){
        if(this->len==0)
                return true;
        return false;
}

StackNodeTree1* Tree1::createStackNode(LCNode* node, int flag){
        StackNodeTree1* stackNode = (StackNodeTree1*)malloc(sizeof(StackNodeTree1));
        stackNode->root = node;
        stackNode->flag = flag;
        stackNode->next = NULL;
        
        return stackNode;
}


Tree1::Tree1(){
        /**
         *                     A
         *                   /   \
         *                  B     C
         *                 / \   / \
         *                D   E F   G
         *               /\  /\ /\  /\
         *            NULL ............
         * 前序遍历(NLR)： ABDECFG
         * 中序遍历(LNR)： DBEAFCG
         * 后序遍历(LRN)： DEBFGCA
         */
        // 完全二叉树
        LCNode nA = {'A', 1, NULL, NULL};
        LCNode nB = {'B', 2, NULL, NULL};
        LCNode nC = {'C', 3, NULL, NULL};
        LCNode nD = {'D', 4, NULL, NULL};
        LCNode nE = {'E', 5, NULL, NULL};
        LCNode nF = {'F', 6, NULL, NULL};
        LCNode nG = {'G', 7, NULL, NULL};
        
        nA.lChild = &nB;
        nA.rChild = &nC;
        nB.lChild = &nD;
        nB.rChild = &nE;
        nC.lChild = &nF;
        nC.rChild = &nG;
        
        root = &nA;
        NLR = "ABDECFG";
        LNR = "DBEAFCG";
        LRN = "DEBFGCA";

        StackTree1 stack;

        printf("前序遍历：\n");
        cout << NLR << endl;
        preOrderRecursion(root);
        printf("\n");
        preOrderNonRecursion(root);
        printf("\n\n");

        printf("中序遍历：\n");
        cout << LNR << endl;
        midOrderRecursion(root);
        printf("\n");
        midOrderNonRecursion(root);
        printf("\n\n");

        printf("后序遍历：\n");
        cout << LRN << endl;
        postOrderRecursion(root);
        printf("\n");
        postOrderNonRecursion(root);
        printf("\n\n");

        int searchId = 7;
        LCNode* result = searchNode(root, searchId);
        if(result != NULL){
                printf("search: %d, result: %d\n", searchId, result->id);
        }else{
                printf("search: %d, result: NULL\n", searchId);
        }

        
}

Tree1::~Tree1(){
        // deleteNode(this->root);
}

LCNode* Tree1::getRoot(){
        return this->root;
}

void Tree1::preOrderRecursion(LCNode *node){  //前序递归遍历
        if(node == NULL)
                return;
        printf("%c", node->name);
        preOrderRecursion(node->lChild);
        preOrderRecursion(node->rChild);
}

void Tree1::midOrderRecursion(LCNode *node){  //中序递归遍历
        if(node == NULL)
                return;
        midOrderRecursion(node->lChild);
        printf("%c", node->name);
        midOrderRecursion(node->rChild);
}

void Tree1::postOrderRecursion(LCNode *node){  //后序递归遍历
        if(node == NULL)
                return;
        postOrderRecursion(node->lChild);
        postOrderRecursion(node->rChild);
        printf("%c", node->name);
}

// 非递归遍历
void Tree1::preOrderNonRecursion(LCNode *node){
        StackTree1* stack = new StackTree1();
        stack->push(createStackNode(node, MY_FALSE));
        while (!stack->isEmpty())
        {
                StackNodeTree1* stackNode = stack->top();
                stack->pop();

                if(stackNode->root == NULL)
                        continue;

                if(stackNode->flag)
                {
                        printf("%c", stackNode->root->name);
                }
                else
                {
                        stack->push(createStackNode(stackNode->root->rChild, MY_FALSE));
                        stack->push(createStackNode(stackNode->root->lChild, MY_FALSE));
                        stackNode->flag = MY_TRUE;
                        stack->push(stackNode);
                }
        }        
}

void Tree1::midOrderNonRecursion(LCNode *node){
        StackTree1* stack = new StackTree1();
        stack->push(createStackNode(node, MY_FALSE));
        while (!stack->isEmpty())
        {
                StackNodeTree1* stackNode = stack->top();
                stack->pop();

                if(stackNode->root == NULL)
                        continue;

                if(stackNode->flag)
                {
                        printf("%c", stackNode->root->name);
                }
                else
                {
                        stack->push(createStackNode(stackNode->root->rChild, MY_FALSE));
                        stackNode->flag = MY_TRUE;
                        stack->push(stackNode);
                        stack->push(createStackNode(stackNode->root->lChild, MY_FALSE));
                }
        }        
}

void Tree1::postOrderNonRecursion(LCNode *node){
        StackTree1* stack = new StackTree1();
        stack->push(createStackNode(node, MY_FALSE));
        while (!stack->isEmpty())
        {
                StackNodeTree1* stackNode = stack->top();
                stack->pop();

                if(stackNode->root == NULL)
                        continue;

                if(stackNode->flag)
                {
                        printf("%c", stackNode->root->name);
                }
                else
                {
                        stackNode->flag = MY_TRUE;
                        stack->push(stackNode);
                        stack->push(createStackNode(stackNode->root->rChild, MY_FALSE));
                        stack->push(createStackNode(stackNode->root->lChild, MY_FALSE));
                }
        }        
}

// bug:  为什么传入进来的节点地址会为空呢 ???
void Tree1::testTraversal(LCNode* node){

        printf("前序遍历：\n");
        cout << NLR << endl;
        preOrderRecursion(node);
        preOrderNonRecursion(node);
        printf("\n\n");

        printf("中序遍历：\n");
        cout << LNR << endl;
        midOrderRecursion(node);
        midOrderNonRecursion(node);
        printf("\n\n");

        printf("后序遍历：\n");
        cout << LRN << endl;
        postOrderRecursion(node);
        postOrderNonRecursion(node);
        printf("\n\n");
}

LCNode* Tree1::searchNode(LCNode* node, int nodeId){
        if(node == NULL)
                return NULL;

        if(node->id == nodeId)
                return node;

        LCNode *temp = NULL;
        if(node->lChild != NULL)
                temp = searchNode(node->lChild, nodeId);
        if(temp != NULL)
                return temp;

        if(node->rChild != NULL)
                temp = searchNode(node->rChild, nodeId);
        return temp;
}

// bug: root作为参数传入会出错
void Tree1::testSearchNode(){
        // LCNode* result = searchNode(root, 5);
        // if(result != NULL){
        //         printf("result: %d", result->id);
        // }else{
        //         printf("result: NULL");
        // }
}

// todo: test
bool Tree1::addNode(int nodeId, int direction, LCNode* newNode){
        LCNode* node = searchNode(root, nodeId);
        if(node == NULL)
                return false;
        if(direction == 0 && node->lChild == NULL)
                node->lChild = newNode;
        else if(direction == 1 && node->rChild == NULL)
                node->rChild = newNode;
        else
                return false;
        
        // testTraversal();
        return true;
}

LCNode* Tree1::leafNode(LCNode* root, int nodeId){
        // 栈遍历
        if(root == NULL)
                return NULL;

        if(root->lChild == NULL && root->rChild == NULL && root->id == nodeId)
                return root;

        LCNode* temp = NULL;
        if(root->lChild != NULL)
                temp = leafNode(root->lChild, nodeId);
        if(temp != NULL)
                return temp;
        
        if(root->rChild != NULL)
                temp = leafNode(root->rChild, nodeId);
        return temp;
}

bool Tree1::deleteNode(LCNode* root, int nodeId){
        if(searchNode(root, nodeId) == NULL)
                return false;

        if(leafNode(root, nodeId) != NULL){  // 叶子节点
                root = NULL;
        }else{

        }
        return true;
}

void Tree1::showTree(LCNode* node){
        
}
