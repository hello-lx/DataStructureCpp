#ifndef Q05_H
#define Q05_H

#include <iostream>
#include <iomanip>
using namespace std;

/**
 * (二叉)树应用四：哈夫曼树 —— 给定一组具有确定权值的叶子结点，可以构造出不同的二叉树，将其中带权路径长度最小的二叉树称为哈夫曼树。
 * 设二叉树有n个带权值的叶子结点，从根节点到各个叶子结点的路径长度与相应叶子结点权值的乘积之和叫做二叉树的带权路径长度。
 * https://www.cnblogs.com/smile233/p/8184492.html
 * 
 * 哈夫曼树算法思想：
　　(1) 以权值分别为W1,W2．．．Ｗｎ的ｎ各结点，构成n棵二叉树T1,T2,．．．Tn并组成森林F={T1,T2,．．．Tn},其中每棵二叉树 Ti仅有一个权值为 Wi的根结点；

　　(2) 在F中选取两棵根结点权值最小的树作为左右子树构造一棵新二叉树，并且置新二叉树根结点权值为左右子树上根结点的权值之和（根结点的权值=左右孩子权值之和，叶结点的权值= Wi）；

　　(3) 从F中删除这两棵二叉树，同时将新二叉树加入到F中;

　　(4) 重复(2)、(3)直到F中只含一棵二叉树为止，这棵二叉树就是Huffman树。
*/

struct Element
{
    int weight;    // 权值
    int lChild, rChild, parent;  // 该节点的左、右、双亲节点在数组中的下标
};

void selectMin(Element a[], int n, int &s1, int &s2);

void HuffmanTree(Element huftree[], int w[], int n);

void print(Element hT[], int n);

void test05();

#endif