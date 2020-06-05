#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "DynamicArray.h"

typedef struct PERSON
{
    char name[64];
    int age;
}Person;

int main(int argc, char const *argv[])
{
    Person p1 = {"aaa", 10};
    Person p2 = {"bbb", 20};
    Person p3 = {"ccc", 30};
    
    SeqQueue* queue = (SeqQueue*)init_SeqQueue();
    printf("size: %d\n", queue->size);

    Push_SeqQueue(queue, &p1);
    Push_SeqQueue(queue, &p2);
    Push_SeqQueue(queue, &p3);
    
    Person* p = (Person*)Back_SeqQueue(queue);
    printf("name: %s \t  age: %d\n", p->name, p->age);

    while (queue->size > 0)
    {
        p = (Person*)Front_SeqQueue(queue);
        printf("name: %s \t  age: %d\n", p->name, p->age);
        Pop_SeqQueue(queue);
    }
    
    free_SeqQueue(queue);

    return 0;
}

