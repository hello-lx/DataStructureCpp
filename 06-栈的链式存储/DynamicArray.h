#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#define LINKSTACK_TRUE 1
#define LINKSTACK_FALSE 0

typedef struct  LINKNODE
{
    struct LINKNODE* next;
}LinkNode;

typedef struct LINKSTACK
{
    /* data */
    LinkNode head;
    int size;
    
} LinkStack;

typedef void (*PRINTLINKSTACK)(LinkNode*);

LinkStack* initLinkStack();

void pushLinkStack(LinkStack* stack, LinkNode* node);

LinkNode* topLinkStack(LinkStack* stack);

void popLinkStack(LinkStack* stack);

void printLinkStack(LinkStack* stack,  PRINTLINKSTACK printLinkStack);

int isEmpty(LinkStack* stack);

int sizeLinkStack(LinkStack* stack);

void clearLinkStack(LinkStack* stack);

void freeLinkStack(LinkStack* stack);

#endif