#ifndef Q53_H
#define Q53_H

#include <iostream>
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
    ENode()
    {
        adjvex = -1;
        weight = -1;
        next = nullptr;
    }
    ENode(int adjvex_, int weight_, ENode *node) 
    {
        adjvex = adjvex_;
        weight = weight_;
        next = node;
    }
} ENode;


typedef struct GraphQ53
{
    int vertexNum;  // 顶点数
    int edgeNum;
    int **A;

    GraphQ53()
    {
        vertexNum = vexNum;
        edgeNum = 11;
        A = new int*[vertexNum];
        for(int i=0; i<vertexNum; i++)
        {
            A[i] = new int[vertexNum];
            for(int j=0; j<vertexNum; j++)
            {
                A[i][j] = INF_MAX;
            }
        }
        A[0][1] = 2;
        A[1][0] = 2;

        A[1][2] = 5;
        A[2][1] = 5;

        A[1][6] = 3;
        A[6][1] = 3;

        A[1][8] = 7;
        A[8][1] = 7;

        A[2][8] = 2;
        A[8][2] = 2;

        A[3][4] = 6;
        A[4][3] = 6;

        A[5][4] = 5;
        A[4][5] = 5;

        A[6][7] = 8;
        A[7][6] = 8;

        A[7][4] = 4;
        A[4][7] = 4;

        A[8][3] = 9;
        A[3][8] = 9;
    }
} GraphQ53;

class Graph2
{
public:
    int vextexNum;
    ENode **A;    
};


int FirstNeighbor(Graph &G, int v);

void DFS(GraphQ53 &g, int vexId, int &vn, int &ve, bool *visited);

bool isTree(GraphQ53 g);

void hw02();

/* 5.3-综合题03：邻接表：深度优先搜索非递归
*/
void hw03();

/* 5.3-综合题04：邻接表(有向图)：分别用深度优先和广度优先判断是否右 Vi 到 Vj 的路径 (i != j)
*/
void hw04();

#endif