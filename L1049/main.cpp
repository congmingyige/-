#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define ll long long

const int maxn=1e2+10;
const int inf=1e9;
const double eps=1e-8;

///遇到这种复杂题：如果状态不好，可以选择先做第二部分的简单题

int g[maxn],tot[maxn],a[maxn][maxn];    ///人数：队伍数*10

int main()
{
    int n,i,j,b=0,rest;

    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&tot[i]),tot[i]*=10;
    rest=n;

    ///不怕超时
    i=0;
    while (rest)
    {
        if (i==n)
            i=1;
        else
            i++;

        if (g[i]!=tot[i])
        {
            ///嵌套的变量名：个人感觉，越不让自己犯迷糊，越简短，越好
            ///题目转化为：不想让同校的队员坐在相邻的位置
            if (b!=0 && a[i][g[i]]==b)
                b++;
            a[i][++g[i]]=++b;   ///如果不熟悉，还是分开来写
            if (g[i]==tot[i])
                rest--;
        }
    }
    for (i=1;i<=n;i++)
    {
        printf("#%d\n",i);
        for (j=1;j<=tot[i];j++)
            printf("%d%c",a[i][j],(j%10==0)?'\n':' ');

    }
    return 0;
}
/*
1
2

2
1
2
*/
