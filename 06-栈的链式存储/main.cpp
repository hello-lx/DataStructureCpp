#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "DynamicArray.h"

typedef struct PERSON
{
    LinkNode node;
    char name[64];
    int age;
}Person;

void printLinkNode(LinkNode* data){
    Person* p = (Person*)data;
    printf("name: %s\t age: %d\n", p->name, p->age);
}


int main(int argc, char const *argv[])
{
    Person p1, p2, p3;
    strcpy(p1.name, "aaa");
    p1.age = 10;
    strcpy(p2.name, "bbb");
    p2.age = 20;
    strcpy(p3.name, "ccc");
    p3.age = 30;
    
    LinkStack* stack = initLinkStack();
    pushLinkStack(stack, (LinkNode*)&p1);
    pushLinkStack(stack, (LinkNode*)&p2);
    pushLinkStack(stack, (LinkNode*)&p3);

    while (sizeLinkStack(stack) > 0)
    {
        LinkNode* node = topLinkStack(stack);
        popLinkStack(stack);
    }

    freeLinkStack(stack);    

    return 0;
}

