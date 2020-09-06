#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include "DynamicArray.h"
using namespace std;

int GetPriority(char c){
    if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    return 0;
}

int isNumber(char c){
    return c <= '9' && c >= '0';
}

int isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void NumberOperator(char* c){
//     printf("%c\n", *c);
}

typedef struct MYCHAR{
    LinkNode node;
    char* p;;
} MyChar;

MyChar* CreateMyChar(char* p){
    MyChar* c = (MyChar*)malloc(sizeof(MyChar));
    c->p = p;
    return c;
}

int isLeft(char* p){
    return *p == '(';
}

void LeftOperate(LinkStack* stack, char* p){
    MyChar* c = CreateMyChar(p);
//     printf("%c \n", *(c->p));  // test
    pushStack(stack, (LinkNode*)c);
}

int isRight(char* p){
    return *p == ')';
}

void RightOperate(LinkStack* stack){
    while(sizeStack(stack) > 0){
        MyChar* c = (MyChar*)topStack(stack);
        if(isLeft(c->p)){
//             printf("%c \n", *(c->p));  // test
            popStack(stack);
            break;
        }
        popStack(stack);
        free(c);
    }
}

void OperatorOperate(LinkStack* stack, char* p){
    MyChar* stack_char = (MyChar*)topStack(stack);
    if(stack_char == NULL){
        LinkNode* node = (LinkNode*)CreateMyChar(p);
        pushStack(stack, node);
        return;
    }
    
    // 若栈顶的优先级小于插入的字符，则直接插入栈顶
    if(GetPriority(*(stack_char->p)) < GetPriority(*p)){
        pushStack(stack, (LinkNode*)CreateMyChar(p));
        return;
    }else{
        printf("==>%c ", *p);
        while(sizeStack(stack) > 0){
            stack_char = (MyChar*)topStack(stack);
            if(GetPriority(*(stack_char->p)) < GetPriority(*p)){
                pushStack(stack, (LinkNode*)CreateMyChar(p));
                return;
            }
            popStack(stack);
        }
    }
}


int main()
{
    char* str = "8+(3-1)*5";
    char* p = str;
    
    LinkStack* stack = initStack();
//     while(*p != '\0'){
//         printf("%c ", *p);
//         cout << *p << endl;
//         p++;
//     }
    
    while(*p != '\0'){
        
        if(isNumber(*p))
            NumberOperator(p);
        if(isLeft(p))
            LeftOperate(stack, p);
        if(isRight(p))
            RightOperate(stack);
        
        OperatorOperate(stack, p);
        p++;
    }
    
    printf("\n");
    return 0;
}

