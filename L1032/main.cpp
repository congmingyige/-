#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;

/**
这道题没有考虑到字符为空格！
**/

/**
这道题没有说明输入的非空字符串的长度，
字符串的前面一部分有可能是无用的，不必存储

更快的方法是每次读长度为x(x>n,x尽量大)的字符串，若这次字符串的长度为x，则之前读的字符串都丢弃
**/

char str[maxn],s[10],c;

int main()
{
    int n,i,j,len;
    scanf("%d",&n);
    fgets(s,10,stdin);
    for (i=0;i<n;i++)
        str[i]=s[1];
    i=0;
    while (1)
    {
        scanf("%c",&c);
        if (c=='\n')
            break;
        str[i]=c;
        i=(i+1)%n;
    }
    j=(i-1+n)%n;
    while (i!=j)
    {
        printf("%c",str[i]);
        i=(i+1)%n;
    }
    printf("%c",str[i]);
    return 0;
}
/*
15
I love GPLT
*/
