#ifndef Q01_H
#define Q01_H

#include "QBase.h"
#include <vector>
using namespace std;
/**
 * 深度搜索算法(DFS) 和 广度搜索算法(BFS)
*/

void createGT(vector<GTNode*> &graphTable);

void createGM(vector<vector<GMNode*>> &graphMatrix);

// 对图表进行深度优先搜索
void testDFSGT();

// 对图矩阵进行深度优先搜索
void testDFSGM();

// 对图表进行广度优先搜索
void testBFSGT();

// 对图矩阵进行广度优先搜索
void testBFSGM();

#endif