#include "Q44.h"

Node* createForest(){
/**                  A
 *                 /   
 *                B ——> C
 *               /     / 
 *              D     F     
 */

    vector<char> names = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    vector<int> data = {1, 2, 3, 4, 5, 6, 7};

    Node* nodeD = (Node*)(malloc(sizeof(Node)));
    nodeD->name = names[3];
    nodeD->data = data[3];

    Node* nodeF = (Node*)(malloc(sizeof(Node)));
    nodeF->name = names[5];
    nodeF->data = data[5];

    Node* nodeC = (Node*)(malloc(sizeof(Node)));
    nodeC->name = names[2];
    nodeC->data = data[2];
    nodeC->fch = nodeF;

    Node* nodeB = (Node*)(malloc(sizeof(Node)));
    nodeB->name = names[1];
    nodeB->data = data[1];
    nodeB->fch = nodeD;
    nodeB->nsib = nodeC;

    Node* root = (Node*)(malloc(sizeof(Node)));
    root->name = names[0];
    root->data = data[0];
    root->fch = nodeB;
    
    return root;
}

int Leaves(Node *root){
    if(root == nullptr)
        return 0;
    if(root->fch == NULL)           // 若无孩子，必是叶子结点
        return 1 + Leaves(root->nsib);
    else                            // 森林的叶子节点为孩子的叶子结点和兄弟结点的叶子结点总数之和
        return Leaves(root->fch) + Leaves(root->nsib);
}

void hw05_(){
    Node* root = createForest();
    cout << "森林的叶子结点个数：" << Leaves(root) << endl;
}
