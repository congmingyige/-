#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;
#define ll long long

///做这题的技巧是先题目仔细看一篇，理解题意，避免之后走弯路

struct node
{
    int a,b;
    double c,d;
    bool operator<(const node y)
    {
        if (d==y.d)
            return a<y.a;
        return d>y.d;
    }
}f[maxn],ff[maxn];

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
    int n,a,b,c,d,e,g=0,i;
    scanf("%d",&n);
    for (i=0;i<10000;i++)
        fa[i]=i,f[i].a=i;
    while (n--)
    {
        scanf("%d",&a);
        vis[a]=1;

        ///same operation
        ///father,mother doesn't mean root of the united tree
        scanf("%d",&b);
        if (b!=-1)
        {
            vis[b]=1;
            fa[getf(b)]=getf(a);
        }

        scanf("%d",&b);
        if (b!=-1)
        {
            vis[b]=1;
            fa[getf(b)]=getf(a);
        }

        scanf("%d",&c);
        while (c--)
        {
            scanf("%d",&b);
            if (b!=-1)
            {
                vis[b]=1;
                fa[getf(b)]=getf(a);
            }
        }

        scanf("%d%d",&d,&e);
        f[a].c+=d,f[a].d+=e;    ///give value to the root point: later, and the non-root point has not need to modify its value
    }
    g=0;
    for (i=0;i<10000;i++)
    {
        f[i].b++;
        a=getf(i);
        if (a!=i)
        {
            f[a].a=min(f[a].a,i);
            f[a].b++;
            f[a].c+=f[i].c;
            f[a].d+=f[i].d;
            vis[i]=0;
        }
    }
    for (i=0;i<10000;i++)
        if (vis[i])
        {
            ff[++g]=f[i];
            ff[g].c/=ff[g].b;
            ff[g].d/=ff[g].b;
        }
    sort(ff+1,ff+g+1);

    printf("%d\n",g);
    for (i=1;i<=g;i++)
        printf("%04d %d %.3f %.3f\n",ff[i].a,ff[i].b,ff[i].c,ff[i].d);
    return 0;
}
