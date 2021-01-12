#ifndef Q03_H
#define Q03_H

#include "QBase.h"
/**
 * 图应用二：最短路径（带权有向图）
 * 算法： Dijkstra 和 Floyd
*/

//#pragma once是一个比较常用的C/C++杂注，
//只要在头文件的最开始加入这条杂注，
//就能够保证头文件只被编译一次。

#include<iostream>
#include<string>
using namespace std;

#define INT_MAX 65535


//检验输入边数和顶点数的值是否有效，可以自己推算为啥：
//顶点数和边数的关系是：((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int Vexnum, int edge);

/*
本程序是使用Dijkstra算法实现求解最短路径的问题
采用的邻接矩阵来存储图
*/
struct Dis
{
    string path;
    int value;
    bool visit;
    Dis(){
        path = "";
        value = 0;
        visit = false;
    }
};

//记录起点到每个顶点的最短路径的信息
// https://blog.csdn.net/qq_35644234/article/details/60870719
class Graph_DG {
private:
    int vexNum;     // 顶点数量
    int edgeNum;    // 边的数量
    int **arc;      // 邻接矩阵
    Dis *dis;       //记录各个顶点最短路径的信息

public:
    Graph_DG();
    ~Graph_DG();

    // 判断我们每次输入的的边的信息是否合法
    // 顶点从1开始编号
    bool check_edge_value(int start, int end, int weight);
    // 创建图
    void createGraph();
    //打印邻接矩阵
    void print();
    //打印最短路径
    void print_path(int);
    
    void Dijkstra(int beginVexId);
};



// https://www.cnblogs.com/wangyuliang/p/9216365.html
void Floyd();

#endif