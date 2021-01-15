#include <Q53.h>

// 5.3-综合题02：设计一个算法，判断一个无向图是否为一颗树

int FirstNeighbor(graphQ53 &G, int v)
{
    return G.adjList[v].firstEdge->adjvex;
}

int NextNeighbor(graphQ53 &G, int v, int &w)
{
    ENode* node = G.adjList[v].firstEdge;
    for(int i=0; i<w-1; i++)
    {
        if(node->next != nullptr)
            node = node->next;
    }
    if(node->next != nullptr)
        return node->next->adjvex;
    else
        return -1;
}

void DFS(graphQ53 &G, int v, int &VNum, int &ENum, bool visited[vexNum]) {
	visited[v] = true;
	VNum++;
	int w = FirstNeighbor(G, v);
	while (w!=-1)
	{
		ENum++;
		if (!visited[w])
			DFS(G, v, VNum, ENum, visited);
		w = NextNeighbor(G, v, w);
	}
}

bool GraphIsTree(graphQ53 &G) {
	for (int i = 0; i < G.vertexNum; i++)
	{
		visits[i] = false;
	}
	int VNum = 0;
	int ENum = 0;
	
    int v = 0;
    DFS(G, v, VNum, ENum, visits);

	if (VNum == G.vertexNum&& ENum == 2 * (G.vertexNum - 1))
		return true;
	else
		return false;
}

bool isTree(graphQ53 *g)
{
    for(int i=0; i<g->vertexNum; i++)
    {
        visits[i] = false;
    }

    // 顶点数量和顶点边数
    int vn = 0, ve = 0;
    DFS(*g, 0, vn, ve, visits);

    cout << vn << ' ' << ve << endl;
    if(vn==g->vertexNum && ve==2*(g->vertexNum-1))
    {
        cout << "true" << endl;
        return true;
    }
    else
    {
        cout << "false" << endl;
        return false;
    }
}

void CreateALGraph(GraphQ53 *graph)
{
    int **A = new int*[vexNum];
    for(int i=0; i<vexNum; i++)
    {
        A[i] = new int[vexNum];
        for(int j=0; j<vexNum; j++)
            A[i][j] = INF_MAX;
    }

    A[0][1] = 2;
    A[1][2] = 5;
    A[1][6] = 3;
    A[1][8] = 7;
    A[2][8] = 2;
    A[3][4] = 6;
    A[5][4] = 5;
    A[6][7] = 8;
    A[7][4] = 4;
    A[8][3] = 9;

    for(int i=0; i<vexNum; i++)
        for(int j=0; j<vexNum; j++)
            A[j][i] = A[i][j];

    *graph = (GraphQ53)malloc(sizeof(graphQ53));
    ENode *node;
    for(int i=0; i<vexNum; i++)
    {
        (*graph)->adjList[i].firstEdge = nullptr;
        for(int j=0; j<vexNum; j++)
        {
            if(A[i][j] != INF_MAX)
            {
                node = (ENode*)malloc(sizeof(ENode));
                node->adjvex = j;
                node->weight = A[i][j];
                node->next = (*graph)->adjList[i].firstEdge;
                (*graph)->adjList[j].firstEdge = node;
            }
        }
    }
}

void hw02(){
    // Graph： 邻接图链表
    GraphQ53 graph;
    CreateALGraph(&graph);
    isTree(graph);
}


// 5.3-综合题03：邻接表：深度优先搜索非递归

void DFSNoRecursion()
{
    // Stack *stack;
}

void hw03(){

}


// 5.3-综合题04：邻接表(有向图)：分别用深度优先和广度优先判断是否右 Vi 到 Vj 的路径 (i != j)
void findPathByBFS()
{
    
}


void findPathByDFS()
{

}


void hw04(){

}