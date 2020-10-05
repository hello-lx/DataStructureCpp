#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <vector>
#include <malloc.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

#define MAX 100
#define isLetter(ch)  (((ch)>='a') && ((ch)<='z') || ((ch)>='A') && ((ch)<='Z'))
#define LENGTH(arr)  (sizeof(arr)/sizeof(arr[0]))
#define chars "ABCDEFGHIJKLMNOPQRTSUVWXYZ"


/**
 * 定义图的数据结构
 *      类型： 无权无向图 / 无权有向图 / 有权有向图 / 有权有向图
 *      结构：
 *              邻接矩阵：顺序存储         （稠密图， 判断顶点之间是否存在边——效率高， 顶点之间是否存在相邻的边——效率低）
 *              邻接表：顺序存储 + 链式存储 （稀疏图， 判断顶点之间是否存在边——效率低， 顶点之间是否存在相邻的边——效率高）
 *              邻接多重表：
 */


// 邻接矩阵
typedef struct GraphMatrix
{
        vector<char> vertices;            // 顶点名集合        例如: ['A', 'B', 'C', ...]
        vector<vector<int>> matrix;
        bool ori;            // 是否为有向图
} GMatrix;

// 邻接表
typedef struct GraphTableNode
{
        // int vId;        // 邻接点在数组中的位置下标
        char name;      // 邻接点的数值
        int weight;
        struct GraphTableNode *next;

        GraphTableNode(){
                name = ' ';
                weight=0;
                next=nullptr;
        }
        GraphTableNode(char n, int w, GraphTableNode* _next): name(n), weight(w), next(_next){}
} GTNode;


// template<class T>
class Graph{
public:
        Graph();
        ~Graph();
        
        void createGraphMatrx(const vector<vector<char>> &letters, const vector<int> &weights, const bool &ori, vector<vector<int>> &matrix);
        void printMatrix(const vector<vector<int>> &matrix);
        void testMatrix();

        void createGraphTable(const vector<vector<char>> &letters, const vector<int> &weights, const bool &ori, vector<GTNode*> &table);
        void printTable(const vector<GTNode*> &table);
        void testTable();

private:
        map<char, int>* ch2int;
        map<int, char>* int2ch;
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