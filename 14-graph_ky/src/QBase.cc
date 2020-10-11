#include "QBase.h"


// -------------------------------- 链式队列 --------------------------------
// 2.2 定义链式存储队列模板
template <typename T>
LinkQueue<T>::LinkQueue(){
    header = (T*)(malloc(sizeof(T)));
    size = 0;
}

template <typename T>
LinkQueue<T>::~LinkQueue(){
    free(this);
}

template <typename T>
void LinkQueue<T>::push(int data)
{
    if(data <= 0){
        cout << "插入失败， 数据必须大于0" << endl;
        return;
    }

    T* last = header->next;
    if(size == 0){
        last = (T*)(malloc(sizeof(T)));
        last->data = data;
        header->next = last;
        size++;
        return;
    }

    
    while (last->next != nullptr)
        last = last->next;

    T* cur = (T*)(malloc(sizeof(T)));
    cur->data = data;
    last->next = cur;
    size++;
}

// template <class T>
// void LinkQueue<T>::push(T* node)
// {
//     // if(node->data <= 0){
//     //     cout << "插入失败， 数据必须大于0" << endl;
//     //     return;
//     // }

//     T* last = header->next;
//     if(size == 0){
//         header->next = node;
//         size++;
//         return;
//     }

    
//     while (last->next != nullptr)
//         last = last->next;

//     last->next = node;
//     size++;
// }

// template <class T>
// T* LinkQueue::front(){
//     if (size == 0)
//         return nullptr;
    
//     return header->next;
// }

// template <class T>
// T* LinkQueue::back(){
//     if(size == 0)
//         return nullptr;
//     T* last = header->next;
//     while(last->next != nullptr)
//         last = last->next;
//     return last;
// }

// template <class T>
// T* LinkQueue::pop(){
//     if(size==0)
//         return;
//     T* top = header->next
//     header->next = header->next->next;   
//     size--;
//     return top;
// }

// int LinkQueue::getSize(){
//     return size;
// }

// void LinkQueue::clear(){
//     if(size > 0)
//         header->next = nullptr;
// }

// template <class T>
// void LinkQueue::print(){
//     if(size == 0){
//         cout << "队列为空～" << endl;
//         return;
//     }
    
//     T* cur = header->next;
//     while(cur != nullptr){
//         cout << cur->data << endl;
//         cur = cur->next;
//     }
//     cout << "队列打印完毕～" << endl;
// }

// bool LinkQueue::isEmpty(){
//     if (size > 0)
//         return false;
//     return true;
// }


template <class T>
void testLinkQueue(){
    cout << "==========================" << endl;

    // LinkQueue<T>* q = new LinkQueue<T>();

    // int arr[] = {33, 21, 25, 16, 8};
    // for(int i=0; i<5; i++){
    //     T* node = (T*)(malloc(sizeof(T)));
    //     node->data = arr[i];
    //     q->push(node);
    //     // q->push(arr[i]);
    // }
        
    // q->print();    
}

template<typename  T> 
void swap2(T& t1, T& t2) {
    T tmpT;
    tmpT = t1;
    t1 = t2;
    t2 = tmpT;
}

/* ------------------------------------ 图初始化 ------------------------------------------ */
Graph::Graph(){
    int n = LENGTH(chars);
    ch2int = new map<char, int>();
    int2ch = new map<int, char>();
    
    for(int i=0; i<n; i++){
        ch2int->insert(pair<char, int>(chars[i], i));
        int2ch->insert(pair<int, char>(i, chars[i]));
    }
}

Graph::Graph(vector<char> &vertexs){
    int n = LENGTH(vertexs);
    ch2int = new map<char, int>();
    int2ch = new map<int, char>();
    
    for(int i=0; i<n; i++){
        ch2int->insert(pair<char, int>(vertexs[i], i));
        int2ch->insert(pair<int, char>(i, vertexs[i]));
    }
}

Graph::~Graph(){
    if(ch2int)
        delete ch2int;
    
    if(int2ch)
        delete int2ch;
}


