#include "DynamicArray.h"

SeqQueue* init_SeqQueue(){
        SeqQueue* data = (SeqQueue*)malloc(sizeof(SeqQueue));
        data->size = 0;
        return data;
}

void Push_SeqQueue(SeqQueue* queue,  void* data){
        if(queue == NULL || data == NULL)
                return;
        
        // if(queue->size == MaxSize)  // 重新设置data的大小
        // {
        //         int num = queue->size / MaxSize;
        //         SeqQueue* data_new = (SeqQueue*)malloc(sizeof(SeqQueue));
        // }
        
        queue->data[queue->size] = data;
        queue->size++;
}

void* Front_SeqQueue(SeqQueue* queue){
        if(queue == NULL)
                return NULL;
        if(queue->size == 0)
                return NULL;
        
        return queue->data[0];
}

void* Back_SeqQueue(SeqQueue* queue){
        if(queue == NULL)
                return NULL;
        if(queue->size == 0)
                return NULL;
        
        return queue->data[queue->size-1];
}

void Pop_SeqQueue(SeqQueue* queue){
        if(queue == NULL)
                return;
        
        if(queue->size == 0)
                return;
        
        for(int i=0; i<queue->size-1; i++)
                queue->data[i] = queue->data[i+1];
        queue->size--;
}

void clear_SeqQueue(SeqQueue* queue){
        if(queue==NULL)
                return;
        
        queue->size = 0;
}

void free_SeqQueue(SeqQueue* queue){
        if(queue == NULL)
                return;

        free(queue);
}
