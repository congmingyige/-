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

const int maxn=1e3+10;
const int inf=1e9;
const double eps=1e-8;

bool vis[maxn];
int per[maxn][maxn],a[maxn][maxn],pr[maxn],g;

void dfs(int d)
{
    int i,j,k;
    g++;
    vis[d]=1;
    ///与该点相连的所有点(所有兴趣，一个兴趣的所有点)
    for (i=1;i<=a[d][0];i++)
    {
        k=a[d][i];
        for (j=1;j<=per[k][0];j++)
            if (!vis[per[k][j]])
                dfs(per[k][j]);
    }
}

int main()
{
    int n,m,i,j,d,sum=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d:",&m);
        for (j=1;j<=m;j++)
        {
            scanf("%d",&d);
            per[d][++per[d][0]]=i;
            a[i][++a[i][0]]=d;
        }
    }
    for (i=1;i<=n;i++)
        if (!vis[i])
        {
            g=0;
            dfs(i);
            pr[++sum]=g;
        }
    printf("%d\n",sum);
    sort(pr+1,pr+sum+1);
    for (i=sum;i>=1;i--)
        printf("%d%c",pr[i],i==1?'\n':' ');
    return 0;
}
