#ifndef Q02_H
#define Q02_H

#include <stdio.h>
#include <stdlib.h>

/**
 * 图应用一：生成最小树（带权图）
 * 算法： Prim 和 Kruskal(并查集 Elog(E))
*/

#define INFINITY 65535

#define MAXSIZE 9
#define MAXEDGE 15
#define MAXVEX 9

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


// 3. 回环结构 (Prim)
typedef struct
{
    int adjvex;
    EdgeType lowcost;
} CloseEdge[MAXVEX];

CloseEdge gClose; // 全局数组

// 4. 边 (Kruskal)
typedef struct Edge
{
    int startVex;
    int endVex;
    int weight;
} Edge;

// 定义辅助数组
typedef struct Assist
{
    int value;      // 顶点数据
    int sign;       // 每个顶点所属的集合(顶点id)
} Assist;

Assist assists[MAXVEX];

// 产生权重边无向矩阵图
void CreateWeightGraphMatrix(MGraph *G);
// 产生权重边无向邻接表图
void CreateWeightGraphList(MGraph G, GraphAdjList *GL);



// 在辅助数组中找出权值最小的边的数组下标，就可以间接找到此边的终点顶点。
int minimum(MGraph MG, CloseEdge close);

// 适合求边稠密的网的最小生成树：http://data.biancheng.net/view/41.html
void Prim(MGraph MG);
void Prim(GraphAdjList LG);

int LocateVex(int numVertexes, int point);
void CreateEdges(const MGraph *MG, EdgeNode edges[]);
int cmp(const void *a, const void *b);

// 适合求边稀疏的网的最小生成树
void Kruskal(MGraph MG);
void Kruskal(GraphAdjList LG);

#endif