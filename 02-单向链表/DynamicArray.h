#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H


typedef struct NODE
{
    void* value;
    struct NODE* next;
} Node;


typedef struct LINK_LIST
{
    /* data */
    Node* head;
    int size;
} LinkList;

typedef void(*PRINTLINKNODE)(void*);

// 1. 初始化
LinkList* init_LinkList();
// 2. 插入
void insert_LinkList(LinkList* list, int pos, Node* val);
// 3. 删除
void remove_LinkList(LinkList* list, int pos);
// 4. 查找
int find_Node(LinkList* list,  Node* data);
// 4. 链表大小
int Size_LinkList(LinkList* list);
// 5. 返回第一个节点
void* Front_LinkList(LinkList* list);
// 6. 打印链表
void print_LInkList(LinkList* list, PRINTLINKNODE print);
// 7. 释放内存
void free_LinkList(LinkList* list);

#endif