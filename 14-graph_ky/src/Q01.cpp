#include <iostream>
#include "Q01.h"

/*
        A ----> B ----> F
         \     / 
          \   /    
            C ----> D ----> E
*/
vector<vector<char>> arcs = {{'A', 'B'}, {'A', 'C'}, {'B', 'C'}, {'B', 'F'}, {'C', 'D'}, {'D', 'E'}};
vector<int> weights = {1, 3, 5, 2, 4, 6};
vector<char> vertexs = {'A', 'B', 'C', 'D', 'E', 'F'};

int nVertexs = vertexs.size();

void createGT(vector<GTNode*> &graphTable){
    bool ori = false;
    Graph* graph = new Graph();
    graph->createGraphTable(arcs, weights, ori, graphTable);
    // graph->printTable(graphTable);
}

void createGM(vector<vector<GMNode*>> &graphMatrix){
    bool ori = false;
    Graph* graph = new Graph(vertexs);

    graph->createGraphMatrix(arcs, weights, ori, graphMatrix);
    // graph->printMatrix(graphMatrix);
}


void BFS(vector<GTNode*> &gt, int vId, LinkQueue<GTNode>* queue, bool visited[]){
    cout << vertexs[vId] << endl;
    visited[vId] = true;
    
}

// 对图表进行广度优先搜索
void testBFSGT(){
    vector<GTNode*> gt;
    createGT(gt);

    bool visited[nVertexs];
    for(int i=0; i<nVertexs; i++)
        visited[i] = false;
    
    // auto queue = new LinkQueue<GTNode>();
    // TODO: 创建图结点的队列
    
    // for(int i=0; i<nVertexs; i++)
    //     if (visited[i] == false)
    //         BFS(gt, i, queue, visited);
}


// 对图矩阵进行广度优先搜索
void testBFSGM(){
    vector<vector<GMNode*>> gm(vertexs.size(), vector<GMNode*>(vertexs.size(), 0));
    createGM(gm);

}


// 对图表进行深度优先搜索
void testDFSGT(){
    vector<GTNode*> gt;
    createGT(gt);
    
}

// 对图矩阵进行深度优先搜索
void testDFSGM(){
    vector<vector<GMNode*>> gm(vertexs.size(), vector<GMNode*>(vertexs.size(), 0));
    createGM(gm);
    
}
