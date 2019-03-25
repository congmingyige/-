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

/*
剪枝：
后续的所有点 可以用于赢，可以用于输的个数
不符合要求则退出
*/

const int maxn=1e2+10;
const int inf=1e9;
const double eps=1e-8;

int f[maxn][maxn],a[maxn],n;
int win[maxn][maxn],gw[maxn],lose[maxn][maxn],gl[maxn],canw[maxn],canl[maxn];
bool vis[maxn];

void dfs(int k,int d)
{
    int i,j,dd;
    bool v;
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
    if (k!=1)
    {
        for (j=1;j<=gl[d];j++)
            canw[lose[d][j]]--;
    }
    for (j=1;j<=gw[d];j++)
        canl[win[d][j]]--;

    dd=0;
    for (j=1;j<=gw[d];j++)
        if (win[d][j]==1 && canl[win[d][j]]==0)
        {
            dd=2;
            break;
        }
        else if (!vis[win[d][j]] && canl[win[d][j]]==0)
            dd++,i=win[d][j];
    if (dd==0)
    {
        for (i=1;i<=gw[d];i++)
            if (!vis[win[d][i]])
            {
                dd=win[d][i];
                v=1;
                for (j=1;j<=gl[dd];j++)
                    if (!vis[lose[dd][j]] && canw[lose[dd][j]]==1)
                    {
                        v=0;
                        break;
                    }
                if (v)
                    dfs(k+1,dd);
            }
    }
    else if (dd==1)
        dfs(k+1,i);

    if (k!=1)
    {
        for (j=1;j<=gl[d];j++)
            canw[lose[d][j]]++;
    }
    for (j=1;j<=gw[d];j++)
        canl[win[d][j]]++;
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
                win[i][++gw[i]]=j,lose[j][++gl[j]]=i;
    for (i=1;i<=n;i++)
        canw[i]=gw[i],canl[i]=gl[i];
    ///cycle,a[1]=1
    dfs(1,1);
    printf("No Solution");
    return 0;
}
/*

*/
