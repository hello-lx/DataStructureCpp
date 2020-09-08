#include <iostream>
#include <string>
#include "base.h"

using namespace std;

Node::Node(){
        index = 0;
        data = 0;
        pLChild = NULL;
        pRChild = NULL;
        pParent = NULL;
}


void Node::DeleteNode(){
        if(this->pLChild != NULL)
                this->pLChild->DeleteNode();
        if(this->pRChild != NULL)
                this->pRChild->DeleteNode();
        
        // 多余的？
        if(this->pParent != NULL){
                if(this->pParent->pLChild == this)
                        this->pParent->pLChild == NULL;
                if(this->pParent->pRChild == this)
                        this->pParent->pRChild == NULL;
        }

        delete this;
}


Node *Node::SearchNode(int nodeIndex){
        
        if(this->index == nodeIndex)
                return this;
        
        
        Node *temp = NULL;

        if(this->pLChild == NULL){
                if(this->pLChild->index == nodeIndex)
                {
                        return this->pLChild;
                }
                else
                {
                        temp = this->pLChild->SearchNode(nodeIndex);
                        if(temp != NULL)
                                return temp;
                }
        }
        
        if(this->pRChild == NULL){

                if(this->pRChild->index == nodeIndex)
                {
                        return this->pRChild;
                }
                else
                {
                        temp = this->pRChild->SearchNode(nodeIndex);
                        if(temp != NULL)
                                return temp;    
                }
        }

        return NULL;
}

// ------------------------------------------------- 分割线 --------------------------------------------------------------

Tree::Tree(){
        m_pRoot = new Node();
}


Tree::~Tree()
{
        m_pRoot->DeleteNode();
}

Node *Tree::SearchNode(int nodeIndex){
        return m_pRoot->SearchNode(nodeIndex);
}


bool Tree::AddNode(int nodeIndex, int direction, Node* pNode)
{
        Node* temp = SearchNode(nodeIndex);
        
        if(temp == NULL)
                return false;
        
        Node* node = new Node();
        if(node == NULL)
                return false;
        
        node->index = pNode->index;
        node->data = pNode->data;
        node->pParent = temp;

        if(direction == 0)
                temp->pLChild = node;
        else
                temp->pRChild = node;
        
        return true;
}

bool Tree::DeleteNode(int nodeIndex, Node* pNode)
{
        Node *temp = SearchNode(nodeIndex);

        if(temp == NULL)
                return false;

        if(temp != NULL)
                pNode->data = temp->data;
        
        temp->DeleteNode();

        return pNode;
}

void Tree::showTree(Node* node){
        if(node == NULL)
                return;

        cout << node->index << '\t' << node->data <<endl;
        showTree(node->pLChild);
        showTree(node->pRChild);
}

Node* Tree::getRootNode(){
        return this->m_pRoot;
}