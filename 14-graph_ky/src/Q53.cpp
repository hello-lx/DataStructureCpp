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
    
    for(int i=0; i<g->vexNum; i++)
        cout << g->visited[i] << ' ';
    cout << endl;
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



// 5.3-综合题04：邻接表(有向图)：分别用深度优先和广度优先判断是否有 Vi 到 Vj 的路径 (i != j)
Graph04* CreateGraph04()
{
    Graph04 *g;
    int **arc = new int*[MAX04];
    for(int i=0; i<MAX04; i++)
    {
        arc[i] = new int[MAX04];
        for(int j=0; j<MAX04; j++)
            arc[i][j] = INF04;
    }    
    
    arc[0][1] = 1;
    arc[0][5] = 1;
    arc[1][2] = 1;
    arc[1][6] = 1;
    arc[1][8] = 1;
    arc[2][8] = 1;
    arc[3][4] = 1;
    arc[5][4] = 1;
    arc[6][7] = 1;
    arc[7][4] = 1;
    arc[8][3] = 1;

    // for(int i=0; i<MAX04; i++)
    // {
    //     for(int j=0; j<MAX04; j++)
    //         cout << arc[i][j] << '\t';
    //     cout << endl;
    // }
    
    
    g = (Graph04*)malloc(sizeof(Graph04));
    ENode04 *e;
    int vexNum = 0, edgeNum = 0;
    for(int i=0; i<MAX04; i++)
    {
        g->adjList[i].vex = i;
        vexNum++;
        for(int j=0; j<MAX04; j++)
        {
            if(arc[i][j] != INF04)
            {
                g->adjList[j].in++;
                g->adjList[i].out++;
                edgeNum++;
                e = (ENode04*)malloc(sizeof(ENode04));
                e->adjvex = j;
                e->weight = arc[i][j];
                e->next = g->adjList[i].firstEdge;
                g->adjList[i].firstEdge = e;
            }
        }
    }
    g->vexNum = vexNum;
    g->edgeNum = edgeNum;  // 无向图
    memset(g->visited, 0, sizeof(g->visited));

    // cout<<"邻接图创建完毕： 顶点数——"<<g->vexNum<<", 边数——"<<g->edgeNum<<endl;
    // for(int i=0; i<g->vexNum; i++)
    //     cout << g->visited[i] << ' ';
    // cout << endl;
    // cout << endl;
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

    return g;
}

bool BFS04(Graph04 *g, int &vexIdStart, int &vexIdEnd)
{
    if(vexIdStart == vexIdEnd)
        return true;

    cout << vexIdStart << ' ' << vexIdEnd << endl;
    ENode04* e;
    g->visited[vexIdStart] = true;
    e = g->adjList[vexIdStart].firstEdge;
    while(e)
    {
        vexIdStart = e->adjvex;
        //因为要将每一个结果都要返回，
        //~~如果只是冒然返回isExitedPathDFS的结果，那有一条走不通就都走不通了~~ 
        //如果没有!visited[a]，会陷入死循环
        //所以这里答案巧妙地做成在if语句里走这个结果，而且只需要对的结果，错误的一律不反回
        if(!g->visited[vexIdStart] && BFS04(g, vexIdStart, vexIdEnd))
            return true;
        e = e->next;
    }

    // 所有节点遍历完毕，未找到路径
    return false;
}

bool findPathByBFS(Graph04 *g, int &vexIdStart, int &vexIdEnd)
{
    cout << "BFS" << endl;
    if(BFS04(g, vexIdStart, vexIdEnd))
    {
        cout << "true" << endl;
        return true;
    }

    cout << "false" << endl;
    return false;
}

bool DFS04(Graph04 *g, int &vexIdStart, int &vexIdEnd)
{
    if(vexIdStart == vexIdEnd)
        return true;

    // cout << vexIdStart << ' ' << vexIdEnd << endl;
    g->visited[vexIdStart] = true;
    cout << vexIdStart << ' ' << vexIdEnd << endl;
    ENode04* e = g->adjList[vexIdStart].firstEdge;
    while(e)
    {
        if(g->visited[e->adjvex] == 0 && DFS04(g, e->adjvex, vexIdEnd))
            return true;
        e = e->next;
    }
    return false;
}

bool findPathByDFS(Graph04 *g, int &vexIdStart, int &vexIdEnd)
{
    cout << "DFS" << endl;
    if(DFS04(g, vexIdStart, vexIdEnd))
    {
        cout << "true" << endl;
        return true;
    }

    cout << "false" << endl;
    return false;    
}


void hw04(){
    Graph04 *g = CreateGraph04();
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



    int startVexId1 = 1, endVexId1 = 4;  // true
    findPathByDFS(g, startVexId1, endVexId1);

    int startVexId2 = 1, endVexId2 = 4;  // true
    for(int i=0; i<g->vexNum; i++)
        g->visited[i] = 0;
    findPathByBFS(g, startVexId2, endVexId2);


    int startVexId3 = 2, endVexId3 = 5;  // false
    for(int i=0; i<g->vexNum; i++)
        g->visited[i] = 0;
    findPathByDFS(g, startVexId3, endVexId3);

    int startVexId4 = 2, endVexId4 = 5;  // false
    for(int i=0; i<g->vexNum; i++)
        g->visited[i] = 0;
    findPathByBFS(g, startVexId4, endVexId4);
}