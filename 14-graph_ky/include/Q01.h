#ifndef Q01_H
#define Q01_H

#include "base.h"
#include "QBase.h"
/**
 * 深度搜索算法(DFS) 和 广度搜索算法(BFS)
*/

void createGT(vector<GTNode*> &graphTable){
/*
        A ----> B ----> F
         \     / 
          \   /    
            C ----> D ----> E
*/
    vector<vector<char>> arcs = {{'A', 'B'}, {'A', 'C'}, {'B', 'C'}, {'B', 'F'}, {'C', 'D'}, {'D', 'E'}};
    vector<int> weights = {1, 3, 5, 2, 4, 6};
    bool ori = true;
    Graph* graph = new Graph();
    // graph->createGraphTable(arcs, weights, ori, graphTable);
}

void createGM(vector<vector<GMNode*>> &graphTable){
/*
        A ----> B ----> F
         \     / 
          \   /    
            C ----> D ----> E
*/
    vector<vector<char>> arcs = {{'A', 'B'}, {'A', 'C'}, {'B', 'C'}, {'B', 'F'}, {'C', 'D'}, {'D', 'E'}};
    vector<int> weights = {1, 3, 5, 2, 4, 6};
    bool ori = true;
    Graph* graph = new Graph();
    // graph->createGraphTable(arcs, weights, ori, graphTable);
}


// 对图表进行深度优先搜索
void DFSGT(){
    // vector<GTNode*> gt;
    // createGT(gt);
    
}

// 对图矩阵进行深度优先搜索
void DFSGM(){

}


// 对图表进行广度优先搜索
void BFSGT(){

}


// 对图矩阵进行广度优先搜索
void BFSGM(){

}

#endif