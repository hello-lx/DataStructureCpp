#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include "DynamicArray.h"

typedef struct PERSON{
    LinkNode node;
    char name[64];
    int age;
} Person;

void MyPrint(LinkNode* node){
    Person* p = (Person*)node;
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int compareNode(LinkNode* n1, LinkNode* n2){
    Person* p1 = (Person*)(n1);
    Person* p2 = (Person*)(n2);
    
    if(p1->name == p2->name && p1->age == p2->age)
        return 0;
    
    return -1;
}

int main(int argc, char const *argv[])
{
    Person p1, p2, p3;
    p1.age = 10;
    p2.age = 20;
    p3.age = 30;

    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    
    LinkList* list = init_LinkList();
    InsertArr(list, 0,  (LinkNode*)&p1);
    InsertArr(list, 0,  (LinkNode*)&p2);
    InsertArr(list, 0,  (LinkNode*)&p3);    
    print_LInkList(list, MyPrint);
    printf("\n");
    
    removeArr(list, 1);
    print_LInkList(list, MyPrint);
    printf("\n");

    InsertArr(list, 2, (LinkNode*)&p2);
    print_LInkList(list, MyPrint);
    printf("\n");
    
    int pos = findArr(list, (LinkNode*)&p2, compareNode);
    printf("%d\n"file:///home/yuan/XSpace/Study/DataStructureCpp/std, pos);
    
    return 0;
}

