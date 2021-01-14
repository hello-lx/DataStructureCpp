#include "Q04.h"
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

const int maxa = 10;
vector<int> vec[maxa];  // 邻接矩阵，一维：顶点数量， 二维：相邻的节点id
queue<int> q;
int rudu[maxa];
int t, n, m, x, y, now;

// n 顶点数量

bool tuopu()
{
    int counter = 0;
    while(!q.empty()) q.pop();

    for(int i=0; i<n; i++)
    {
        if(rudu[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        now = q.front();
        counter++;
        q.pop();
        for(int i=0; i<vec[now].size(); i++)
        {
            if(--rudu[vec[now][i]] == 0)
                q.push(vec[now][i]);
        }
    }

    if(counter == n)
        return true;
    else
        return false;
}

void DAG()
{
    cout << "组数t: ";
    cin>>t;
    while(t--)
    {
        cout << "n(课程) m(顺序关系): ";
        cin>>n>>m;
        memset(rudu,0,sizeof(rudu));
        for(int i=1;i<=n;i++) vec[i].clear();
        while(m--)
        {
            cout << "m: "<<m+1<<"   顶点x->顶点y: ";
            cin>>x>>y;
            vec[x].push_back(y);
            rudu[y]++;//入度+1
        }
        if(tuopu()) cout<<"Correct"<<endl;
        else cout<<"Wrong"<<endl;
    }

    return;
}