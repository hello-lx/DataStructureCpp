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


struct AENode            // 有向边节点
{
        int adjvex;      // 索引
        double weight;
        AENode* next;
};


struct ENode            // 无向边节点
{
        double weight;
        ENode* next;
};

template<class T>
struct VNode                    // 邻接表顶点
{
        T vertex;               // 值
        AENode* firstArc;       // 指向第一个中间节点
};

template <class T>
class ALGraph
{
private:
        const int MAX = 20;     // 邻接表数组大小
        VNode<T> adjList[MAX];  // 邻接表数组
        int vexNum;             // 节点数量
        int arcNum;             // 连边数量
        bool visited;           // 标记被访问
        int edgeTo[MAX];
        double distTo[MAX];     // 最短距离
        queue<int> relax_edge;      //需要放松的队列
        bool onQ[MAX];              //标记是否在队列中

// 初始化/增/删(边和顶点)/改/查/可视化
public:
        ALGraph();
        ~ALGraph();
        
        void printGraph();
        void Dijkstra(int source);
        void DijkstraVisit(int &delmin, int source);
        void BellmanFord(int source);  //BellmanFord算法
        void BellmanFord_Relax(int v); //放松操作
};



#endif