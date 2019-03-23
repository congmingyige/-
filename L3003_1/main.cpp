#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define ll long long

const int maxn=1e4+10;
const int inf=1e9;
const double eps=1e-8;

///兴趣之间连接边

bool vis[maxn];
int g[maxn],road[maxn][maxn],pr[maxn],sum;

///边少：矩阵 ， 减少代码量

void dfs(int d)
{
    sum+=g[d];
    vis[d]=1;
    for (int i=1;i<=1000;i++)
        if (!vis[i] && road[d][i])
            dfs(i);
}

int main()
{
    int n,m,x,y,i,ge=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d:",&m);
        scanf("%d",&x);
        g[x]++;
        m--;
        while (m--)
        {
            scanf("%d",&y);
            road[y][x]=road[x][y]=1;
        }
    }
    for (i=1;i<=1000;i++)
        if (!vis[i] && g[i]!=0)
    {
        sum=0;
        dfs(i);
        pr[++ge]=sum;
    }
    sort(pr+1,pr+ge+1);
    printf("%d\n",ge);
    for (i=ge;i>=1;i--)
        printf("%d%c",pr[i],i==1?'\n':' ');
    return 0;
}
