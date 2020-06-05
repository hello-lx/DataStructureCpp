#include "DynamicArray.h"
#include <stdlib.h>
#include <stdio.h>

// 1. 初始化
LinkList* init_LinkList(){
        LinkList* list = (LinkList*)malloc(sizeof(LinkList));
        list->head.next = NULL;
        list->size = 0;
        return list;
}

// 2. 插入
void InsertArr(LinkList* list, int pos, LinkNode* node){
        if(list == NULL || node == NULL)
                return;
        
        if(pos < 0 || pos > list->size)
                return;
        
        LinkNode* pCurrent = &(list->head);
        for(int i=0; i<pos; i++){
                pCurrent = pCurrent->next;
        }

        node->next = pCurrent->next;
        pCurrent->next = node;

        list->size++;
}

// 3. 删除
void removeArr(LinkList* list, int pos){
// void remove_LinkList(LinkList* list, int pos){
        if(list == NULL)
                return;
        if(pos < 0 || pos > list->size)
                return;
        
        LinkNode* pCur = &(list->head);
        for(int i=0; i<pos; i++)
                pCur = pCur->next;
        
        pCur->next = pCur->next->next;
        list->size--;
}

// 4. 查找
int findArr(const LinkList* list, LinkNode* node, COMPARENODE compare){
    int pos = -1;
    
    LinkNode* curNode = list->head.next;
    for(int i=0; i<list->size; i++){
        if(compare(node, curNode) == 0)
            return i;
        curNode = curNode->next;
    }
    
    return -1;
}

// 4. 链表大小
int Size_LinkList(LinkList* list){

}

// 5. 返回第一个节点
void* Front_LinkList(LinkList* list){

}

// 6. 打印链表
void print_LInkList(LinkList* list, PRINTLINKNODE print){
        if(list == NULL)
                return;
        
        LinkNode* node = list->head.next;
        while (node != NULL){
                print(node);
                node = node->next;
        }
        
}

// 7. 释放内存
void free_LinkList(LinkList* list){
        if(list == NULL)
                return;
        free(list);
}
