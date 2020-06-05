#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
#include "DynamicArray.h"

typedef struct PERSON{
    char name[64];
    int age;
    int score;
} Person;

void MyPrint(void* data){
    Person* p = (Person*)data;
    printf("Name: %s,   Age: %d    Score: %d \n", p->name, p->age,  p->score);
}

void test(){
    Person p1 = {"aaa", 10, 90};
    Person p2 = {"bbb", 20, 88};
    Person p3 = {"ccc", 30, 94};
    
    LinkList* list = init_LinkList();
    insert_LinkList(list, 0, &p1);
    cout << list->size << endl;
    insert_LinkList(list, 1, &p2);
    cout << list->size << endl;
    insert_LinkList(list, 2, &p3);
    cout << list->size << endl;
    
    print_LInkList(list, MyPrint);
    
    cout << endl;
    remove_LinkList(list, 1);
    print_LInkList(list, MyPrint);
    
    cout << endl;
    Person* p = (Person*)Front_LinkList(list);
    printf("Name: %s,   Age: %d    Score: %d \n", p->name, p->age,  p->score);
    // MyPrint(p);

    free_LinkList(list);



}


int main(int argc, char const *argv[])
{
    test();
    return 0;
}

