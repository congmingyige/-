#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
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

bool vis[maxn][maxn];

int fa[maxn];

int getf(int d)
{
    if (fa[d]==d)
        return d;
    fa[d]=getf(fa[d]);
    return fa[d];
}

int main()
{
    int n,m,k,i,x,y,z;
    bool s,t;
    scanf("%d%d%d",&n,&m,&k);
    for (i=1;i<=n;i++)
        fa[i]=i;
    while (m--)
    {
        scanf("%d%d%d",&x,&y,&z);
        if (z==1)
            fa[getf(x)]=getf(y);
        else
            vis[y][x]=vis[x][y]=1;
    }
    while (k--)
    {
        scanf("%d%d",&x,&y);
        s=(getf(x)==getf(y));
        t=vis[x][y];
        if (s && !t)
            printf("No problem\n");
        else if (!s && !t)
            printf("OK\n");
        else if (s && t)
            printf("OK but...\n");
        else
            printf("No way\n");
    }
    return 0;
}
