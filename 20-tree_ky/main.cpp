#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "base.h"
#include "Q01.h"
#include "Q02.h"
#include "Q03.h"
// #include "Q04.h"
// #include "Q05.h"
// #include "Q06.h"
// #include "Q07.h"

void binTreeInit(Tree* tree){
        /** 
         *                          root             
         *                         /       \
         *                       A         B
         *                     /  \       /  \
         *                   C    D    E
         *                         
         */

        // tree = new Tree();
        // int index = 0, data = 10;
        // for(int i=0; i<10; i++){
        //     Node* node =  new Node();
        //     node->index = ++index;
        //     node->data = ++data;
        //     if(i % 2 == 0)
        //         tree->AddNode(node->index, 0, node);
        //     else
        //         tree->AddNode(node->index, 1, node);
        // }

        // Tree *tree = new Tree();
        tree = new Tree();

        Node *node1 = new Node();
        node1->index = 1;
        node1->data = 5;

        Node *node2 = new Node();
        node2->index = 2;
        node2->data = 8;

        Node *node3 = new Node();
        node3->index = 3;
        node3->data = 2;

        Node *node4 = new Node();
        node4->index = 4;
        node4->data = 6;

        Node *node5 = new Node();
        node5->index = 5;
        node5->data = 9;

        Node *node6 = new Node();
        node6->index = 6;
        node6->data = 7;

        tree->AddNode(0,0, node1);
        tree->AddNode(0, 1, node2);

        tree->AddNode(1, 0, node3);
        tree->AddNode(1, 1, node4);

        tree->AddNode(2, 0, node5);
        tree->AddNode(2, 1, node6);
        Node* temp = tree->SearchNode(4);
        cout << temp->index <<"--"<< temp->data<<endl;
        //二叉树删除会把子树也删除
        //tree->DeleteNode(2,NULL);
        // tree->PreorderTraversal();
        // delete tree;
        tree->showTree(tree->getRootNode());
}


void testQ01(){}


void testQ02(){}


void testQ03(){}


int main(int argc, char const *argv[])
{
    Tree *tree = NULL;
    binTreeInit(tree);
    return 0;
}

