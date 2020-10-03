#include "Q05.h"

void selectMin(Element a[], int n, int &s1, int &s2)
{   
    // 1. 初始化s1,s1的双亲为-1
    for(int i=0; i<n; i++)
    {
        if(a[i].parent == -1)
        {
            s1 = i;
            break;
        }
    }

    // 2. s1为权值最小的下标，且没有双亲节点
    for(int i=0; i<n; i++)
    {
        if(a[i].parent == -1 && a[s1].weight > a[i].weight)
            s1 = i;
    }
    

    // 3. 初始化s2,s2的双亲为-1
    for(int j=0; j<n; j++)
    {
        if(a[j].parent == -1 && j != s1)
        {
            s2 = j;
            break;
        }
    }

    // 4. s2为另一个权值最小的结点，且没有双亲节点, 且 s2 ！= s1
    for(int j=0; j<n; j++)
    {
        if(a[j].parent == -1 && a[s2].weight > a[j].weight && j != s1)
            s2 = j;
    }
}

/*
哈夫曼算法： n个叶子结点的权值保存在数组w中
    1、数组haftree初始化，所有数组元素的双亲、左右孩子都置为-1；
    2、数组haftree的前n个元素的权值置给定权值；
    3、进行n-1次合并
        3.1 在二叉树集合中选取两个权值最小的根节点，其下标分别为i1，i2；
        3.2 将二叉树i1、i2合并为一棵新的二叉树k
*/
void HuffmanTree(Element huftree[], int w[], int n)
{
    // 初始化，所有结点均没有双亲和孩子
    for(int i=0; i<2*n-1; i++)
    {
        huftree[i].parent = -1;
        huftree[i].lChild = -1;
        huftree[i].rChild = -1;
    }

    // 构造只有根节点的n棵二叉树
    for(int i=0; i<n; i++)
        huftree[i].weight = w[i];

    // n-1次合并
    for(int k=n; k<2*n-1; k++)
    {
        int i1, i2;
        selectMin(huftree, k, i1, i2);
        huftree[i1].parent = k;
        huftree[i2].parent = k;
        huftree[k].lChild = i1;
        huftree[k].rChild = i2;
        huftree[k].weight = huftree[i1].weight + huftree[i2].weight;
    }
}

void print(Element hT[], int n)
{
    cout << "index weight parent lChild rChild" << endl;
    cout << left;  // 左对齐输出
    for(int i=0; i<n; i++)
    {
        cout << setw(5) << i << " ";
        cout << setw(6) << hT[i].weight << " ";
        cout << setw(6) << hT[i].parent << " ";
        cout << setw(6) << hT[i].lChild << " ";
        cout << setw(6) << hT[i].rChild << endl;
    }
}

void test05()
{
    int x[] = {5, 29, 7, 8, 14, 23, 3, 11};
    int xSize = 8;
    int treeSize = 2 * xSize - 1;

    Element* hufTree = new Element[treeSize];
    HuffmanTree(hufTree, x, xSize);
    print(hufTree, treeSize);

    return;
}


/**  {5, 29, 7, 8, 14, 23, 3, 11}
 *                             14-100
 *                         /             \
 *                   12-42                 13-58
 *                 /       \             /       \ 
 *             10-19       5-23      1-29       11-29
 *            /     \                          /     \
 *          7-11    8-8                     4-14     9-15
 *                 /   \                            /    \
 *               6-3   0-5                       2-7      3-8
 */
