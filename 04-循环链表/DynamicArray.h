#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0

typedef struct CIRCLELINKNODE{
    struct CIRCLELINKNODE* next;
} CircleLinkNode;

typedef struct CIRCLELINKLIST
{
    CircleLinkNode head;
    int size;
} CircleLinkList;

// 比较回调
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);
// 打印回调
typedef void(*PRINTNODE)(CircleLinkNode*);

CircleLinkList* init_CircleLinkList();

void insert_CircleLinkList(CircleLinkList* list, int pos, CircleLinkNode* node);

void remove_CircleLinkList(CircleLinkList* list, int pos);

void removeByValue_CircleLinkList(CircleLinkList* list, CircleLinkNode* node, COMPARENODE copare);

int size_CircleLinkList(CircleLinkList* list);

int isEmpty_CircleLinkList(CircleLinkList* list);

int find_CircleLinkList(CircleLinkList* list, CircleLinkNode* data, COMPARENODE compare);

void print_CircleLinkList(CircleLinkList* list, PRINTNODE print);

void free_CircleLinkList(CircleLinkList* list);

#endif
