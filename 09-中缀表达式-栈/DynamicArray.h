#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdio.h>



typedef struct LINKNODE{
    struct LINKNODE* next;
} LinkNode;


typedef struct LINKSTACK
{
    LinkNode head;
    int size;
} LinkStack;

LinkStack* initStack();

void pushStack(LinkStack* stack, LinkNode* node);

LinkNode* topStack(LinkStack* stack);

void popStack(LinkStack* stack);

int sizeStack(LinkStack* stack);

int isEmpty(LinkStack* stack);

void clearStack(LinkStack* stack);

void freeStack(LinkStack* stack);

#endif
