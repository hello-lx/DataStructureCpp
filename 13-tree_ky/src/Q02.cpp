#include "base.h"
#include "Q02.h"
using namespace std;

TreeApp2::TreeApp2()
{
    for (int i=0; i<N; i++){
        farther[i] = i;
        height[i] = 0;
    }
}

TreeApp2::~TreeApp2()
{

}

int TreeApp2::findRecursion(int x){
    if (x > N && x < 0)
        return -1;
    
    if (x != farther[x])
    {
        x = findRecursion(farther[x]);
    }

    return x;
}


int TreeApp2::findNonRecursion(int x)
{
    if (x > N && x < 0)
        return -1;
    
    while(x != farther[x])
    {
        x = farther[x];
    }

    return x;
}


void TreeApp2::unionTree(int x, int y)
{
    x = findRecursion(x);
    y = findRecursion(y);
    
    if (x != y)
    {
        if (height[x] < height[y])  // 矮树加到高树上
        {
            farther[x] = y;
        }
        else if (height[x] > height[y])
        {
            farther[y] = x;
        }
        else
        {
            farther[y] = x;
            farther[x]++;
        }
    }
}


void TreeApp2::print()
{   
    cout << "farther:" << endl;
    for(int i=0; i<N; i++)
        cout << farther[i] << " ";
    cout << endl;

    cout << "height:" << endl;
    for(int i=0; i<N; i++)
        cout << height[i] << " ";
    cout << endl;
    
}