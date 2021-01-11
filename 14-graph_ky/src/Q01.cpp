#include "Q01.h"
#include <iostream>
using namespace std;

Status InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;

    return OK;
}

Status QueueEmpty(Queue Q)
{
    if(Q.front == Q.rear)
        return TRUE;

    return FALSE;
}

Status EnQueue(Queue *Q, int e)
{
    if((Q->rear+1) % MAXSIZE == Q->front)
        return ERROR;

    Q->data[Q->rear] = e;               
    Q->rear = (Q->rear + 1) % MAXSIZE;   // 将 rear 指针向后移一位， 若到最后则转到数组头部

    return OK;
}

Status DeQueue(Queue *Q, int *e)  /* 若队列不空,则删除Q中队头元素,用e返回其值 */
{
    if(Q->front == Q->rear)         /* 队列空的判断 */
        return ERROR;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;    /* front指针向后移一位置, 若到最后则转到数组头部 */

    return OK;
}

void CreateMGraph(MGraph *G)
{
    G->numEdges = 15;
    G->numVertexes = MAXSIZE;
    
    /* 读入顶点信息，建立顶点表 */    
    G->vexs[0] = 'A';
    G->vexs[1] = 'B';
    G->vexs[2] = 'C';
    G->vexs[3] = 'D';
    G->vexs[4] = 'E';
    G->vexs[5] = 'F';
    G->vexs[6] = 'G';
    G->vexs[7] = 'H';
    G->vexs[8] = 'I';

    for(int i=0; i<G->numVertexes; i++)
    {
        for(int j=0; j<G->numVertexes; j++)
        {
            G->arc[i][j] = 0;
        }
    }
    
/*
        A   B   C   D   E   F   G   H   I
    A   0   1   0   0   0   1   0   0   0
    B   0   0   1   0   0   0   1   0   1
    C   0   0   0   1   0   0   0   0   1
    D   0   0   0   0   1   0   1   1   1
    E   0   0   0   0   0   1   0   1   0
    F   0   0   0   0   0   0   1   0   0
    G   0   0   0   0   0   0   0   1   0
    H   0   0   0   0   0   0   0   0   0
    I   0   0   0   0   0   0   0   0   0
*/

    G->arc[0][1] = 1;
    G->arc[0][5] = 1;
    G->arc[1][2] = 1;
    G->arc[1][6] = 1;
    G->arc[1][8] = 1;
    G->arc[2][3] = 1;
    G->arc[2][8] = 1;
    G->arc[3][4] = 1;
    G->arc[3][6] = 1;
    G->arc[3][7] = 1;
    G->arc[3][8] = 1;
    G->arc[4][5] = 1;
    G->arc[4][7] = 1;
    G->arc[5][6] = 1;
    G->arc[6][7] = 1;

    for(int i=0; i<G->numVertexes; i++)
    {
        for(int j=i; j<G->numVertexes; j++)
        {
            G->arc[j][i] = G->arc[i][j];
        }
    }

    cout << "邻接矩阵创建完成:" << endl;
    for(int i=0; i<G->numVertexes; i++)
    {
        for(int j=0; j<G->numVertexes; j++)
        {
            cout << G->arc[i][j] << ' ';
        }
        cout << endl;
    }
}

/* 利用邻接矩阵构建邻接表 */
void CreateALGraph(MGraph G, GraphAdjList *GL)
{
    EdgeNode* e;
    *GL = (GraphAdjList)malloc(sizeof(graphAdjList));
    (*GL)->numVertexes = G.numVertexes;
    (*GL)->numEdges = G.numEdges;

    for(int i=0; i<G.numVertexes; i++)  /* 读入顶点信息,建立顶点表 */
    {
        (*GL)->adjList[i].in = 0;
        (*GL)->adjList[i].data = G.vexs[i];
        (*GL)->adjList[i].firstEdge = nullptr;  // 将边表置空
    }

    for(int i=0; i<G.numVertexes; i++)
    {
        for(int j=0; j<G.numVertexes; j++)
        {
            if(G.arc[i][j] == 1)
            {
                e = (EdgeNode*)malloc(sizeof(EdgeNode));
                e->adjvex = j;                              /* 邻接序号为j */
                e->next = (*GL)->adjList[i].firstEdge;      /* 将当前顶点上的指向的结点指针赋值给e */
                (*GL)->adjList[i].firstEdge = e;            /* 将当前顶点的指针指向e */ 
                (*GL)->adjList[j].in++;
            }
        }
    }

    for(int i=0; i<MAXSIZE; i++)
    {
        (*GL)->vexs[i] = G.vexs[i];
    }

    cout << "邻接表创建完成：" << endl;
    for(int i=0; i<(*GL)->numVertexes; i++)
    {
        cout << (*GL)->vexs[i];
        e = (*GL)->adjList[i].firstEdge;
        while(e)
        {
            cout << "->" << G.vexs[e->adjvex];
            e = e->next;
        }
        cout << endl;
    }
}

