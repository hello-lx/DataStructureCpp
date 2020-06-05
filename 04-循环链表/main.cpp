#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "DynamicArray.h"

typedef struct  PERSON
{
    CircleLinkNode* node;
    char name[64];
    int age;
    int score;
}Person;

void MyPrint(CircleLinkNode* node){
    Person* person = (Person*)node;

    if (person->age != 0)
        printf("name: %s, age: %d, score: %d\n", person->name, person->age, person->score);
}

int compare(CircleLinkNode* n1, CircleLinkNode* n2){
    Person* p1 = (Person*)n1;
    Person* p2 = (Person*)n2;
    
    if(strcmp(p1->name, p2->name) == 0 && p1->age == p2->age && p1->score == p2->score)
        return CIRCLELINKLIST_TRUE;

    return CIRCLELINKLIST_FALSE;
}


typedef struct NUM
{
    CircleLinkNode* node;
    int val;
} Num;

void PrintNum(CircleLinkNode* node){ 
    Num* n = (Num*)&node;
    printf("val: %d\n", n->val);
}

int compareNum(CircleLinkNode* n1, CircleLinkNode* n2){
    Num* num1 = (Num*)n1;
    Num* num2 = (Num*)n1;
    if(num1->val == num2->val)
        return CIRCLELINKLIST_TRUE;
    
    return CIRCLELINKLIST_FALSE;
}

int main(int argc, char const *argv[])
{
    CircleLinkList* clist = init_CircleLinkList();

    // Num n;
    // n.val = 10;
    // CircleLinkNode* node = (CircleLinkNode*)&n;
    // Num* n2 = (Num*)&node;
    // printf(n2->val);

    int M = 10;
    Num num[M];
    for(int i=0; i<M; i++){
        num[i].val = i+1;
        CircleLinkNode* n = (CircleLinkNode*)&num[i];
        // PrintNum(n);
        printf("num: %d\n", num[i].val);
        insert_CircleLinkList(clist, 0, (CircleLinkNode*)&num[i]);
    }
    printf("\n");
    print_CircleLinkList(clist, PrintNum);

    // int N = 3;
    // int index = 0;
    // CircleLinkNode* pCur = (CircleLinkNode*)clist->head.next;
    // while (size_CircleLinkList(clist)>1)
    // {
    //     if(index == N){
    //         Num* n = (Num*)pCur;
    //         printf("%d ", n);

    //         CircleLinkNode* pNext = pCur->next;
    //         removeByValue_CircleLinkList(clist, pCur, compareNum);
    //         pCur = pNext;
    //         if(pCur == &(clist->head))
    //             pCur = pCur->next;
    //         index = 1;
    //     }
    //     pCur = pCur->next;
    //     index++;
    // }
    
    // if(size_CircleLinkList(clist) == 1){
    //     CircleLinkNode* node = &(clist->head);
    //     Num* n = (Num*)node;
    //     printf(n->val);
    // }
    // else
    //     printf("error~");
}

// int main(int argc, char const *argv[])
// {
//     CircleLinkList* clist = init_CircleLinkList();
    
//     Person p1;
//     strcpy(p1.name, "aaa");
//     p1.age = 10;
//     p1.score = 88;

//     Person p2;
//     strcpy(p2.name, "bbb");
//     p2.age = 20;
//     p2.score = 78;
        
//     Person p3;
//     strcpy(p3.name, "ccc");
//     p3.age = 30;
//     p3.score = 98;
    
//     insert_CircleLinkList(clist, 0, (CircleLinkNode*)&p1);
//     insert_CircleLinkList(clist, 1, (CircleLinkNode*)&p2);
//     insert_CircleLinkList(clist, 2, (CircleLinkNode*)&p3);
//     print_CircleLinkList(clist, MyPrint);
//     printf("\n");

//     removeByValue_CircleLinkList(clist, (CircleLinkNode*)&p2, compare);
//     print_CircleLinkList(clist, MyPrint);
//     printf("\n");
//     return 0;
// }

