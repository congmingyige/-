#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;

struct node
{
    int x,y;
    char z;
}per[maxn];

bool vis[maxn];
///1,2,4,8,16
int num[100],g;

void dfs1(int s,int w)
{
    if (w>5)
        return;
    num[++g]=s,vis[s]=1;
    if (per[s].x!=-1 && per[s].x!=0)    ///
        dfs1(per[s].x,w+1);
    if (per[s].y!=-1 && per[s].y!=0)
        dfs1(per[s].y,w+1);
}

bool dfs2(int s,int w)
{
    if (w>5)
        return 0;
    bool v=vis[s];
    if (per[s].x!=-1 && per[s].x!=0)
        v=v || dfs2(per[s].x,w+1);
    if (per[s].y!=-1 && per[s].y!=0)
        v=v || dfs2(per[s].y,w+1);
    return v;
}

int main()
{
    int n,a,c,d,i,q;
    char b;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d %c%d%d",&a,&b,&c,&d);
        per[a]={c,d,b};
        per[c].z='M',per[d].z='F';  ///!!!
    }
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d%d",&c,&d);
        if (per[c].z==per[d].z)
        {
            printf("Never Mind\n");
            continue;
        }
        g=0;
        dfs1(c,1);
        if (dfs2(d,1))
            printf("No\n");
        else
            printf("Yes\n");
        for (i=1;i<=g;i++)
            vis[num[i]]=0;
    }
    return 0;
}
