#ifndef QBASE_H
#define QBASE_H
#include <iostream>
#include <vector>
using namespace std;



// 1.1 定义顺序存储栈模板
class SeqStack
{
private:
    int size;

public:
    SeqStack();
    ~SeqStack(); 

    void push(int data);
    void pop();
    int top();
    int getSize();
    bool isEmpty();
    void print();
    
};

void testSeqStack();


// 1.2 定义链式存储栈模板
typedef struct StackNode
{
    int data;
    struct StackNode *next=nullptr;
} SNode;

class LinkStack
{
private:
    SNode* header;
    int size;

public:
    LinkStack();
    ~LinkStack(); 

    void push(int data);
    void pop();
    int top();
    int getSize();
    bool isEmpty();
    void print();
    
};

void testLinkStack();

// 2.1 定义顺序存储队列模板
class SeqQueue{
    
};


// 2.2 定义链式存储队列模板
typedef struct QueueNode{
    int data;
    struct QueueNode* next=nullptr;
} QNode;

class LinkQueue{
private:
    int size;
    QNode* header=nullptr;
    
public:
    LinkQueue();
    ~LinkQueue();
    
    void push(int data);
    int front();
    int back();
    void pop();
    int getSize();  
    void clear();
    void print();  
};

void testLinkQueue();

// 3.1 定义顺序存储二叉树模板


// 3.2 定义链式存储二叉树模板
typedef struct BinaryTreeNode{
    char name;
    int data;
    struct BinaryTreeNode* lChild=nullptr;
    struct BinaryTreeNode* rChild=nullptr;
    struct BinaryTreeNode* parent=nullptr;
    BinaryTreeNode(char n, int d): name(n), data(d){}
} BTNode;


class BiTree{
public:
    BiTree();
    BiTree(vector<char> &names, vector<int> &data);
    ~BiTree();

    BTNode* getRoot();
    void preOrder(BTNode* node);
    void inOrder(BTNode* node);
    void postOrder(BTNode* node);

private:
    BTNode* root = nullptr;
    int len = 0;
};

void testBiTree();

class BBTree{  // balance binary tree
public:
    BBTree();
    ~BBTree();

    BTNode* getRoot();
    void preOrder(BTNode* node);
    void inOrder(BTNode* node);
    void postOrder(BTNode* node);

private:
    BTNode* root = nullptr;
    int len = 0;
};

#endif