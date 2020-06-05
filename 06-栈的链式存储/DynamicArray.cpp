#include "DynamicArray.h"


LinkStack* initLinkStack(){
        LinkStack* stack = (LinkStack*)(malloc(sizeof(LinkStack)));
        stack->size = 0;
        stack->head.next = NULL;
        return stack;
}

void pushLinkStack(LinkStack* stack, LinkNode* node){
        if(stack == NULL || node == NULL)
                return;
        node->next = stack->head.next;
        stack->head.next = node;
        stack->size++;
}

LinkNode* topLinkStack(LinkStack* stack){
        if(stack == NULL || stack->size == 0)
                return NULL;
        
        return stack->head.next;
}

void popLinkStack(LinkStack* stack){
        if(stack == NULL)
                return;
        
        if(stack->size == 0)
                return;

        LinkNode* nodeDel = stack->head.next;
        stack->head.next = nodeDel->next;
        stack->size--;
}

int isEmpty(LinkStack* stack){
        if(stack == NULL)
                return LINKSTACK_FALSE;
        if(stack->size == 0)
                return LINKSTACK_FALSE;
        return LINKSTACK_TRUE;
}

int sizeLinkStack(LinkStack* stack){
        if(stack == NULL)
                return -1;
        return stack->size;
}

void clearLinkStack(LinkStack* stack){
        if(stack == NULL)
                return;
        stack->head.next = NULL;
        stack->size = 0;
}

void freeLinkStack(LinkStack* stack){
        if(stack == NULL)
                return;

        free(stack);
}
