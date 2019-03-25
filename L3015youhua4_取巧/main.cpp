#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

#define ll long long

const int maxn=1e2+10;
const int inf=1e9;
const double eps=1e-8;

/*
判断点1是否还有点可以赢它，具有取巧性质
*/

int f[maxn][maxn],a[maxn],x[maxn][maxn],g[maxn],n,rest;
bool vis[maxn];

void dfs(int k,int d)
{
    int i;
    a[k]=d;
    if (k==n)
    {
        if (f[a[n]][a[1]])
        {
            for (i=1;i<=n;i++)
                printf("%d%c",a[i],i==n?'\n':' ');
            exit(0);
        }
        return;
    }

    vis[d]=1;
    for (i=1;i<=g[d];i++)
        if (!vis[x[d][i]])
        {
            rest-=f[x[d][i]][1];
            if (rest!=0 || k==n-1)
                dfs(k+1,x[d][i]);
            rest+=f[x[d][i]][1];
        }

    vis[d]=0;
}

int main()
{
    int i,j;
    char c;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%c",&c);
        for (j=1;j<=n;j++)
        {
            scanf("%c",&c);
            if (c=='W')
                f[i][j]=1;
            else if (c=='L')
                f[j][i]=1;
        }
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (f[i][j])
                x[i][++g[i]]=j;
    for (i=1;i<=n;i++)
        rest+=f[i][1];
    ///cycle,a[1]=1
    dfs(1,1);
    printf("No Solution");
    return 0;
}
/*

*/
