#include "Q45.h"

BiTree* createBTree(){
/**                  A
 *                 /   \
 *                B     C
 *               / \   / \
 *              D   E F   G  
 */

    vector<char> names = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    vector<int> data = {1, 2, 3, 4, 5, 6, 7};
    BiTree* tree = new BiTree(names, data);
    return tree;
}

BiTree* createBST(){
    vector<char> names = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    vector<int> data = {4, 2, 6, 1, 3, 5, 7}; // bug: BE位置互换时，无法判断为排序树
    BiTree* tree = new BiTree(names, data);
    return tree;
}

//     4.5-综06：判断二叉树是否是二叉排序树
// 用中序遍历判断是否为升序
int JudgeBST(Node* root, int &pred){  // pred 前驱节点的值，前驱节点一般在左子树上的
    int b1, b2;
    if(!root)
        return 1;
    else{
        b1 = JudgeBST(root->lChild, pred);
        if(b1 == 0 || pred >= root->data)   // 左子树返回0或前驱节点大于当前节点
            return 0;
        pred = b1;                          // 保存当前结点的值
        b2 = JudgeBST(root->rChild, pred);  // 判断右子树
        return b2;                          // 返回右子树的结果
    }
}

void hw06_(){
/**                  A4
 *                 /   \
 *                B2    C6
 *               / \   / \
 *              D1 3E F5 7G  
 */
        
    int pred = -32767;
    BiTree* tree = createBST();
    if(JudgeBST(tree->getRoot(), pred))
        cout << "是二叉排序树" << endl;
    else
        cout << "不是二叉排序树" << endl;

    pred = -32767;
    Node* root2 = createBTree()->getRoot();
    if(JudgeBST(root2, pred))
        cout << "是二叉排序树" << endl;
    else
        cout << "不是二叉排序树" << endl;
}


//     4.5-综07：求出指定节点在给定二叉排序树中的层次
int findLevel(Node* root, int key){
    int n=0;
    if(root){
        Node* t = root;
        n++;
        while (t->data != key)
        {
            if(t->data < key)
                t = t->rChild;
            else
                t = t->lChild;
            n++;

            if(!t)
                return 0;
        }
    }
    return n;
}

void hw07_(){
/**                  A4
 *                 /   \
 *                B2    C6
 *               / \   / \
 *              D1 3E F5 7G  
 */

    BiTree* tree = createBST();
    int level = findLevel(tree->getRoot(), 5);
    // int level = findLevel(tree->getRoot(), level);
    cout << "level: " << level << endl;
}


//     4.5-综08：利用二叉树遍历的思想编写一个判断二叉树是否是平衡二叉树的算法
/**
 *  (1) 高度为0, 空树，平衡
 *  (2) 高度为1, 只有根节点，平衡
 *  (3) 对采用后序遍历，返回左右子树的高度和平衡标记，二叉树的高度为最高子树的高度加1.
 *      若左右子树的高度差大于1,则balance=0; 若左右子树的高度小于等于1，且左右子树都平衡，返回1，否则返回0
 */
void JudgeAVL(Node* root, int &balance, int &h){
    int bl=0, br=0, hl=0, hr=0;
    if(root == nullptr){
        h = 0;
        balance = 1;
    }
    else if(root->lChild==nullptr && root->rChild==nullptr){
        h = 1;
        balance = 1;
    }
    else{
        JudgeAVL(root->lChild, bl, hl);
        JudgeAVL(root->rChild, br, hr);
        h = (hl > hr ? hl : hr) + 1;
        if(abs(hl - hr) < 2)
            balance = bl && br;
        else
            balance = 0;
    }
}


void hw08_(){
    BiTree* tree = createBTree();
    int h = 0, balance = 1;
    Node* root = tree->getRoot();
    root->rChild = nullptr;

    JudgeAVL(root, balance, h);
    if(balance)
        cout << "平衡二叉树" << endl;
    else
        cout << "非平衡二叉树" << endl;
}


//     4.5-综09：设计算法，求出给定二叉排序树中最小和最大的关键字
int minKey(Node* root){
    if(!root)
        return -1;
    while (root->lChild)
        root = root->lChild;
    return root->data;
}

int maxKey(Node* root){
    if(!root)
        return -1;
    while (root->rChild)
        root = root->rChild;
    return root->data;
}

void hw09_(){
    BiTree* tree = createBST();
    cout << "最小值：" << minKey(tree->getRoot()) << "    最大值：" << maxKey(tree->getRoot()) << endl;
}


//     4.5-综10：设计算法，从大到小，输出二叉排序树中所有其值不小与k的关键字
// 中序遍历: 从大小输出值（改变左子树和右子树的访问顺序）
void output(Node* root, int key){
    if(!root)
        return;
    output(root->rChild, key);
    if (root->data >= key)
        cout << root->data << ' ';
    output(root->lChild, key);
}

void hw10_(){
/**                  A4
 *                 /   \
 *                B2    C6
 *               / \   / \
 *              D1 3E F5 7G  
 */
    BiTree* tree = createBST();
    Node* root = tree->getRoot();
    output(root, 4);
    cout << endl;    
}
