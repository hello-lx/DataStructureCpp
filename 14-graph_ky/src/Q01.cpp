// #include <iostream>
// #include "Q01.h"
// #include "base.h"

// /*
//         A ----> B ----> F
//          \     / 
//           \   /    
//             C ----> D ----> E
// */
// vector<vector<char>> arcs = {{'A', 'B'}, {'A', 'C'}, {'B', 'C'}, {'B', 'F'}, {'C', 'D'}, {'D', 'E'}};
// vector<int> weights = {1, 3, 5, 2, 4, 6};
// vector<char> vertexs = {'A', 'B', 'C', 'D', 'E', 'F'};
// Graph* graph = new Graph(vertexs);

// int nVertexs = vertexs.size();

// void createGT(vector<GTNode*> &graphTable){
//     bool ori = false;
//     graph->createGraphTable(arcs, weights, ori, graphTable);
//     // graph->printTable(graphTable);

// }

// void createGM(vector<vector<GMNode*>> &graphMatrix){
//     bool ori = false;
//     graph->createGraphMatrix(arcs, weights, ori, graphMatrix);
//     // graph->printMatrix(graphMatrix);
// }


// /* --------- 1. 对图表进行广度优先搜索 --------- */
// void GTBFS(vector<GTNode*> &gt, int vId, LinkQueue<GTNode>* queue, bool visited[]){
//     // cout << vertexs[vId] << endl;
//     visited[vId] = true;

//     while(gt[vId]->next)
//     {
//         int nodeId = graph->ch2int[gt[vId]->next->name];
        
//         if(visited[nodeId] == false)
//         {
//             queue.push_back(gt[vId]->next);
//             visited[nodeId] = true;
//         }
//     }
// }

// void testBFSGT(){
//     vector<GTNode*> gt;
//     createGT(gt);
    
//     bool visited[nVertexs];
//     for(int i=0; i<nVertexs; i++)
//         visited[i] = false;
    
//     auto queue = new LinkQueue<GTNode>();
//     // TODO: 创建图结点的队列
    
//     for(int i=0; i<nVertexs; i++)
//         if (visited[i] == false)
//             GTBFS(gt, i, queue, visited);
// }



// /* --------- 2. 对图表进行深度优先搜索 --------- */
// void GTDFS(){

// }

// void testDFSGT(){
//     vector<GTNode*> gt;
//     createGT(gt);
    
// }



// /* --------- 3. 对图矩阵进行广度优先搜索 --------- */
// void GMBFS(){

// }

// void testBFSGM(){
//     vector<vector<GMNode*>> gm(vertexs.size(), vector<GMNode*>(vertexs.size(), 0));
//     createGM(gm);

// }



// /* --------- 4. 对图矩阵进行深度优先搜索 --------- */
// void GMDFS(){

// }

// void testDFSGM(){
//     vector<vector<GMNode*>> gm(vertexs.size(), vector<GMNode*>(vertexs.size(), 0));
//     createGM(gm);
    
// }
