#ifndef QBASE_H
#define QBASE_H
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    char name;
    int data;
    struct Node *lChild=nullptr, *rChild=nullptr, *parent=nullptr;  // tree
    struct Node *fch=nullptr, *nsib=nullptr;  // 森林：左孩子和右兄弟
    struct Node *next=nullptr;                                      // stack / queue
    Node(char n, int d): name(n), data(d){}
};

typedef struct MYNODE{
    char name;
    int data;
    struct MYNode *lChild=nullptr, *rChild=nullptr, *parent=nullptr;  // tree
    struct MYNode *next=nullptr;                                      // stack / queue
    MYNODE(char n, int d): name(n), data(d){}
} MyNode;


// 1.1 定义顺序存储栈模板
class SeqStack
{
private:
    int size;

public:
    SeqStack();
    ~SeqStack(); 

    void push(int data);
    void push(Node* node);
    void pop();
    Node* top();
    int getSize();
    bool isEmpty();
    void print();
    
};

void testSeqStack();


// 1.2 定义链式存储栈模板
class LinkStack
{
private:
    Node* header;
    int size;

public:
    LinkStack();
    ~LinkStack(); 

    void push(int data);
    void push(Node* node);
    void pop();
    // int top();
    Node* top();
    int getSize();
    bool isEmpty();
    void print();
    
};

void testLinkStack();

// 2.1 定义顺序存储队列模板
class SeqQueue{
public:
    SeqQueue();
    ~SeqQueue();
    void push(Node* node);
    Node* pop();
    int getSize();
    bool isEmpty();

private:
    int size = 0;
    vector<Node*> arr;
};


// 2.2 定义链式存储队列模板
class LinkQueue{
private:
    int size;
    Node* header=nullptr;
    
public:
    LinkQueue();
    ~LinkQueue();
    
    void push(int data);
    void push(Node* node);
    // int front();
    Node* front();
    // int back();
    Node* back();
    void pop();
    bool isEmpty();
    int getSize();  
    void clear();
    void print();  
};

void testLinkQueue();

// 3.1 定义顺序存储二叉树模板


// 3.2 定义链式存储二叉树模板
class BiTree{
public:
    BiTree();
    BiTree(vector<char> &names, vector<int> &data);
    ~BiTree();

    Node* getRoot();
    int getLen();
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