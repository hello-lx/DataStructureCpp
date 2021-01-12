#include <iostream>
#include "Q02.h"
using namespace std;

void CreateWeightGraphMatrix(MGraph *G)
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
    A   0   2   0   0   0   9   0   0   0
    B   0   0   5   0   0   0   3   0   7
    C   0   0   0   1   0   0   0   0   2
    D   0   0   0   0   6   0   4   1   9
    E   0   0   0   0   0   5   0   4   0
    F   0   0   0   0   0   0   1   0   0
    G   0   0   0   0   0   0   0   8   0
    H   0   0   0   0   0   0   0   0   0
    I   0   0   0   0   0   0   0   0   0
*/

    G->arc[0][1] = 2;  // A->B
    G->arc[0][5] = 9;  // A->F
    G->arc[1][2] = 5;  // B->C
    G->arc[1][6] = 3;  // B->G
    G->arc[1][8] = 7;  // B->I
    G->arc[2][3] = 1;  // C->D
    G->arc[2][8] = 2;  // C->I
    G->arc[3][4] = 6;  // D->E
    G->arc[3][6] = 4;  // D->G
    G->arc[3][7] = 1;  // D->H
    G->arc[3][8] = 9;  // D->I
    G->arc[4][5] = 5;  // E->F
    G->arc[4][7] = 4;  // E->H
    G->arc[5][6] = 1;  // F->G
    G->arc[6][7] = 8;  // G->H

    for(int i=0; i<G->numVertexes; i++)
    {
        for(int j=i; j<G->numVertexes; j++)
        {
            if(G->arc[i][j] == 0)
                G->arc[i][j] = INFINITY;
            G->arc[j][i] = G->arc[i][j];
        }
    }

    cout << "邻接矩阵创建完成:" << endl;
    for(int i=0; i<G->numVertexes; i++)
    {
        for(int j=0; j<G->numVertexes; j++)
        {
            cout << G->arc[i][j] << '\t';
        }
        cout << endl;
    }
}

void CreateWeightGraphList(MGraph G, GraphAdjList *GL)
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
            if(G.arc[i][j] != 0)
            {
                e = (EdgeNode*)malloc(sizeof(EdgeNode));
                e->weight = G.arc[i][j];
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
            cout << "->" << G.vexs[e->adjvex] << e->weight;
            e = e->next;
        }
        cout << endl;
    }
}

// 在辅助数组中找出权值最小的边的数组下标，就可以间接找到此边的终点顶点。
int minimum(MGraph MG, CloseEdge close)
{
    int min = INFINITY;
    int min_i = -1;
    for(int vexId=0; vexId<MG.numVertexes; vexId++)
    {
        //权值为0，说明顶点已经归入最小生成树中；然后每次和min变量进行比较，最后找出最小的。
        if(close[vexId].lowcost > 0 && close[vexId].lowcost < min)
        {
            min = close[vexId].lowcost;
            min_i = vexId;
        }
    }
    return min_i;
}

// 将所有点分成已知和未知，然后不断在已知的点中和未知点中寻找最小的边，然后将未知变成已知
void Prim(MGraph MG)
{
    int startVexId = 1, minVexId;
    
    //首先将与该起始点相关的所有边的信息
    for(int i=0; i<MG.numVertexes; i++)
    {
        if(MG.arc[startVexId][i] != 0)
        {
            gClose[i].adjvex = i;
            gClose[i].lowcost = MG.arc[startVexId][i];
        }
    }

    gClose[startVexId].lowcost = 0;
    
    printf("%c", MG.vexs[startVexId]);
    for(int i=1; i<MG.numVertexes; i++)
    {
        minVexId = minimum(MG, gClose);
        printf("--%d-->%c", gClose[minVexId].lowcost, MG.vexs[gClose[minVexId].adjvex]);

        //归入最小生成树的顶点的辅助数组中的权值设为0
        gClose[minVexId].lowcost = 0;
        
        // 信息辅助数组中存储的信息，由于此时树中新加入了一个顶点，需要判断，
        // 由此顶点出发，到达其它各顶点的权值是否比之前记录的权值还要小，如果还小，则更新
        for(int j=0; j<MG.numVertexes; j++)
        {
            if(MG.arc[minVexId][j] < gClose[j].lowcost)
            {
                gClose[j].adjvex = j;
                gClose[j].lowcost = MG.arc[minVexId][j];
            }
        }
    }
    printf("\n");
}

void Prim(GraphAdjList LG)
{

}

