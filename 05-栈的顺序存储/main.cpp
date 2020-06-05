#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "DynamicArray.h"

typedef struct PERSON
{
    char name[32];
    int age;
}Person;



int main(int argc, char const *argv[])
{
    SeqStack* stack = initStack();
    Person p1 = {"aaa", 10};
    pushStack(stack, &p1);
    Person p2 = {"bbb", 20};
    pushStack(stack, &p2);
    Person p3 = {"ccc", 30};
    pushStack(stack, &p3);

    while (sizeStack(stack) > 0)
    {
        Person* p = (Person*)topStack(stack);
        printf("name: %s\t age: %d\n", p->name, p->age);
        popStack(stack);
    }
    
    freeStack(stack);
    return 0;
}

