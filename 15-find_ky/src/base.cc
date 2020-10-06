#include "base.h"

// -------------------------------- 分界线 --------------------------------
// 1.2 定义链式存储栈模板
LinkStack::LinkStack()
{
    header = (SNode*)malloc(sizeof(SNode));
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

    SNode* nodeTop = (SNode*)malloc(sizeof(SNode));
    nodeTop->data = data;
    nodeTop->next = header->next;
    header->next = nodeTop;
    size++;
}

void LinkStack::pop(){
    if (size == 0)
        return;

    header->next = header->next->next;
    size--;
}

int LinkStack::top(){
    if (size == 0)
        return -1;
    
    return header->next->data;    
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
        cout << top() << endl;
        pop();
    }

    cout << "栈打印完毕～" << endl;
}

void testLinkStack(){
    LinkStack* stack = new LinkStack();

    int arr[] = {33, 21, 25, 16, 8};
    for(int i=0; i<5; i++)
        stack->push(arr[i]);

    stack->print();
}

// -------------------------------- 分界线 --------------------------------
// 2.2 定义链式存储队列模板
LinkQueue::LinkQueue(){
    header = (QNode*)(malloc(sizeof(QNode)));
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

    QNode* last = header->next;
    if(size == 0){
        last = (QNode*)(malloc(sizeof(QNode)));
        last->data = data;
        header->next = last;
        size++;
        return;
    }

    
    while (last->next != nullptr)
        last = last->next;

    QNode* cur = (QNode*)(malloc(sizeof(QNode)));
    cur->data = data;
    last->next = cur;
    size++;
}

int LinkQueue::front(){
    if (size == 0)
        return -1;
    
    return header->next->data;
}

int LinkQueue::back(){
    if(size == 0)
        return -1;
    QNode* last = header->next;
    while(last->next != nullptr)
        last = last->next;
    return last->data;
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
    
    QNode* cur = header->next;
    while(cur != nullptr){
        cout << cur->data << endl;
        cur = cur->next;
    }
    cout << "队列打印完毕～" << endl;
}

void testLinkQueue(){
    LinkQueue* q = new LinkQueue();

    int arr[] = {33, 21, 25, 16, 8};
    for(int i=0; i<5; i++)
        q->push(arr[i]);
        
    q->print();    
}

// -------------------------------- 分界线 --------------------------------