void CreateEdges(const MGraph *MG, Edge edges[])
{
    cout << "bug" << endl;
    for(int i=0; i<MAXSIZE; i++)
    {
        cout << MG->vexs[i] << ' ';
    }
    cout << endl;
    cout << "bug" << endl;

    int edgeId = 0;
    Edge* e;
    int vertexValues[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  // 顶点实际id
    for(int i=0; i<MG->numVertexes; i++)
    {        
        // MG.arc[i][i] = vertexValues[i];  // 对角线存放顶点的值
        for(int j=0; j<MG->numVertexes; j++)
        {
            if((MG->arc[i][j] < INFINITY) && (i!=j))
            {
                e = (Edge*)malloc(sizeof(Edge));
                e->weight = MG->arc[i][j];
                // e->startVex = MG.arc[i][i];
                // e->endVex = MG.arc[j][j];
                e->startVex = vertexValues[i];
                e->endVex = vertexValues[j];
                edges[edgeId] = *e;
                edgeId++;

                cout << i << ' ' << j << ' ' << MG->arc[i][j] << endl;
                for(int k=0; k<MAXSIZE; k++)
                {
                    cout << (*MG).vexs[k] << ' ';
                }
                cout << endl;
            }
        }

        assists[i].value = vertexValues[i];  // vertex value
        assists[i].sign = i;  // vertex id
    }

    cout << "bug" << endl;
    for(int x=0; x<MAXSIZE; x++)
    {
        cout << (*MG).vexs[x] << ' ';
    }
    cout << endl;
    cout << "bug" << endl;
}

int cmp(const void *a, const void *b)
{
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// 返回顶点id
int LocateVex(int numVertexes, int point)
{
    for(int i=0; i<numVertexes; i++)
    {
        if(assists[i].value == point)  // 判断顶点是否相同
        {
            return i;
        }
    }

    return -1;
}

/*  http://data.biancheng.net/view/41.html
将所有边按照权值的大小进行升序排序，然后从小到大一一判断，条件为：如果这个边不会与之前选择的所有边组成回路，
就可以作为最小生成树的一部分；反之，舍去。直到具有 n 个顶点的连通网筛选出来 n-1 条边为止。筛选出来的边和
所有的顶点构成此连通网的最小生成树。 
*/
void Kruskal(MGraph MG)
{    
    printf("\n");
    Edge edges[MAXEDGE], minTree[MAXSIZE];
    int treeEdgeId = 0;
    CreateEdges(&MG, edges);

    cout << "11111" << endl;
    for(int i; i<MAXSIZE; i++)
    {
        cout << MG.vexs[i] << ' ';
    }
    cout << endl;

    qsort(edges, MAXEDGE, sizeof(edges[0]), cmp);    

    // 遍历所有的边
    for(int eId=0; eId<MAXEDGE; eId++)
    {
        // cout << "---" << eId << "---" << endl;
        int startVexId = LocateVex(MG.numVertexes, edges[eId].startVex);
        int endVexId = LocateVex(MG.numVertexes, edges[eId].endVex);
        
        //如果顶点位置存在且顶点的标记不同，说明不在一个集合中，不会产生回路
        if(startVexId!=-1 && endVexId!=-1 && assists[startVexId].sign!=assists[endVexId].sign)
        {
            cout << startVexId << "-->" << endVexId << endl;
            cout << MG.vexs[startVexId] << "==>" << MG.vexs[endVexId] << endl;
            //记录该边，作为最小生成树的组成部分
            minTree[treeEdgeId++] = edges[eId];
            //将新加入生成树的顶点标记全部更改为一样的：3->4:  3->3
            for(int i=0; i<MG.numVertexes; i++)
            {
                if(assists[i].sign == assists[endVexId].sign)
                {
                    assists[i].sign = assists[startVexId].sign;
                }
            }
            //如果选择的边的数量和顶点数相差1，证明最小生成树已经形成，退出循环
            if(treeEdgeId == MG.numVertexes-1)
                break;
        }

        // cout << "===" << treeEdgeId << "===" << MG.numVertexes-1 << endl;
    }

    printf("===========\n");
    for(int i=0; i<MG.numVertexes-1; i++)
    {
        if(i == 0)
        {
            printf("%d->%d", MG.vexs[minTree[i].startVex-1], MG.vexs[minTree[i].endVex-1]);
        }
        else
        {
            printf("->%d", MG.vexs[minTree[i].endVex-1]);
        }
    }
}

void Kruskal(GraphAdjList LG)
{

}