/* 邻接表的深度优先递归算法 */
void DFS(GraphAdjList GL, int adjvex)
{

    EdgeNode* p;
    visited[adjvex] = TRUE;
    printf("%c ", GL->adjList[adjvex].data);  /* 打印顶点,也可以其它操作 */
    p = GL->adjList[adjvex].firstEdge;
    
    while(p)
    {
        if(!visited[p->adjvex])
            DFS(GL, p->adjvex);     /* 对为访问的邻接顶点递归调用 */
        p = p->next;                // 链表中当前节点的下一个节点
    }
}

/* 邻接表的深度遍历操作 */
void DFSTraverse(GraphAdjList GL)
{
    EdgeNode *p;
    Queue q;
    for(int i=0; i<GL->numVertexes; i++)
        visited[i] = FALSE;

    for(int i=0; i<GL->numVertexes; i++)
    {
        if(!visited[i])
            DFS(GL, i);
    }
}


/* 邻接表的广度遍历算法 */
void BFSTraverse(GraphAdjList GL)
{
    /*
        1. 对顶点遍历
        2. 将遍历的节点放入队列中,队列存放当前顶点的周围节点
        3. 遍历队列
        4. 遍历队列中每个节点的链表(即周围的节点)
    */
    EdgeNode *p;
    Queue Q;

    for(int i=0; i<GL->numVertexes; i++)
        visited[i] = FALSE;

    for(int i=0; i<GL->numVertexes; i++)
    {
        if(!visited[i])
        {
            visited[i] = TRUE;
            printf("%c ", GL->adjList[i].data);
            EnQueue(&Q, i);
            while(!QueueEmpty(Q))
            {
                DeQueue(&Q, &i);
                p = GL->adjList[i].firstEdge;
                while(p)
                {
                    if(!visited[p->adjvex])
                    {
                        visited[p->adjvex] = TRUE;
                        printf("%c ", GL->adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
    cout << endl;
}



/* ----------------- 二：矩阵的深度搜索和广度搜索 ----------------- */

/* 图矩阵的深度优先递归算法 */
void DFS(MGraph GM, int vertexId)
{
    for(int adjVex=0; adjVex<GM.numVertexes; adjVex++)
    {
        if(visited2[adjVex] == FALSE)
        {
            printf("%c. ", GM.vexs[adjVex]);
            visited2[adjVex] = TRUE;
        }

        if((GM.arc[vertexId][adjVex] != 0) && (visited2[adjVex] == FALSE))
        {
            printf("%c ", GM.vexs[adjVex]);
            visited2[adjVex] = TRUE;
            DFS(GM, adjVex);    
        }
    }
}

/* 图矩阵的深度遍历操作 */
void DFSTraverse(MGraph GM)
{
    for(int i=0; i<GM.numVertexes; i++)
        visited2[i] = FALSE;

    DFS(GM, 0);
}

/* 图矩阵的广度遍历操作 */
void BFSTraverse(MGraph GM)
{
    for(int i=0; i<GM.numVertexes; i++)
        visited2[i] = FALSE;

    Queue Q;
    InitQueue(&Q);
    int vexId = 0;  // start vertex

    EnQueue(&Q, vexId);
    while(!QueueEmpty(Q))
    {
        DeQueue(&Q, &vexId);
        if(!visited2[vexId])
        {
            printf("%c. ", GM.vexs[vexId]);
            visited2[vexId] = TRUE;
        }

        for(int adjVex=0; adjVex<GM.numVertexes; adjVex++)
        {
            if(GM.arc[vexId][adjVex] != 0 && visited2[adjVex] == FALSE)
                EnQueue(&Q, adjVex);
        }
    }

    cout << endl;
}
