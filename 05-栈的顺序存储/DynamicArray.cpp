#include "DynamicArray.h"


SeqStack* initStack(){
    SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
    for(int i=0; i<MAX_SIZE; i++){
            stack->data[i] = NULL;
    }
    stack->size = 0;
    return stack;
}

void pushStack(SeqStack* stack, void* data){
        if(stack == NULL || data == NULL || stack->size == MAX_SIZE)
                return;

        stack->data[stack->size++] = data;
}

void popStack(SeqStack* stack){
        if(stack == NULL || stack->size == 0)
                return;
        
        stack->data[stack->size--] == 0;
}

void* topStack(SeqStack* stack){
        if(stack == NULL)
                return NULL;
        // printf("size: %d", stack->size);
        return stack->data[stack->size-1];
}

int isEmpty(SeqStack* stack){
        if(stack == NULL)
                return 0;
        if(stack->size == 0)
                return SEQSTACK_TRUE;
        return SEQSTACK_FALSE;
}

int sizeStack(SeqStack* stack){
        return stack->size;
}

void clearStack(SeqStack* stack){
        if(stack == NULL)
                return;
        for(int i=0; i<stack->size; i++)
                stack->data[i] = NULL;
        stack->size = 0;
}

void freeStack(SeqStack* stack){
        if(stack==NULL)
                return;
        free(stack);
}
