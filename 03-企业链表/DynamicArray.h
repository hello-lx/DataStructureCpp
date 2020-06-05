#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct LINKNODE
{
    struct LINKNODE* next;
} LinkNode;

typedef struct LINKLIST
{
    /* data */
    LinkNode head;
    int size;
} LinkList;

typedef void(*PRINTLINKNODE)(LinkNode*);
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);

LinkList* init_LinkList();

void InsertArr(LinkList* list, int pos, LinkNode* node);

void removeArr(LinkList* list, int pos);

LinkList* editArr(LinkList* arr, int pos, int val);

void print_LInkList(LinkList* list, PRINTLINKNODE print);

int findArr(const LinkList* list, LinkNode* node, COMPARENODE compare);

#endif
