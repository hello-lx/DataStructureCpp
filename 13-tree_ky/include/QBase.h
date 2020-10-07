#ifndef QBASE_H
#define QBASE_H
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    char name;
    int data;
    struct Node *lChild=nullptr, *rChild=nullptr, *parent=nullptr, *next=nullptr;
    Node(char n, int d): name(n), data(d){}
};


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
    Node* header;
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
    Node* header=nullptr;
    
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

    Node* getRoot();
    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);

private:
    Node* root = nullptr;
    int len = 0;
};

void testBiTree();

class BBTree{  // balance binary tree
public:
    BBTree();
    ~BBTree();

    Node* getRoot();
    void preOrder(Node* node);
    void inOrder(Node* node);
    void postOrder(Node* node);

private:
    Node* root = nullptr;
    int len = 0;
};

#endif