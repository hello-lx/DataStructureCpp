#include <Q53.h>

// 5.3-综合题02：设计一个算法，判断一个无向图是否为一颗树

Graph2::Graph2()
{
    vextexNum = vexNum;
    int adjMat = new int[vextexNum][vextexNum];
    for(int i=0; i<vertexNum; i++)
    {
        adjMat[i] = new int[vertexNum];
        for(int j=0; j<vertexNum; j++)
        {
            adjMat[i][j] = INF_MAX;
        }
    }
    adjMat[0][1] = 2;
    adjMat[1][2] = 5;
    adjMat[1][6] = 3;
    adjMat[1][8] = 7;
    adjMat[2][8] = 2;
    adjMat[3][4] = 6;
    adjMat[4][5] = 5;
    adjMat[6][7] = 8;
    adjMat[4][7] = 4;
    adjMat[3][8] = 9;

    for(int i=0; i<vertexNum; i++)
        for(int j=0; j<vextexNum; j++)
        {
            adjMat[j][i] = adjMat[i][j];
        }
        
    A = new ENode*[vexNum];
    for(int i=0; i<vexNum; i++)
    {
        A[i] = new ENode[vexNum];
        for(int j=0; j<vexNum; j++)
            A[i][j] = nullptr;
    }
    // A[0][1] = ;
    // A[1][0] = ;

    // A[1][2] = ;
    // A[2][1] = ;

    // A[1][6] = ;
    // A[6][1] = ;

    // A[1][8] = ;
    // A[8][1] = ;

    // A[2][8] = ;
    // A[8][2] = ;

    // A[3][4] = ;
    // A[4][3] = ;

    // A[5][4] = ;
    // A[4][5] = ;

    // A[6][7] = ;
    // A[7][6] = ;

    // A[7][4] = ;
    // A[4][7] = ;

    // A[8][3] = ;
    // A[3][8] = ;


    ENode *node;
    A[0][1] = new ENode(1, 2, nullptr);
    node = new ENode(1, 2, nullptr);
    A[0][1] = &node;
    // A[0][1] = new ENode(1, 2, nullptr);
    // A[1][0] = new ENode(0, 2, nullptr);

    // A[1][2] = new ENode(2, 5, nullptr);
    // A[2][1] = new ENode(1, 5, nullptr);

    // A[1][6] = new ENode(6, 3, nullptr);
    // A[6][1] = new ENode(1, 3, nullptr);

    // A[1][8] = new ENode(8, 7, nullptr);
    // A[8][1] = new ENode(1, 7, nullptr);

    // A[2][8] = new ENode(8, 2, nullptr);
    // A[8][2] = new ENode(2, 2, nullptr);

    // A[3][4] = new ENode(4, 6, nullptr);
    // A[4][3] = new ENode(3, 6, nullptr);

    // A[5][4] = new ENode(4, 5, nullptr);
    // A[4][5] = new ENode(5, 5, nullptr);

    // A[6][7] = new ENode(7, 8, nullptr);
    // A[7][6] = new ENode(6, 8, nullptr);

    // A[7][4] = new ENode(4, 4, nullptr);;
    // A[4][7] = new ENode(7, 4, nullptr);;

    // A[8][3] = new ENode(3, 9, nullptr);;
    // A[3][8] = new ENode(8, 9, nullptr);;

    // A[0][1].next = A[1][]
}


int FirstNeighbor(Graph &G, int v)
{
    for(int i=0; i<G.vertexNum; i++)
    {
        if(G.A[v][i] != nullptr)
            return i;
    }
    return -1;
}

int NextNeighbor(Graph &G, int v, int &w)
{
    while (w<G->vertexNum)
    {
        if(G->A[v][++w] != nullptr)
            return w;
    }
    return -1;
}

void DFS(Graph2 &G, int &v, int &VNum, int &ENum, int visited[]) {
	visited[v] = true;
	VNum++;
	// int w = NextNeighbor(G, v, visited);
	int w = NextNeighbor(G, v, 0);
	while (w!=-1)
	{
		ENum++;
		if (!visited[w])
			DFS(G, v, VNum, ENum, visited);
		w = NextNeighbor(G, v, w);
	}
    v++;
}

bool GraphIsTree(Graph &G) {
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = false;
	}
	int VNum = 0;
	int ENum = 0;
	
    int v = 0;
    DFS(G, v, VNum, ENum, visited);

	if (VNum == G.vexnum&& ENum == 2 * (G.vexnum - 1))
		return true;
	else
		return false;
}
 
void DFS(GraphQ53 &g, int vexId, int &vn, int &ve, bool *visited)
{
    for(int i=0; i<g.vertexNum; i++)
    {
        if (!visited[i])
        {
            vn++;
            visited[i] = true;
        }
        if ((g.A[vexId][i] < INF_MAX) && (visited[i] == false))
        {
            ve++;
            visited[i] = true;
            DFS(g, i, vn, ve, visited);
        }
    }
}

bool isTree(GraphQ53 g)
{
    for(int i=0; i<g.vertexNum; i++)
    {
        visits[i] = false;
    }

    // 顶点数量和顶点边数
    int vn = 0, ve = 0;
    DFS(g, 0, vn, ve, visits);

    cout << vn << ' ' << ve << endl;
    if(vn==g.vertexNum && ve==2*(g.vertexNum-1))
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

void hw02(){
    // Graph： 邻接链表

    GraphQ53 *g = new GraphQ53();
    isTree(*g);

    Graph2 g;
    
    
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