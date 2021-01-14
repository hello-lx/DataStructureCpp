#include <stdio.h>
#include <stdlib.h>
#include <string>
// #include "Q01.h"
#include "Q02.h"
#include "Q03.h"
#include "Q04.h"
#include "Q05.h"
#include "Q53.h"
#include "QBase.h"

template<typename  T> 
void swap2(T& t1, T& t2) {
    T tmpT;
    tmpT = t1;
    t1 = t2;
    t2 = tmpT;
}


void testGraph(){
    // Graph* g = new Graph();
    // g->testMatrix();
    // g->testTable();

    // testLinkQueue<int>();

    int x1=10, x2=20;
    cout << x1 << " " << x2 << endl;
    swap2<int>(x1, x2);
    cout << x1 << " " << x2 << endl;
}


// void testQ01()
// {
//     MGraph MG;
//     GraphAdjList GL;
//     CreateMGraph(&MG);
//     CreateALGraph(MG, &GL);
    
//     printf("\n1.图的邻接表的深度优先遍历为：");
//     DFSTraverse(GL);

//     printf("\n2.图的邻接表的广度优先遍历为：");
//     BFSTraverse(GL);


//     printf("\n3.图的矩阵的深度优先遍历为：");
//     DFSTraverse(MG);

//     printf("\n4.图的矩阵的广度优先遍历为：");
//     BFSTraverse(MG);

// }


void testQ02(){
    MGraph MG;
    GraphAdjList LG;
    CreateWeightGraphMatrix(&MG);
    CreateWeightGraphList(MG, &LG);
    
    Prim(MG);
//     Prim(LG);
    
    Kruskal(MG);
    cout << "end" << endl;
//     Kruskal(LG);
}


void testQ03(){
    // Graph_DG *graph = new Graph_DG();
    // graph->createGraph();
    // graph->print();
    // graph->Dijkstra(1);
    // graph->print_path(1);

    Floyd();
}


void testQ04(){
    DAG();
}


void testQ05(){
    
}


void testQ53(){
    hw02();
    hw03();
    hw04();
}

int main(int argc, char const *argv[])
{
    // testGraph();
    
    // testQ01();
    // testQ02();
    // testQ03();
    // testQ04();
    // testQ05();
    testQ53();

    return 0;
}

