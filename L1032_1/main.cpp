#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e7+10;

/**
做错了，也尽量骗多点分，把字符串长度改为尽可能大
内存 1e6 -- 1M (char 1字节)
**/

char str[maxn],c[10];

int main()
{
    int n,i,len;
    scanf("%d",&n);
    fgets(c,10,stdin);
    c[0]=c[1];
    c[1]=0;
    fgets(str,maxn,stdin);
    len=strlen(str);
    if (str[len-1]=='\n')
        len--,str[len]=0;
    if (n<len)
    {
        for (i=len-n;i<len;i++)
            printf("%c",str[i]);
    }
    else
    {
        for (i=0;i<n-len;i++)
            printf("%s",c);
        printf("%s",str);
    }
    return 0;
}
/*
15
I love GPLT
*/
