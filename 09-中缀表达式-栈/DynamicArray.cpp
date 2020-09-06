#include "DynamicArray.h"

LinkStack* initStack(){
    LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
    stack->size = 0;
    return stack;
}

void pushStack(LinkStack* stack, LinkNode* node){
    if(stack == NULL || node == NULL)
        return;
    
    node->next = stack->head.next;
    stack->head.next = node;
    stack->size++;
}

LinkNode* topStack(LinkStack* stack){
    if(stack==NULL)
        return NULL;
    
    return stack->head.next;
}


void popStack(LinkStack* stack){
    if(stack==NULL)
        return;
    if(stack->size == 0)
        return;
    
    LinkNode* pCur = stack->head.next;
    stack->head.next = pCur->next;
    stack->size--;
}

int sizeStack(LinkStack* stack){
    if(stack == NULL)
        return 0;
    return stack->size;
}

int isEmpty(LinkStack* stack){
    if(stack == NULL)
        return -1;
    return stack->size == 0;
}

void clearStack(LinkStack* stack){
    if(stack==NULL)
        return;
    stack->size = 0;
    stack->head.next = NULL;
}

void freeStack(LinkStack* stack){
    if(stack==NULL)
        return;
    
    free(stack);
}
