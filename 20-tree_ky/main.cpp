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

        tree = new Tree();
        int index = 0, data = 10;
        for(int i=0; i<10; i++){
            Node* node =  new Node();
            node->index = index++;
            node->data = data++;
            if(i % 2 == 0)
                tree->AddNode(node->index, 0, node);
            else
                tree->AddNode(node->index, 1, node);
        }

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

