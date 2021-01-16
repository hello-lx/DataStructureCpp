#ifndef Q53_H
#define Q53_H

#include<iostream>
#include<stdlib.h>
#include<stack>
#include<stdio.h>
#include<string.h>
using namespace std;

/* 5.3-综合题02：设计一个算法，判断一个无向图是否为一颗树
*/
#define INF_MAX 999999
const int vexNum = 9;
bool visits[vexNum];

typedef struct ENode
{
    int adjvex;     // 邻接顶点
    int weight;
    struct ENode *next; 
} ENode;

typedef struct VNode
{
    int in;
    int data;
    ENode *firstEdge;
} VNode, ADJList[vexNum];


typedef struct
{
    int vertexNum, edgeNum;  // 顶点数
    char vexs[vexNum];
    ADJList adjList;
} graphQ53, *GraphQ53;


int FirstNeighbor(graphQ53 &G, int v);

void DFS(graphQ53 &G, int v, int &VNum, int &ENum, bool visited[vexNum]);

bool isTree(graphQ53 g);


// bug
void hw02();

/* 5.3-综合题03：邻接表：深度优先搜索非递归
*/
#define MAX03 9
#define INF03 99999
typedef struct ENode03
{
    int adjvex = -1;
    int weight = -1;
    struct ENode03 *next = nullptr;
} ENode03;

typedef struct VNode03
{
    int vex = -1;
    int in = 0;
    ENode03 *firstEdge = nullptr;
} VNode03, AdjList03[MAX03];

typedef struct
{
    AdjList03 adjList;
    int vexNum;
    int edgeNum;
    int visited[MAX03];
} Graph03;

// void CreateGraph03(Graph03 *g);
Graph03* CreateGraph03();

void DFS03(Graph03 *g, int vexId);

void hw03();


/* 5.3-综合题04：邻接表(有向图)：分别用深度优先和广度优先判断是否右 Vi 到 Vj 的路径 (i != j)
*/
void hw04();

#endif