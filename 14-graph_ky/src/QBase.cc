#include "QBase.h"

// -------------------------------- 分界线 --------------------------------
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

// -------------------------------- 分界线 --------------------------------
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


// -------------------------------- 分界线 --------------------------------
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


// -------------------------------- 分界线 --------------------------------
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

