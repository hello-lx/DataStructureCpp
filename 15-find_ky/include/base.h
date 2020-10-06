#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <vector>
using namespace std;



// 1.1 定义顺序存储栈模板


// 1.2 定义链式存储栈模板
template<class T>
typedef struct StackNode
{
    T key;
    struct StackNode *next;    
} SNode;

template<class T>
class LinkStack
{
private:
    T key;
    /* data */
public:
    LinkStack(/* args */);
    LinkStack(T *n);
    ~LinkStack();    
};




// 2.1 定义顺序存储栈模板


// 2.2 定义链式存储栈模板



// 3.1 定义顺序存储二叉树模板


// 3.2 定义链式存储二叉树模板

#endif