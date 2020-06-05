#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0

typedef struct SEQSTACK
{
    /* data */
    void* data[MAX_SIZE];
    int size;
} SeqStack;

SeqStack* initStack();

void pushStack(SeqStack* stack, void* data);

void* topStack(SeqStack* stack);

void popStack(SeqStack* stack);

int isEmpty(SeqStack* stack);

int sizeStack(SeqStack* stack);

void clearStack(SeqStack* stack);

void freeStack(SeqStack* stack);

#endif