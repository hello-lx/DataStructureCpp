#include "QBase.h"

// -------------------------------- 链式栈 --------------------------------
// 1.2 定义链式存储栈模板
LinkStack::LinkStack()
{
    header = (Node*)malloc(sizeof(Node));
    size = 0;
}

LinkStack::~LinkStack()
{
    if(size > 0)
        size=0;
}

void LinkStack::push(int data){
    if(data <= 0)
    {
        cout << "入栈失败，入栈的数必须大于0" << endl;
        return;
    }

    Node* nodeTop = (Node*)malloc(sizeof(Node));
    nodeTop->data = data;
    nodeTop->next = header->next;
    header->next = nodeTop;
    size++;
}

void LinkStack::push(Node* node){
    if(node->data <= 0)
    {
        cout << "入栈失败，入栈的数必须大于0" << endl;
        return;
    }

    node->next = header->next;
    header->next = node;
    size++;
}

void LinkStack::pop(){
    if (size == 0)
        return;

    header->next = header->next->next;
    size--;
}

// int LinkStack::top(){
//     if (size == 0)
//         return -1;
    
//     return header->next->data;    
// }
Node* LinkStack::top(){
    if (size == 0)
        return nullptr;
    return header->next;
}


int LinkStack::getSize(){
    return size;
}

bool LinkStack::isEmpty(){
    if(size==0)
        return true;
    return false;
}

void LinkStack::print(){
    if(size == 0){
        cout << "栈为空～" << endl;
        return;
    }

    while(size > 0){
        cout << top()->data << endl;
        pop();
    }

    cout << "栈打印完毕～" << endl;
}

void testLinkStack(){
    LinkStack* stack = new LinkStack();

    int arr[] = {33, 21, 25, 16, 8};
    for(int i=0; i<5; i++){
        Node *node = (Node*)malloc(sizeof(Node));
        node->data = arr[i];
        stack->push(node);
        // stack->push(arr[i]);
    }

    stack->print();
}

// -------------------------------- 顺序栈 --------------------------------


// -------------------------------- 顺序队列 --------------------------------
// 2.1 定义顺序存储队列模板
SeqQueue::SeqQueue(){}

SeqQueue::~SeqQueue(){}

void SeqQueue::push(Node* node){
    arr.push_back(node);
    size++;
}

Node* SeqQueue::pop(){
    if(size==0)
        return nullptr;
    
    Node* node = arr[0];
    for(int i=0; i<size-1; i++)
        arr[i] = arr[i+1];
    arr.pop_back();
    size--;

    return node;
}

int SeqQueue::getSize(){
    return size;
}

bool SeqQueue::isEmpty(){
    if(size == 0)
        return true;
    return false;
}


// -------------------------------- 链式队列 --------------------------------
// 2.2 定义链式存储队列模板
LinkQueue::LinkQueue(){
    header = (Node*)(malloc(sizeof(Node)));
    size = 0;
}

LinkQueue::~LinkQueue(){
    free(this);
}

void LinkQueue::push(int data)
{
    if(data <= 0){
        cout << "插入失败， 数据必须大于0" << endl;
        return;
    }

    Node* last = header->next;
    if(size == 0){
        last = (Node*)(malloc(sizeof(Node)));
        last->data = data;
        header->next = last;
        size++;
        return;
    }

    
    while (last->next != nullptr)
        last = last->next;

    Node* cur = (Node*)(malloc(sizeof(Node)));
    cur->data = data;
    last->next = cur;
    size++;
}

void LinkQueue::push(Node* node)
{
    // if(node->data <= 0){
    //     cout << "插入失败， 数据必须大于0" << endl;
    //     return;
    // }

    Node* last = header->next;
    if(size == 0){
        header->next = node;
        size++;
        return;
    }

    
    while (last->next != nullptr)
        last = last->next;

    last->next = node;
    size++;
}

Node* LinkQueue::front(){
    if (size == 0)
        return nullptr;
    
    return header->next;
}

Node* LinkQueue::back(){
    if(size == 0)
        return nullptr;
    Node* last = header->next;
    while(last->next != nullptr)
        last = last->next;
    return last;
}

void LinkQueue::pop(){
    if(size==0)
        return;
    header->next = header->next->next;   
    size--;
}

int LinkQueue::getSize(){
    return size;
}

void LinkQueue::clear(){
    if(size > 0)
        header->next = nullptr;
}

void LinkQueue::print(){
    if(size == 0){
        cout << "队列为空～" << endl;
        return;
    }
    
    Node* cur = header->next;
    while(cur != nullptr){
        cout << cur->data << endl;
        cur = cur->next;
    }
    cout << "队列打印完毕～" << endl;
}

bool LinkQueue::isEmpty(){
    if (size > 0)
        return false;
    return true;
}


void testLinkQueue(){
    LinkQueue* q = new LinkQueue();

    int arr[] = {33, 21, 25, 16, 8};
    for(int i=0; i<5; i++){
        Node* node = (Node*)(malloc(sizeof(Node)));
        node->data = arr[i];
        q->push(node);
        // q->push(arr[i]);
    }
        
    q->print();    
}


// -------------------------------- 二叉树 --------------------------------
// 3.2 定义链式存储二叉树模板
BiTree::BiTree(){}

BiTree::BiTree(vector<char> &names, vector<int> &data){
    len = data.size();
    if(names.size() != data.size() || len == 0){
        cout << "Failure to create binary tree." << endl;
        return;
    }
    
    vector<Node*> nodes(len);
    root = (Node*)(malloc(sizeof(Node)));
    root->name = names[0];
    root->data = data[0];
    nodes[0] = root;

    for(int i=1; i<len; i++){
        Node *node = new Node(names[i], data[i]);
        nodes[i] = node;
    }

    
    for(int i=0; i<len; i++){
        Node *cur = nodes[i];

        if(i > 0)  // add parent node
            cur->parent = nodes[i/2];

        int lId = 2*i + 1, rId = 2*i + 2;
        if(lId < len)  // add lChild node
            cur->lChild = nodes[lId];
        if(rId < len)  // add rChild node
            cur->rChild = nodes[rId];
    }
}

Node* BiTree::getRoot(){
    return root;
}

int BiTree::getLen(){ return len; }

void BiTree::preOrder(Node* node){
    if(node == nullptr)
        return;
    cout << node->name << ' ';
    preOrder(node->lChild);
    preOrder(node->rChild);
}

void BiTree::inOrder(Node* node){
    if(node == nullptr)
        return;
    inOrder(node->lChild);
    cout << node->name << ' ';
    inOrder(node->rChild);
}

void BiTree::postOrder(Node* node){
    if(node == nullptr)
        return;
    postOrder(node->lChild);
    postOrder(node->rChild);
   cout << node->name << ' ';
 }

void testBiTree(){
/**                  A
 *                 /   \
 *                B     C
 *               / \   / \
 *              D   E F   G  
 */

    vector<char> names = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    vector<int> data = {1, 2, 3, 4, 5, 6, 7};
    BiTree* tree = new BiTree(names, data);
    cout << "A B D E C F G" << endl;
    tree->preOrder(tree->getRoot());
    cout << endl;
    
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
void Graph::createGraphMatrx(const vector<vector<char>> &letters, const vector<int> &weights, const bool &ori,
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

        if (ori)
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
    createGraphMatrx(arcs, weights, ori, matrix);
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
