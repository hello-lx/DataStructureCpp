#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
using namespace std;

/**
 * 定义图的数据结构
 *      类型： 无权无向图 / 无权有向图 / 有权有向图 / 有权有向图
 *      结构：
 *              邻接矩阵：顺序存储         （稠密图， 判断顶点之间是否存在边——效率高， 顶点之间是否存在相邻的边——效率低）
 *              邻接表：顺序存储 + 链式存储 （稀疏图， 判断顶点之间是否存在边——效率低， 顶点之间是否存在相邻的边——效率高）
 *              邻接多重表：
 */


template<class K, class T>   // K 为顶点类型(例如 char)， T 为存储矩阵类型(例如 int)
struct GraphMatrix
{
        K vexs[];            // 顶点名集合        例如: ['A', 'B', 'C', ...]
        K pairs[][1];         // 传入的图节点指向， 例如： [['A', 'C'], ['A', 'B'], ...]
        bool ori;            // 是否为有向图

        int vexNum;
        int edgeNum;
        T matrix[][1];
        
        GraphMatrix(){}
        GraphMatrix(const K &_vexs, const K &_pairs, const bool &_ori);
};


template<class T>
class Graph{
public:
        // 1

};



// template <class T>
// class ALGraph
// {
// private:
//         const int MAX = 20;     // 邻接表数组大小
//         VNode<T> adjList[MAX];  // 邻接表数组
//         int vexNum;             // 节点数量
//         int arcNum;             // 连边数量
//         bool visited;           // 标记被访问
//         int edgeTo[MAX];
//         double distTo[MAX];     // 最短距离
//         queue<int> relax_edge;      //需要放松的队列
//         bool onQ[MAX];              //标记是否在队列中

// // 初始化/增/删(边和顶点)/改/查/可视化
// public:
//         ALGraph();
//         ~ALGraph();
        
//         void printGraph();
//         void Dijkstra(int source);
//         void DijkstraVisit(int &delmin, int source);
//         void BellmanFord(int source);  //BellmanFord算法
//         void BellmanFord_Relax(int v); //放松操作
// };

#endif