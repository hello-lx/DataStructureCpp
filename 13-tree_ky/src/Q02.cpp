#include "base.h"
#include "Q02.h"
using namespace std;

TreeApp2::TreeApp2()
{
    for (int i=0; i<N; i++){
        farther[i] = -1;
        // height[i] = 0;
    }
/**
 *      （1）       （2）       （3）
 *        0          1          2
 *      / | \       / \        / \
 *     6  7  8     4   9      3   5
 */
    farther[6] = 0;
    farther[7] = 0;
    farther[8] = 0;

    farther[4] = 1;
    farther[9] = 1;

    farther[3] = 2;
    farther[5] = 2;
}

TreeApp2::~TreeApp2(){}

// 寻找当前树的根节点
int TreeApp2::findRecursion(int x){
    if (farther[x] != -1)
        x = findNonRecursion(farther[x]);
    return x;
}

// 寻找当前树的根节点
int TreeApp2::findNonRecursion(int x)
{
    while(-1 != farther[x])
    {
        x = farther[x];
    }

    return x;
}


void TreeApp2::unionTree(int x, int y)
{
    x = findRecursion(x);
    y = findRecursion(y);   
    
    farther[y] = x;  // -1 = y
}


void TreeApp2::print()
{   
    cout << "farther:" << endl;
    for(int i=0; i<N; i++)
        cout << farther[i] << " ";
    cout << endl;    
}

/**  将树2的根节点合并至树1中
 *      （1）       （2）       （3）
 *        0          1          2
 *      / | \       / \        / \
 *     6  7  8     4   9      3   5
 */
void TreeApp2::test()
{
    this->print();
    this->unionTree(6, 4);
    this->print();
}