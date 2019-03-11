#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/*
windows
比对输出
fc 1.txt 3.txt

运行
x.exe
x.exe <y.txt
x.exe <y.txt >z.txt

运行时间找不到，linux用time
*/

const int maxn=1e5+10;
#define ll long long

struct node
{
    int d;
    node *to;
}*e[maxn];

bool cut[maxn],vis[maxn];

void dfs(int d)
{
    node *p=e[d];
    vis[d]=1;
    while (p)
    {
        if (!vis[p->d] && !cut[p->d])
            dfs(p->d);
        p=p->to;
    }
}

int main()
{
    bool sin;
    node *p;
    int n,m,q,i,a,b,g,gg,d;
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        p=new node();
        p->d=b;
        p->to=e[a];
        e[a]=p;

        p=new node();
        p->d=a;
        p->to=e[b];
        e[b]=p;
    }
        ///额，有时拷贝后，不必有那么多闲情逸致调整格式，萌萌哒
        memset(vis,0,sizeof(vis));
        g=0;
        for (i=0;i<n;i++)
            if (!cut[i] && !vis[i])
                dfs(i),g++;
        gg=g;

    scanf("%d",&q);
    while (q--)
    {
        scanf("%d",&d);
        cut[d]=1;


        sin=1;
        p=e[d];
        while (p)
        {
            if (!cut[p->d])
                sin=0;
            p=p->to;
        }

        memset(vis,0,sizeof(vis));
        g=0;
        for (i=0;i<n;i++)
            if (!cut[i] && !vis[i])
                dfs(i),g++;
        if (g!=gg && !sin)
            printf("Red Alert: City %d is lost!\n",d);  ///'!'
        else
            printf("City %d is lost.\n",d);
        gg=g;

        if (g==0)
            printf("Game Over.");
    }
    return 0;
}
