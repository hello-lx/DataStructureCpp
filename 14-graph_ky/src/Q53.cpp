#include <Q53.h>

// 5.3-综合题02：设计一个算法，判断一个无向图是否为一颗树

int FirstNeighbor(GraphQ53 &G, int v)
{
    if(G->adjList[v].firstEdge != nullptr)
    {
        if(!visits[G->adjList[v].firstEdge->adjvex])
            return G->adjList[v].firstEdge->adjvex;
    }
    return -1;
}

int NextNeighbor(GraphQ53 &G, int v, int &w)
{
    ENode* node = G->adjList[v].firstEdge;
    for(int i=0; i<w-1; i++)
    {
        if(node->next != nullptr)
            node = node->next;
        else
            return -1;
    }
    
    return node->adjvex;
}

void DFS(GraphQ53 &G, int v, int &VNum, int &ENum, bool visited[vexNum]) {
    cout << v << endl;
	visited[v] = true;
	VNum++;
	int w = FirstNeighbor(G, v);
    cout << "--> " << w << endl;
    exit(0);
	while (w!=-1)
	{
		ENum++;
		if (!visited[w])
			DFS(G, v, VNum, ENum, visited);
		w = NextNeighbor(G, v, w);
	}
}

bool GraphIsTree(GraphQ53 &G) {
	for (int i = 0; i < G->vertexNum; i++)
	{
		visits[i] = false;
	}
	int VNum = 0;
	int ENum = 0;
	
    int v = 0;
    cout << VNum << ' ' << ENum << endl;
    DFS(G, v, VNum, ENum, visits);
    cout << VNum << ' ' << ENum << endl;

	if (VNum == G->vertexNum&& ENum == 2 * (G->vertexNum - 1))
		return true;
	else
		return false;
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

    // for(int i=0; i<vexNum; i++)
    // {
    //     for(int j=0; j<vexNum; j++)
    //         cout << A[i][j] << '\t';
    //     cout << endl;
    // }

    *graph = (GraphQ53)malloc(sizeof(graphQ53));
    ENode *node;
    for(int i=0; i<vexNum; i++)
    {
        (*graph)->adjList[i].firstEdge = nullptr;
        for(int j=0; j<vexNum; j++)
        {
            if(A[i][j] < INF_MAX)
            {
                node = (ENode*)malloc(sizeof(ENode));
                node->adjvex = j;
                node->weight = A[i][j];
                node->next = (*graph)->adjList[i].firstEdge;
                (*graph)->adjList[i].firstEdge = node;
            }
        }
    }

    for(int i=0; i<vexNum; i++)
    {
        node = (*graph)->adjList[i].firstEdge;
        cout << i << ":  ";
        while(node != nullptr)
        {
            cout << "-->" << node->adjvex;
            node = node->next;
        }
        cout << endl;
    }
}

void hw02(){
    // Graph： 邻接图链表
    GraphQ53 graph;
    CreateALGraph(&graph);
    GraphIsTree(graph);
}




/* ----------------- 5.3-综合题03：邻接表：深度优先搜索非递归 ----------------- */
Graph03* CreateGraph03()
{
    Graph03 *g;
    int **arc = new int*[MAX03];
    for(int i=0; i<MAX03; i++)
    {
        arc[i] = new int[MAX03];
        for(int j=0; j<MAX03; j++)
            arc[i][j] = INF03;
    }    
    
    arc[0][1] = 1;
    arc[0][5] = 1;
    arc[1][2] = 1;
    arc[1][6] = 1;
    arc[1][8] = 1;
    arc[2][3] = 1;
    arc[2][8] = 1;
    arc[3][4] = 1;
    arc[3][6] = 1;
    arc[3][7] = 1;
    arc[3][8] = 1;
    arc[4][5] = 1;
    arc[4][7] = 1;
    arc[5][6] = 1;
    arc[6][7] = 1;

    for(int i=0; i<MAX03; i++)
        for(int j=0; j<MAX03; j++)
            arc[j][i] = arc[i][j];

    for(int i=0; i<MAX03; i++)
    {
        for(int j=0; j<MAX03; j++)
            cout << arc[i][j] << '\t';
        cout << endl;
    }
    
    
    g = (Graph03*)malloc(sizeof(Graph03));
    ENode03 *e;
    int vexNum = 0, edgeNum = 0;
    for(int i=0; i<MAX03; i++)
    {
        g->adjList[i].vex = i;
        vexNum++;
        for(int j=0; j<MAX03; j++)
        {
            if(arc[i][j] != INF03)
            {
                g->adjList[i].in++;
                edgeNum++;
                // e = (ENode03*)malloc(sizeof(ENode03));
                e = new ENode03();
                e->adjvex = j;
                e->weight = arc[i][j];
                e->next = g->adjList[i].firstEdge;
                g->adjList[i].firstEdge = e;
            }
        }
    }
    g->vexNum = vexNum;
    g->edgeNum = edgeNum / 2;  // 无向图
    memset(g->visited, 0, sizeof(g->visited));

    cout<<"邻接图创建完毕： 顶点数——"<<g->vexNum<<", 边数——"<<g->edgeNum<<endl;
    for(int i=0; i<g->vexNum; i++)
        cout << g->visited[i] << ' ';
    cout << endl;
    for(int i=0; i<g->vexNum; i++)
    {
        cout << g->adjList[i].vex << "(入度"<< g->adjList[i].in <<"): ";
        e = g->adjList[i].firstEdge;
        while(e != nullptr)
        {
            cout<<"-->"<<e->adjvex;
            e = e->next;
        }
        cout << endl;
    }

    return g;
}

void DFS03(Graph03 *g, int vexId)
{
    stack<int> s;
    ENode03 *e;
    g->visited[vexId] = 1;
    s.push(vexId);
    
    cout << endl << endl;
    printf("%d", g->adjList[vexId].vex);

    while(!s.empty())
    {
        e = g->adjList[s.top()].firstEdge;
        s.pop();
        while(e)
        {
            // 如果第一节点没有被访问过
            if(g->visited[e->adjvex] == 0)
            {
                g->visited[e->adjvex] = 1;
                printf("->%d", g->adjList[e->adjvex].vex);
                s.push(e->adjvex);
                e = g->adjList[e->adjvex].firstEdge;
            }
            else // 第一节点已经被访问过
            {
                e =  e->next;
            }

        }
    }
}

void hw03()
{
    Graph03* g = CreateGraph03();
    // CreateGraph03(&g);  // bug??
    
    // ENode03* e;
    // cout<<"邻接图创建完毕： 顶点数——"<<g->vexNum<<", 边数——"<<g->edgeNum<<endl;
    // for(int i=0; i<g->vexNum; i++)
    // {
    //     cout << g->adjList[i].vex << "(入度"<< g->adjList[i].in <<"): ";
    //     e = g->adjList[i].firstEdge;
    //     while(e != nullptr)
    //     {
    //         cout<<"-->"<<e->adjvex;
    //         e = e->next;
    //     }
    //     cout << endl;
    // }

    for(int i=0; i<g->vexNum; i++)
    {
        if (g->visited[i] != 1)
        {
            DFS03(g, i);
        }
    }
    cout << endl;
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