#include "Q02.h"

int search(int key, int a[])
{
    int i, j;
    i = 0;
    
    // 确定在哪个块中
    while(i < 3 && key > index[i].key)  // 大于最大值
    {
        i++;
    }

    if(i >= 3)      // 超过最大值
        return -1;

    j = index[i].start;
    while(j<=index[i].end && a[j]!=key)
    {
        j++;
        cout << a[j] << endl;
    }
    
    if(j > index[i].end)
        j = -1;
    
    return j;
}


void blockSearch()
{
    int i, j=-1, k, key;
    int a[]={42,63,82,89,111,  146,219,254,325,336,  348,795,867,951,998};

    cout<<"已知有一数组"<<endl;
    for(i=0; i<15; i++)
        cout << a[i] << " ";
    cout<<endl;
    
    for(i=0; i<3; i++)
    {
        //确定每个块的起始值
        index[i].start = j+1;
        j = j + 1;
        index[i].end = j + 4;
        
        j = j + 4;
        index[i].key = a[j];  //确定每个块范围中的元素最大值
    }

    key = 325;
    k = search(key, a);
    if(k >= 0)
        cout << "查找成功：" << k+1 << endl;
    else
        cout << "查找失败！" << endl;
}
