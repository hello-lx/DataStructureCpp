#ifndef QBASE_H
#define QBASE_H
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node{
    char name;
    int data;
    struct Node *lChild=nullptr, *rChild=nullptr, *parent=nullptr;  // tree
    
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


// 2.2 定义链式存储队列模板
template <typename T>
class LinkQueue{
private:
    int size;
    T* header=nullptr;
    
public:
    LinkQueue();
    ~LinkQueue();
    
    void push(int data);
    void push(T* node);
    // int front();
    // int back();
    T* back();
    T* pop();
    bool isEmpty();
    int getSize();  
    void clear();
    void print();  
};


template <class T>
void testLinkQueue();

template<typename T> 
void swap2(T& t1, T& t2);

// 5. 图
#define LENGTH(arr)  (sizeof(arr)/sizeof(arr[0]))
#define chars "ABCDEFGHIJKLMNOPQRTSUVWXYZ"

// --------------------------------------- 邻接矩阵 --------------------------------------- 
typedef struct GraphMatrixNode
{
        int arcId;
        int weight;
        int x, y;
        GraphMatrixNode(){
                arcId = -1;
                weight = -1;
                x=-1;
                y=-1;
        }
        GraphMatrixNode(char d, int w, int _x, int _y):arcId(d), weight(w), x(_x), y(_y){}
} GMNode;

// --------------------------------------- 邻接表 --------------------------------------- 
typedef struct GraphTableNode
{
        // int vId;        // 邻接点在数组中的位置下标
        char name;      // 邻接点的数值
        int weight;
        struct GraphTableNode *next;

        GraphTableNode(){
                name = '#';
                weight=-1;
                next=nullptr;
        }
        GraphTableNode(char n, int w, GraphTableNode* _next): name(n), weight(w), next(_next){}
} GTNode;


//  --------------------------------------- 图  --------------------------------------- 
class Graph{
public:
        Graph();
        Graph(vector<char> &vertexs);
        ~Graph();
        
        void createGraphMatrix(const vector<vector<char>> &letters, const vector<int> &weights, const bool &ori, vector<vector<GMNode*>> &matrix);
        void printMatrix(const vector<vector<GMNode*>> &matrix);
        void testMatrix();

        void createGraphTable(const vector<vector<char>> &letters, const vector<int> &weights, const bool &ori, vector<GTNode*> &table);
        void printTable(const vector<GTNode*> &table);
        void testTable();

private:
        map<char, int>* ch2int;
        map<int, char>* int2ch;
};


#endif