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

const int maxn=21;
const int inf=1e9;
const double eps=1e-8;

short n,pre[1<<20][20],pre1[1<<20][20],pr[maxn],g_pr,a[maxn],gl,ii;
int v=0,lef[167961];   ///C(20,9)=167960
bool x[maxn][maxn],vis[maxn],f[1<<20][20],f1[1<<20][20];

void dfs1(int k,int d)
{
    int i;
    if (k==0)
    {
        for (i=1;i<=ii;i++)
            if (f[v][a[i]])
            {
                for (int j=1;j<n;j++)   ///use[][]
                    if (!vis[j] && x[a[i]][j])
                        f[v|1<<j][j]=1,pre[v|1<<j][j]=a[i];
            }
        return;
    }
    for (i=d;i<=n-k;i++)
    {
        v+=(1<<i);
        a[k]=i;
        vis[i]=1;
        dfs1(k-1,i+1);
        vis[i]=0;
        v-=(1<<i);
    }
}

void work1(int z)
{
    int i;
    for (i=0;i<n;i++)
        if (x[0][i])
            f[1<<i][i]=1;

    for (ii=1;ii<z;ii++)
        dfs1(ii,1);
}

void dfs2(int k,int d)
{
    int i,j;
    if (k==0)
    {
        for (i=1;i<=ii;i++)
            if (f1[v][a[i]])
            {
                for (j=1;j<n;j++)   ///use[][]
                    if (!vis[j] && x[j][a[i]])
                        f1[v|1<<j][j]=1,pre1[v|1<<j][j]=a[i];
            }
        return;
    }
    for (i=d;i<=n-k;i++)
    {
        v+=(1<<i);
        a[k]=i;
        vis[i]=1;
        dfs2(k-1,i+1);
        vis[i]=0;
        v-=(1<<i);
    }
}

void work2(int z)
{
    int i;
    for (i=0;i<n;i++)
        if (x[i][0])
            f1[1<<i][i]=1;

    for (ii=1;ii<z;ii++)
        dfs2(ii,1);
}

void dfs3(int k,int d)
{
    int i;
    if (k==0)
    {
        lef[++gl]=v;
        return;
    }
    for (i=d;i<=n-k;i++)
    {
        v+=(1<<i);
        dfs3(k-1,i+1);
        v-=(1<<i);
    }
}

int main()
{
    int i,j,k,l,z1,z2,z11,r;
    char c;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%c",&c);
        for (j=0;j<n;j++)
        {
            scanf("%c",&c);
            if (c=='W')
                x[i][j]=1;
            else if (c=='L')
                x[j][i]=1;
        }
    }

    if (n==2)
    {
        if (x[0][1] && x[1][0])
            printf("1 2");
        else
            printf("No Solution");
        return 0;
    }

    work1((n-1)/2);
    work2(n/2);
    dfs3((n-1)/2,1);

    r=(1<<n)-2;
    for (i=1;i<n;i++)
        for (j=1;j<n;j++)
            if (x[i][j])
                for (k=1;k<=gl;k++)
                    if (f[lef[k]][i] && f1[r-lef[k]][j])
                    {
                        printf("%d",1);
                        z1=lef[k];
                        z2=i;
                        while (z1!=0)
                        {
                            pr[++g_pr]=z2;
                            z11=z1;
                            z1-=(1<<z2);
                            z2=pre[z11][z2];
                        }
                        for (l=g_pr;l>=1;l--)
                            printf(" %d",pr[l]+1);

                        z1=r-lef[k];
                        z2=j;
                        while (z1!=0)
                        {
                            printf(" %d",z2+1);
                            z11=z1;
                            z1-=(1<<z2);
                            z2=pre1[z11][z2];
                        }
                        exit(0);
                    }
    printf("No Solution");
    return 0;
}
/*
20
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
WWWWWWWWWWWWWWWWWWWW
*/
