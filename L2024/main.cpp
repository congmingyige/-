#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;
const int inf=1e9;
const double eps=1e-8;

int fa[maxn];
bool vis[maxn];

int getf(int d)
{
    if (fa[d]==d)
        return d;
    fa[d]=getf(fa[d]);
    return fa[d];
}

int main()
{
    int n,m,g1=0,g2=0,i,a,x,y;
    for (i=1;i<=10000;i++)
        fa[i]=i;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&m);
        scanf("%d",&a);
        x=getf(a);
        vis[a]=1;
        m--;
        while (m--)
        {
            scanf("%d",&a);
            y=getf(a);
            vis[a]=1;
            fa[y]=x;
        }
    }
    for (i=1;i<=10000;i++)
        if (vis[i])
        {
            g1++;
            if (i==getf(i))
                g2++;
        }
    printf("%d %d\n",g1,g2);
    scanf("%d",&m);
    while (m--)
    {
        scanf("%d%d",&x,&y);
        if (getf(x)==getf(y))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
