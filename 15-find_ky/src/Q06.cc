#include "Q06.h"

/* ------------ 暴力匹配 ------------ */
int hardMatch(string haystack, string needle) {
    // 异常处理
    if(haystack.length() == 0)
    {
        if(needle.length() == 0)
            return 0;
        else
            return -1;
    }
    else if(haystack.length() < needle.length())
    {
        return -1;
    }

    int p1, p2; // p1是目标串的当前匹配位置, p2是模式串的当前匹配位置
    int i = needle.length();  // 将i置为目标串中的匹配串最后一个字符对应的位置
    for(p1=0; i<=haystack.length(); i++)
    {
        int p1_old = p1;  //记录这一轮匹配的初始位置
        p2 = 0; //每一次都从模式串的第一位开始
        
        while(p1<haystack.length() && p2<needle.length() && haystack[p1]==needle[p2])
        {
            p1++;
            p2++;
        }
        
        if(p2 >= needle.length())
            return p1_old;

         p1 = p1_old + 1;
    }

    return -1;
}
/* ------------ 暴力匹配 ------------ */



/* ------------ KMP ------------ */
void cal_next(char *str, int *next, int len)  
{       // 计算与第一个字母与其他字母时候匹配，若匹配为0，不匹配为-1
    next[0] = -1；
    int k = -1;
    
    for(int q=1; q<=len-1; q++)
    {
        while( k > -1 && str[k+1] != str[q])
        {
            k = next[k];
        }
        if(str[k+1] == str[q])
        {
            k = k + 1;
        }
        next[q] = k; // 这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
    }
}


int KMP(char *str, int slen, char *ptr, int plen)
{
    int *next = new int[plen];
    cal_next(ptr, next, plen);  //计算next数组
    int k = -1;
    for(int i=0; i<slen; i++)
    {
        d
    }
}
/* ------------ KMP ------------ */