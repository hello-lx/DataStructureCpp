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


// --------------------------------------- 邻接矩阵 --------------------------------------- 
// typedef struct GraphMatrix
// {
//         vector<char> vertices;            // 顶点名集合        例如: ['A', 'B', 'C', ...]
//         vector<vector<int>> matrix;
//         bool ori;            // 是否为有向图
// } GMatrix;

// --------------------------------------- 邻接表 --------------------------------------- 
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


//  --------------------------------------- 邻接表  --------------------------------------- 
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


#endif