/* ------------------------------------ 图矩阵 ------------------------------------------ */
void Graph::createGraphMatrix(const vector<vector<char>> &letters, const vector<int> &weights, const bool &ori,
                                 vector<vector<GMNode*>> &matrix){
    /**
     *   @letters: {{'A', 'B'}, {'B', 'C'}, ...}
     *   @weights: {   1,          2,       ...}
     *   @ori: 创建的图是否为有向图
     */

    // 初始化
    map<char, int>::iterator it1, it2;
    for(int i=0; i<letters.size(); i++)
    {
        it1 = ch2int->find(letters[i][0]), it2 = ch2int->find(letters[i][1]);
        
        GMNode* mNode = new GMNode(i, weights[i], it1->second, it2->second);
        matrix[it1->second][it2->second] = mNode;

        if (ori == false)
            matrix[it2->second][it1->second] = mNode;
    }
}

void Graph::printMatrix(const vector<vector<GMNode*>> &matrix){
    for(int i=0; i < matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++)
            if (matrix[i][j] != nullptr)
                cout << matrix[i][j]->weight << ' ';
            else
                cout << 0 << ' ';
        cout << endl;
    }
}

void Graph::testMatrix(){
    vector<char> vertexs = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<vector<char>> arcs = {{'A', 'B'}, {'A', 'C'}, {'B', 'F'}, {'C', 'D'}, {'D', 'E'}};
    vector<int> weights = {1, 3, 5, 2, 4};
    bool ori = true;
    
    int nVertexs = vertexs.size();
    // cout << sizeof(vertexs) << ' ' << sizeof(int) << ' ' << nVertexs << endl;
    vector<vector<GMNode*>> matrix(nVertexs, vector<GMNode*>(nVertexs, 0));
    createGraphMatrix(arcs, weights, ori, matrix);
    printMatrix(matrix);
}


/* ------------------------------------ 图链表 ------------------------------------------ */
void Graph::createGraphTable(const vector<vector<char>> &letters, const vector<int> &weights, const bool &ori, vector<GTNode*> &table){
    map<char, int>* heads = new map<char, int>();  // 存储表头，用于判断是否需要重新创建表头
    map<char, int>::iterator it;
    int headId=0;

    for(int i=0; i<letters.size(); i++)
    {
        it = heads->find(letters[i][0]);  // 查找找到的表头
        if(it == heads->end()) // 创建新的表头
        {
            GTNode* n2 = new GTNode(letters[i][1], weights[i], nullptr);
            GTNode* n1 = new GTNode(letters[i][0], 0, n2);
            heads->insert(pair<char, int>(letters[i][0], headId++));
            table.push_back(n1);
        }
        else
        {
            GTNode* head = table[it->second];
            while(head->next)
                head = head->next;
            head->next = new GTNode(letters[i][1], weights[i], nullptr);
        }

        if (ori == false){      // 无向图，需要创建反向链接
            it = heads->find(letters[i][1]);  // 查找找到的表头
            if(it == heads->end()) // 创建新的表头
            {
                GTNode* n2 = new GTNode(letters[i][0], weights[i], nullptr);
                GTNode* n1 = new GTNode(letters[i][1], 0, n2);
                heads->insert(pair<char, int>(letters[i][1], headId++));
                table.push_back(n1);
            }
            else
            {
                GTNode* head = table[it->second];
                while(head->next)
                    head = head->next;
                head->next = new GTNode(letters[i][0], weights[i], nullptr);
            }            
        }
    }
}

void Graph::printTable(const vector<GTNode*> &table)
{
    for(int i=0; i<table.size(); i++){
        GTNode* n = table[i];
        cout << n->name;
        while(n->next){
            cout << " -" << n->next->weight << "-> " << n->next->name;
            n = n->next;
        }
        cout << endl;
    }
}

void Graph::testTable()
{
    vector<char> vertexs = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<vector<char>> arcs = {{'A', 'B'}, {'A', 'C'}, {'B', 'F'}, {'C', 'D'}, {'D', 'E'}};
    vector<int> weights = {1, 3, 5, 2, 4};
    bool ori = false;

    vector<GTNode*> table;
    createGraphTable(arcs, weights, ori, table);
    cout << table.size() << endl;   // bug: empty table
    printTable(table);
}
