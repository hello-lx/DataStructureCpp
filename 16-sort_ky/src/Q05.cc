#include "Q05.h"

/*
*求数据的最大位数,决定排序次数
*/
int maxbit(int data[], int n) 
{
    int d = 1; //保存最大的位数
    int p = 10;
    for(int i=0; i<n; i++)
    {
        while(data[i] > p)
        {
            p *= 10;
            d++;
        }
    }
    
    return d;
}


void radixsort(int data[], int n) //基数排序
{
    int d = maxbit(data, n);

    int count[10], tmp[n];  // count存放某个基数的数量， tmp存放重新排序的值
    int bit=10;             // 进制
    int i, j, k;
    int radix = 1;
    for(int i=1; i<=d; i++)
    {
        for(int j=0; j<bit; j++)
            count[j] = 0;
        
        // 1. 根据单位数的数值放入桶中
        for(j=0; j<n; j++)
        {
            k = (data[j] / radix) % 10;
            count[k]++;
        }


        // 2. ## 将tmp中的顺序位置依次分配给每个桶 ##  count[10] = n
        for(j=1; j<10; j++)
            count[j] = count[j-1] + count[j];


        // 3. 将所有桶中记录依次收集到tmp中 
        for(j=n-1; j>=0; j--)
        {
            k = (data[j] / radix) % 10;
            tmp[count[k]-1] = data[j];
            count[k]--;
        }

        for(j=0; j<n; j++)
            data[j] = tmp[j];

        radix *= 10;
    }
}
