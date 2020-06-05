#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// 1. 初始化
LinkList* init_LinkList(){
        LinkList* list = (LinkList*)malloc(sizeof(LinkList));
        list->size = 0;
        list->head = (Node*)malloc(sizeof(Node));
        return list;
}


// 2. 插入
void insert_LinkList(LinkList* list, int pos, void* val){
        if(list == NULL)
                return;
        
        if(pos < 0 || pos >list->size)
                return;

        Node* cur = list->head;
        for(int i=0; i<pos; i++)
                cur = cur->next;

        Node* node = (Node*)malloc(sizeof(Node));
        node->next = cur->next;
        node->value = val;

        cur->next = node;

        list->size++;

        // return list;
}


// 3. 删除
void remove_LinkList(LinkList* list, int pos){
        if(list == NULL)
                return;
        
        if(pos < 0 || pos >list->size)
                return;

        Node* curNode = list->head;
        for (int i=0; i<pos; i++)
                curNode = curNode->next;
        
        Node* delNode = curNode->next;
        curNode->next = delNode->next;

        free(delNode);

        list->size--;
        // return list;
}


// 4. 查找
int find_Node(LinkList* list,  void* data){
        int pos = -1;

        if(list == NULL || data == NULL)
                return pos;
        
        // Node* curNode = list->head;
        // for(int i=0; i<list->size; i++){
        //         if(data == curNode->value)
        //                 return i;
        //         curNode = curNode->next;
        // }

        Node* curNode = list->head->next;
        int  idx=0;
        while (curNode != NULL)
        {
                if(curNode->value == data)
                        return  idx;
                idx++;
                curNode = curNode->next;
        }
        

        return pos;
}


// 4. 链表大小
int Size_LinkList(LinkList* list){
        if(list == NULL)
                return 0;
        
        return list->size;
}


// 5. 返回第一个节点
void* Front_LinkList(LinkList* list){
        // if(list == NULL)
        //         return NULL;
        return list->head->next->value;
}


// 6. 打印链表
void print_LInkList(LinkList* list, PRINTLINKNODE print){
        if(list == NULL)
                return;
        
        Node* curNode = list->head->next;
        while (curNode != NULL)
        {
                print(curNode->value);
                curNode = curNode->next;
        }
}


// 7. 释放内存
void free_LinkList(LinkList* list){
        if(list == NULL)
                return;
        
        Node* curNode = list->head->next;
        while (curNode != NULL)
        {
                Node* nextNode = curNode->next;
                free(curNode);
                curNode = nextNode;
        }
        
        list->size = 0;
        free(list);

}
