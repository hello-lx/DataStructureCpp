#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdlib.h>

#define  MaxSize 1024

typedef struct SEQQUEUE
{
    /* data */
    void* data[MaxSize];
    int size;
} SeqQueue;

SeqQueue* init_SeqQueue();

void Push_SeqQueue(SeqQueue* queue,  void* data);

void* Front_SeqQueue(SeqQueue* queue);

void* Back_SeqQueue(SeqQueue* queue);

void Pop_SeqQueue(SeqQueue* queue);

void clear_SeqQueue(SeqQueue* queue);

void free_SeqQueue(SeqQueue* queue);

#endif