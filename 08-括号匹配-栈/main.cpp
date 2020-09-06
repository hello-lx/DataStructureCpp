#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "DynamicArray.h"

typedef struct  MYCHAR
{
    LinkNode node;
    char* pAddres;
    int index;
}MyChar;

int isLeft(char c){
    return c == '(';
}

int isRight(char c){   
    return c == ')';
}

MyChar* CreateMyChar(char* p, int index){
    MyChar* myChar = (MyChar*)malloc(sizeof(p));
    myChar->pAddres = p;
    myChar->index = index;
    return myChar;
}

void printError(char* p, int pos){
    printf("%s\n", p);
    for(int i=0; i<pos; i++){
        printf(" ");
    }
    printf("=>");
}

int main(int argc, char const *argv[])
{
    char* str = "1+2+(23+4)+(55+(32+1)))+100";
    char* p = str;
    int index = 0;
    LinkStack* stack = initLinkStack();

    while (*p != '\0')
    {
//         printf("==>%s\n", p);
        if(isLeft(*p)){
            pushLinkStack(stack, (LinkNode*)CreateMyChar(p, index));
        }else if(isRight(*p)){
            MyChar* top = (MyChar*)topLinkStack(stack);
            if(isLeft(*(top->pAddres))){
                popLinkStack(stack);
                free(top);
            }
            else{
                printf("右括号没有匹配的左括号：\n");
                printError(top->pAddres, index);
                break;
            }
        }
        p++;
        index++;
    }
    
    
    while(sizeLinkStack(stack) > 0){
        MyChar* mychar = (MyChar*)topLinkStack(stack);
        printf("左括号没有匹配的右括号\n");
        printError(str, mychar->index);
        popLinkStack(stack);
    }
    
    if(isEmpty(stack)){
        printf("Good\n");
    }else{
        printf("Bad\n");
    }
    return 0;
}

