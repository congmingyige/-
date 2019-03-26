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
1肯定是要放在第一位

节省空间

所有数字前移一位（k作为k-1，0作为n）。
2^20 -> 2^19

如果
使用康拓展开 19!< max long long
而不是20进制，使用两个变量

2^19*19*8 /1024/1024 =76
*/

const int maxn=19;
const int inf=1e9;
const double eps=1e-8;

ll value[maxn],num[1<<maxn][maxn];
bool f[1<<maxn][maxn],vis[maxn],r[maxn+1][maxn+1];
int ii,a[maxn],v=0,n,pr[maxn],g_pr=0;

void dfs(int k,int d)
{
    int i;
    if (k==0)
    {
        int j,l,gl;
        ll num1;
        for (i=1;i<=ii;i++)
            if (f[v][a[i]])
                for (j=0;j<=n-2;j++)
                    if (!vis[j] && r[a[i]][j])
                    {
                        gl=0;
                        for (l=0;l<j;l++)
                            if (vis[l])
                                gl++;
                        num1=num[v][a[i]]+value[18-ii]*(j-gl);
                        if (!f[v|1<<j][j] || num1<num[v|1<<j][j])
                        {
                            f[v|1<<j][j]=1;
                            num[v|1<<j][j]=num1;
                        }
                    }
        return;
    }
    for (i=d;i<=n-2;i++)
    {
        v+=1<<i;
        a[k]=i;
        vis[i]=1;
        dfs(k-1,i+1);
        vis[i]=0;
        v-=1<<i;
    }
}

void work()
{
    int i;
    if (n==2)
    {
        if (r[0][1] && r[1][0])
            printf("1 2");
        else
            printf("No Solution");
        exit(0);
    }
    for (i=0;i<=n-2;i++)
        if (r[n-1][i])
            f[1<<i][i]=1,num[1<<i][i]=value[18]*i;
    for (ii=1;ii<=n-2;ii++)
        dfs(ii,0);
}

int main()
{
    int i,j,k,ind,x,y;
    ll v;
    char c;
    value[0]=1;
    for (i=1;i<=18;i++)
        value[i]=value[i-1]*i;

    scanf("%d",&n);
    for (i=0;i<n;i++)   ///start from 0 (2^0 = 1)
    {
        x=(i==0)?n-1:i-1;
        scanf("%c",&c);
        for (j=0;j<n;j++)
        {
            y=(j==0)?n-1:j-1;
            scanf("%c",&c);
            if (c=='W')
                r[x][y]=1;
            else if (c=='L')
                r[y][x]=1;
        }
    }
    work();

    j=(1<<(n-1))-1;
    num[j][n-1]=9e18;
    ind=n-1;

    for (i=0;i<=n-2;i++)
        if (f[j][i] && r[i][n-1] && num[j][i]<num[j][ind])
            ind=i;

    if (ind==n-1)
    {
        printf("No Solution");
        return 0;
    }

    memset(vis,0,sizeof(vis));
    v=num[j][ind];
    printf("%d",1);
    for (i=18;i>=20-n;i--)
    {
        j=v/value[i];
        k=0;
        while (vis[k])
            k++;
        while (j--)
        {
            k++;
            while (vis[k])
                k++;
        }
        printf(" %d",k+2);
        vis[k]=1;
        v%=value[i];
    }

    return 0;
}
/*
20
-WWWWWWWWWWWWWWWWWWW
W-WWWWWWWWWWWWWWWWWW
WW-WWWWWWWWWWWWWWWWW
WWW-WWWWWWWWWWWWWWWW
WWWW-WWWWWWWWWWWWWWW
WWWWW-WWWWWWWWWWWWWW
WWWWWW-WWWWWWWWWWWWW
WWWWWWW-WWWWWWWWWWWW
WWWWWWWW-WWWWWWWWWWW
WWWWWWWWW-WWWWWWWWWW
WWWWWWWWWW-WWWWWWWWW
WWWWWWWWWWW-WWWWWWWW
WWWWWWWWWWWW-WWWWWWW
WWWWWWWWWWWWW-WWWWWW
WWWWWWWWWWWWWW-WWWWW
WWWWWWWWWWWWWWW-WWWW
WWWWWWWWWWWWWWWW-WWW
WWWWWWWWWWWWWWWWW-WW
WWWWWWWWWWWWWWWWWW-W
WWWWWWWWWWWWWWWWWWW-

3
-WW
W-W
WW-

3
-WD
D-W
WD-
*/
