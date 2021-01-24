#include "Q04.h"

void merge_sort(int *data, int start, int end, int *result)
{
    if(0 == end - start)  // 只有一个元素
        return;  
    else if(1 == end - start)  // 有两个元素
    {
        if(data[end] < data[start])
        {
            int temp = data[end];
            data[end] = data[start];
            data[start] = temp;
        }
    }
    else
    {
        //继续划分子区间，分别对左右子区间进行排序
        int left=(end-start+1)/2, right=(end-start+1)/2+1;
        merge_sort(data, start, start+left, result);
        merge_sort(data, start+right, end, result);

        //开始归并已经排好序的start到end之间的数据
        merge(data, start, end, result);

        //把排序后的区间数据复制到原始数据中去       // end = length-1   
        for(int i=start; i<=end; i++)
            data[i] = result[i];
    }
}

void merge(int *data, int start, int end, int *result)
{
    int left_length = (end - start + 1) / 2 + 1;
    int left_index = start;
    int right_index = start + left_length;
    int result_index = start;
    
    while(left_index < start + left_length && right_index < end+1)
    {
        if(data[left_index] < data[right_index])
            result[result_index++] = data[left_index++];
        else
            result[result_index++] = data[right_index++];
    }

    while(left_index < start + left_length)
        result[result_index++] = data[left_index++];

    while(right_index < end)
        result[result_index++] = data[right_index++];
}