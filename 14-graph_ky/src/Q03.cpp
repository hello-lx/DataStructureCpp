#include <iostream>
#include "Q03.h"
using namespace std;


Graph_DG::Graph_DG()
{
    //初始化顶点数和边数
    vexNum = 9;    // 9
    edgeNum = 15;  // 15
    cout << "---" << endl;
    
    arc = new int*[vexNum];
    for(int i=0; i<vexNum; i++)
    {
        arc[i] = new int[vexNum];
        for(int j=0; j<vexNum; j++)
        {
            arc[i][j] = INT_MAX;
        }
    }

    dis = new Dis[vexNum];
    cout << "---" << endl;
}

Graph_DG::~Graph_DG()
{
    delete[] dis;
    
    for(int i=0; i<vexNum; i++)
    {
        delete arc[i];
    }
}

// 判断我们每次输入的的边的信息是否合法
//顶点从1开始编号
bool Graph_DG::check_edge_value(int start, int end, int weight)
{
    if(start<1 || end<1 || start>vexNum || end>vexNum || weight<0)
        return false;
    return true;
}


void Graph_DG::createGraph()
{
    arc[0][1] = 2;  // A->B
    arc[0][5] = 9;  // A->F
    arc[1][2] = 5;  // B->C
    arc[1][6] = 3;  // B->G
    arc[1][8] = 7;  // B->I
    arc[2][3] = 1;  // C->D
    arc[2][8] = 2;  // C->I
    arc[3][4] = 6;  // D->E
    arc[3][6] = 4;  // D->G
    arc[3][7] = 1;  // D->H
    arc[3][8] = 9;  // D->I
    arc[4][5] = 5;  // E->F
    arc[4][7] = 4;  // E->H
    arc[5][6] = 1;  // F->G
    arc[6][7] = 8;  // G->H
    
}


void Graph_DG::print()
{
    cout << "邻接矩阵：" << endl;
    for(int i=0; i<vexNum; i++)
    {
        for(int j=0; j<vexNum; j++)
        {
            if (arc[i][j] != INT_MAX)
                cout << arc[i][j] << ' ';
            else
                cout << "∞" << ' ';
        }
        cout << endl;
    }    
}

void Graph_DG::Dijkstra(int beginVexId)
{
    // 设置当前路径
    for(int i=0; i<vexNum; i++)
    {
        //设置当前的路径
        dis[i].path = "v"+to_string(beginVexId)+"-->v"+to_string(i+1);
        dis[i].value = arc[beginVexId-1][i];
    }
    
    //设置起点的到起点的路径为0
    dis[beginVexId-1].value = 0;
    dis[beginVexId-1].visit = true;

    int count = 1;
    //计算剩余的顶点的最短路径（剩余this->vexnum-1个顶点）
    while(count != vexNum)
    {
        //temp用于保存当前dis数组中最小的那个下标
        //min记录的当前的最小值
        int temp = 0;
        int min = INT_MAX;
        for(int i=0; i<vexNum; i++)
        {
            if(!dis[i].visit && dis[i].value<min)
            {
                min = dis[i].value;
                temp = i;
            }
        }

        //把temp对应的顶点加入到已经找到的最短路径的集合中
        dis[temp].visit = true;
        count++;
        for(int i=0; i<vexNum; i++)
        {
            if(!dis[i].visit && arc[temp][i]!=INT_MAX && (dis[temp].value+arc[temp][i])<dis[i].value)
            {
                //如果新得到的边可以影响其他为访问的顶点，那就就更新它的最短路径和长度
                dis[i].value = dis[temp].value + arc[temp][i];
                dis[i].path = dis[temp].path + "-->v" + to_string(i+1);
            }
        }
    }
}

void Graph_DG::print_path(int begin)
{
    string str;
    str = "v" + to_string(begin);
    cout << "以" << str << "为起点的图的最短路径为：" << endl;
    for(int i=0; i<vexNum; i++)
    {
        if(dis[i].value != INT_MAX)
            cout << dis[i].path << "=" << dis[i].value << endl;
        else
            cout << dis[i].path << "是无最短路径的。" << endl;
    }
}

void Floyd()
{
    int vexNum = 9;
    int arc[vexNum][vexNum];
    int inf = 999999;

    for(int i=0; i<vexNum; i++)
    {
        for(int j=0; j<vexNum; j++)
        {
            if (i == j)
                arc[i][j] = 0;
            else
                arc[i][j] = inf;
        }
    }

    arc[0][1] = 2;  // A->B
    arc[0][5] = 9;  // A->F
    arc[1][2] = 5;  // B->C
    arc[1][6] = 3;  // B->G
    arc[1][8] = 7;  // B->I
    arc[2][3] = 1;  // C->D
    arc[2][8] = 2;  // C->I
    arc[3][4] = 6;  // D->E
    arc[3][6] = 4;  // D->G
    arc[3][7] = 1;  // D->H
    arc[3][8] = 9;  // D->I
    arc[4][5] = 5;  // E->F
    arc[4][7] = 4;  // E->H
    arc[5][6] = 1;  // F->G
    arc[6][7] = 8;  // G->H


    // Floyd-Warshall算法不能解决带有“负权回路”（或者叫“负权环”）的图，因为带有“负权回路”的图没有最短路。
    for(int k=0; k<vexNum; k++)
        for(int i=0; i<vexNum; i++)
            for(int j=0; j<vexNum; j++)
            {
                if(arc[i][j] > arc[i][k] + arc[k][j])
                    arc[i][j] = arc[i][k] + arc[k][j];
            }

    for(int i=0; i<vexNum; i++)
    {
        for(int j=0; j<vexNum; j++)
            printf("%10d", arc[i][j]);
        printf("\n");
    }
}