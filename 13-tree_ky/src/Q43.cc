#include "Q43.h"

BiTree* createBiTree(){
/**                  A
 *                 /   \
 *                B     C
 *               / \   / \
 *              D   E F   G  
 */

    vector<char> names = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    vector<int> data = {1, 2, 3, 4, 5, 6, 7};
    // vector<char> names = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    // vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    BiTree* tree = new BiTree(names, data);
    return tree;
}

// 4.3-综合题03： 二叉树自下而上、从右到左的层次遍历算法
void hw03(BiTree* tree){
    if(tree == nullptr)
        tree = createBiTree();
    
    Node *n;
    LinkStack* s = new LinkStack();
    LinkQueue* q = new LinkQueue();
    if(tree->getLen() > 0){
        q->push(tree->getRoot());
        while (!q->isEmpty())
        {
            n = q->front();
            q->pop();

            s->push(n);
            
            if(n->lChild)
                q->push(n->lChild);
            if(n->rChild)
                q->push(n->rChild);
        }
        
        while (!s->isEmpty())
        {
            n = s->top();
            s->pop();
            cout << n->data << ' ';
        }
        cout << endl;        
    }
}


// 4.3-综合题05： 链式二叉树，用非递归求二叉树的高度？
void hw05(BiTree* tree){  // 非递归
    if(tree == nullptr)
        tree = createBiTree();
    
    int front=-1, rear=0;
    int last=0, level=0;
    LinkQueue *q = new LinkQueue();  // bug: LinkQueue *q; 为什么这个push不进去？
    q->push(tree->getRoot());
    Node *n;

    if (tree->getLen() > 0)
        while (!q->isEmpty())
        {
            n = q->front();
            q->pop();
            front++;

            if(n->lChild){
                rear++;
                q->push(n->lChild);
            }
            if(n->rChild){
                rear++;
                q->push(n->rChild);
            }
            
            if(front == last){
                last = rear;
                level++;
            }
        }

    cout << "树的高度为：" << level << endl;
}

int hw05(Node* node){  // 递归
    if(node == nullptr)
        return 0;
    
    int lh = hw05(node->lChild);
    int rh = hw05(node->rChild);
    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
}

// 4.3-综合题06： 二叉树中各节点值不同，已知先序结果数组A[1...N]和中序结果数组B[1...N]，重新建立二叉树链表
Node* createTreeByPreIn(vector<Node> &A, vector<Node> &B, int l1, int h1, int l2, int h2){
    Node* root = (Node*)(malloc(sizeof(Node)));
    root->data = A[l1].data;
    root->name = A[l1].name;
    int i;
    for(i=l2; B[i].name != root->name; i++);        // 根节点在中序序列的划分

    int lLen = i - l2;                  // 左子树的长度
    int rLen = h2 - i;                  // 右子树的长度
    if(lLen)                            // 递归建立左子树
        root->lChild = createTreeByPreIn(A, B, l1+1, l1+lLen, l2, l2+lLen-1);
    else
        root->lChild = nullptr;
    
    if(rLen)                            // 递归建立右子树
        root->rChild = createTreeByPreIn(A, B, h1-rLen+1, h1, h2-rLen+1, h2);
    else
        root->rChild = nullptr;
    
    return root;
}

void hw06(){
    vector<char> names = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<int> data = {1, 2, 3, 4, 5, 6};
    BiTree* tree = new BiTree(names, data);
    // tree->preOrder(tree->getRoot());
    // cout << endl;
    // tree->inOrder(tree->getRoot());
    // cout << endl;

    vector<char> preNames = {'A', 'B', 'D', 'E', 'C', 'F'}, inNames = {'D', 'B', 'E', 'A', 'F', 'C'};
    vector<Node> preNodes, inNodes;
    for(int i=0; i<preNames.size(); i++){
        preNodes.push_back(Node(preNames[i], 1));
        inNodes.push_back(Node(inNames[i], 1));
    }
    
    Node* root = createTreeByPreIn(preNodes, inNodes, 0, 6, 0, 6);
    tree->preOrder(root);
    cout << endl;
}


// 4.3-综合题07： 链式二叉树，判断是否为完全二叉树
bool isComplete(Node* root){
    if(!root)       // 空树为满二叉树
        return true;
    
    // LinkQueue *queue = new LinkQueue();
    SeqQueue *queue = new SeqQueue();
    queue->push(root);
    Node* n;

    while (!queue->isEmpty())
    {
        n = queue->pop();
        
        if(n){  // bug: 此处需要使用顺序存储队列进行存储
            queue->push(n->lChild);
            queue->push(n->rChild);
        }
        else{       // 判断方法：最后一个叶子节点右边是否还有叶子结点
            while (!queue->isEmpty())
            {
                n = queue->pop();
                if(n)
                    return false;
            }
        }
    }
    
    return true;
}


void hw07(){
    /** tree1   A           tree2  A
     *         / \                / \
     *        B   C              B   C
     *       /                  /     \
     *      D                  D       E
     */
    vector<char> names = {'A', 'B', 'C', 'D'};
    vector<int> data = {1, 2, 3, 4};
    BiTree* tree1 = new BiTree(names, data);
    Node* root1 = tree1->getRoot();
    cout << "tree1: " << isComplete(root1) << endl;

    BiTree* tree2 = new BiTree(names, data);
    Node* root2 = tree2->getRoot();
    Node* nodeE = new Node('E', 5);
    root2->rChild->rChild = nodeE;
    nodeE->parent = root2->rChild;
    cout << "tree2: " << isComplete(root2) << endl;

}


// 4.3-综合题08： 链式二叉树，计算所有双分支节点个数
void hw08(){
}


// 4.3-综合题09： 链式二叉树，把所有结点的左右子树进行交换
void hw09(){
}


// 4.3-综合题10： 链式二叉树，求先序遍历序列中第k(1 <= k <= 树结点个数)个节点的值
void hw10(){
}


// 4.3-综合题11： 链式二叉树，对于每个每个元素值为x的结点，删去已它为根的子树，并释放相应的空间
void hw11(){
}


// 4.3-综合题12： 二叉树，查找值为x的结点，并打印值为x的结点的所有祖先。假设值为x的结点不多于一个
void hw12(){
}


// 4.3-综合题17： 判断两颗二叉树是否相似
void hw17(){
}


// 4.3-综合题19： 设计WPL算法： 二叉树带权路径长度（WPL）是二叉树中所有带权路径长度之和.  二叉树结点属性： left weight right  (weight > 0)
void hw19(){
}


// 4.3-综合题20：设计算法：将给定的表达式树(二叉树)转化为等价的中缀表达式(通过括号反映操作符的计算次序)并输出。
void hw20(){
}

