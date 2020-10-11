#ifndef Q01_H
#define Q01_H

#include "QBase.h"
/**
 * 深度搜索算法(DFS) 和 广度搜索算法(BFS)
*/

void createGT(vector<GTNode*> &graphTable);

void createGM(vector<vector<GMNode*>> &graphTable);

// 对图表进行深度优先搜索
void DFSGT();

// 对图矩阵进行深度优先搜索
void DFSGM();

// 对图表进行广度优先搜索
void BFSGT();

// 对图矩阵进行广度优先搜索
void BFSGM();

#endif