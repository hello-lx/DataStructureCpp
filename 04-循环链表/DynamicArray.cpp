#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

CircleLinkList* init_CircleLinkList()
{
        CircleLinkList* list = (CircleLinkList*)(malloc(sizeof(CircleLinkList)));
        list->size = 0;
        list->head.next = &(list->head);

        return list;
}

void insert_CircleLinkList(CircleLinkList* list, int pos, CircleLinkNode* node)
{
        if(list == NULL)
                return;
        if(pos<0 || pos >list->size)
                pos = list->size;

        CircleLinkNode* nodeCur = &(list->head);
        for(int i=0; i<pos; i++)
                nodeCur = nodeCur->next;
        
        node->next = nodeCur->next;
        nodeCur->next = node;

        list->size++;
}

void remove_CircleLinkList(CircleLinkList* list, int pos)
{
        if(list == NULL)
                return;
        
        if(pos < 0 || pos > list->size)
                return;

        CircleLinkNode* nodeCur = &(list->head);
        for(int i=0; i<pos; i++)
                nodeCur = nodeCur->next;
        
        CircleLinkNode* nodeDel = nodeCur->next;
        nodeCur->next = nodeCur->next;
        
        list->size--;
}

void removeByValue_CircleLinkList(CircleLinkList* list, CircleLinkNode* node, COMPARENODE compare){
        if(list == NULL || node == NULL)
                return;
        
        CircleLinkNode* pPrev = &(list->head);
        CircleLinkNode* pCur = pPrev->next;
        for(int i=0; i<list->size; i++){
                if(compare(pCur, node) == CIRCLELINKLIST_TRUE){
                        pPrev->next = pCur->next;
                        break;
                }
                pPrev = pCur;
                pCur = pPrev->next;
        }
}

int size_CircleLinkList(CircleLinkList* list)
{
        if(list==NULL)
                return 0;
        return list->size;
}

int isEmpty_CircleLinkList(CircleLinkList* list)
{       
        if(list == NULL)
                return 1;
        
        if(&list->head == list->head.next || list->size == 0)
                return CIRCLELINKLIST_TRUE;
        return CIRCLELINKLIST_FALSE;
}

int find_CircleLinkList(CircleLinkList* list, CircleLinkNode* data, COMPARENODE compare)
{
        int pos = -1;
        if(list == NULL || data == NULL)
                return pos;

        CircleLinkNode* pCur = &(list->head);
        for(int i=0; i<list->size; i++){
                if(compare(pCur, data) == CIRCLELINKLIST_TRUE){
                        pos = i;
                        break;
                }
                pCur = pCur->next;
        }
        return pos;
}

void print_CircleLinkList(CircleLinkList* list, PRINTNODE print)
{
        if(list==NULL)
                return;
        
        CircleLinkNode* pCur = list->head.next;
        for(int i=0; i<list->size; i++){
                print(pCur);
                pCur = pCur->next;
        }

        // for(int i=0; i<list->size*2; i++){
        //         if(pCur == &(list->head))
        //                 pCur = list->head.next;
        //         print(pCur);
        //         pCur = pCur->next;
        // }
}

void free_CircleLinkList(CircleLinkList* list)
{
        if(list==NULL)
                return;
        
        free(list);

        // CircleLinkNode* node = list->head.next;
        
        // for(int i=0; i<list->size; i++){
        //         CircleLinkNode* temp = node->next;
        //         free(node);
        //         node = temp;
        // }
}
