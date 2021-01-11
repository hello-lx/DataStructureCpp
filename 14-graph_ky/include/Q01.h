#ifndef Q01_H
#define Q01_H

#include <stdio.h>
#include <stdlib.h>

/* ################# 邻接表图和矩阵图的深度搜索和广度搜索 ################# */
// blog: https://www.cnblogs.com/mix88/p/6241627.html?utm_source=itdadao&utm_medium=referral

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 9
#define MAXEDGE 15
#define MAXVEX 9

typedef int Status;   /* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef int Boolean;  /* Boolean是布尔类型,其值是TRUE或FALSE */

typedef char VertexType;        /* 顶点类型应由用户定义 */  
typedef int EdgeType;           /* 边上的权值类型应由用户定义 */  


// 1. 邻接矩阵结构
typedef struct
{
    VertexType vexs[MAXVEX];      // 顶点表
    EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵，可看作边表

    int numVertexes, numEdges;    // 图中当前的顶点和边数
} MGraph;



// 2. 邻接表结构
typedef struct EdgeNode     /* 边表结点 */ 
{
    int adjvex;             /* 邻接点域,存储该顶点对应的下标 */
    int weight;             /* 用于存储权值,对于非网图可以不需要 */
    struct EdgeNode* next;  /* 链域,指向下一个邻接点 */ 
} EdgeNode;

typedef struct VertexNode   /* 顶点表节点 */
{
    int in;                 /* 顶点入度 */
    char data;              /* 顶点域， 存储顶点信息 */
    EdgeNode *firstEdge;    /* 边表头指针 */
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    VertexType vexs[MAXVEX];
    int numVertexes, numEdges;   // 图中当前顶点数和边数

} graphAdjList, *GraphAdjList;



// 3. 准备：需要用到的队列和函数
typedef struct                    /* 循环队列的顺序存储结构 */
{
    int data[MAXSIZE];
    int front;                    /* 头指针 */
    int rear;                     /* 尾指针,若队列不空,指向队列尾元素的下一个位置 */
} Queue;

Status InitQueue(Queue *Q);

Status QueueEmpty(Queue Q);

Status EnQueue(Queue *Q, int e);

Status DeQueue(Queue *Q, int *e);

void CreateMGraph(MGraph *G);

void CreateALGraph(MGraph G, GraphAdjList *GL);


/* ----------------- 一：邻接链表的深度搜索和广度搜索 ----------------- */
Boolean visited[MAXSIZE];

/* 邻接表的深度优先递归算法 */
void DFS(GraphAdjList GL, int adjvex);


/* 邻接表的深度遍历操作 */
void DFSTraverse(GraphAdjList GL);


/* 邻接表的广度遍历算法 */
void BFSTraverse(GraphAdjList GL);



/* ----------------- 二：矩阵的深度搜索和广度搜索 ----------------- */
Boolean visited2[MAXSIZE];

/* 图矩阵的深度优先递归算法 */
void DFS(MGraph GM, int vertexId);

/* 图矩阵的深度遍历操作 */
void DFSTraverse(MGraph GM);

/* 图矩阵的广度遍历操作 */
void BFSTraverse(MGraph GM);

#endif