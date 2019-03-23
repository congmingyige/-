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

const int maxn=5e2+10;
const int inf=1e9;
const double eps=1e-8;

/**
写成函数形式，便于修改
**/

struct node
{
    int d;
    ll len,time;
    node *to;
}*e[maxn];

struct rec
{
    ll x,y;
    ///time,length
    ///length,point
    bool operator>(rec b) const
    {
        if (x==b.x)
            return y>b.y;
        return x>b.x;
    }
}dist[maxn];

int pr1[maxn],pr2[maxn],pre[maxn],g1=0,g2=0;
int be,en,n;
ll r1,r2;
bool vis[maxn];

bool judge()
{
    if (g1!=g2)
        return 0;
    for (int i=1;i<=g1;i++)
        if (pr1[i]!=pr2[i])
            return 0;
    return 1;
}

void re(int pr[maxn],int g)
{
    for (int i=g;i>=1;i--)
    {
        printf("%d",pr[i]);
        if (i!=1)
            printf(" => ");
    }
    printf("\n");
}

void print(int pr[maxn],int &g)
{
    int d=en;
    ///
    while (d!=-1)
    {
        pr[++g]=d;
        d=pre[d];
    }
}

///修改完work1()，再写work2()
void work1()
{
    node *p;
    int i,d,dd;
    rec temp;
    memset(vis,0,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    dist[n].x++;///
    dist[be]={0,0};
    pre[be]=-1;
    while (1)
    {
        d=n;
        for (i=0;i<n;i++)///
            if (!vis[i] && dist[d]>dist[i])
                d=i;
        if (d==en)
            break;
        vis[d]=1;

        p=e[d];
        while (p)
        {
            dd=p->d;
            temp={dist[d].x+p->time,dist[d].y+p->len};
            if (dist[dd]>temp)
                dist[dd]=temp,pre[dd]=d;
            p=p->to;
        }
    }
    print(pr1,g1);
    r1=dist[en].x;
}

void work2()
{
    node *p;
    int i,d,dd;
    rec temp;
    memset(vis,0,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    dist[n].x++;
    dist[be]={0,0};
    pre[be]=-1;
    while (1)
    {
        d=n;
        for (i=0;i<n;i++)
            if (!vis[i] && dist[d]>dist[i])
                d=i;
        if (d==en)
            break;
        vis[d]=1;

        p=e[d];
        while (p)
        {
            dd=p->d;
            temp={dist[d].x+p->len,dist[d].y+1};
            if (dist[dd]>temp)
                dist[dd]=temp,pre[dd]=d;
            p=p->to;
        }
    }
    print(pr2,g2);
    r2=dist[en].x;
}

int main()
{
    node *p;
    int m,i,a,b,c;
    ll d,ee;
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d%lld%lld",&a,&b,&c,&d,&ee);
//        if (c==1)
//        {
        p=new node();
        p->d=b;
        p->len=d;
        p->time=ee;
        p->to=e[a];
        e[a]=p;
//        }


        if (c==0)
        {
        p=new node();
        p->d=a;
        p->len=d;
        p->time=ee;
        p->to=e[b];
        e[b]=p;
        }
    }
    scanf("%d%d",&be,&en);
    work1();
    work2();
    if (judge())
    {
        printf("Time = %lld; Distance = %lld: ",r1,r2);
        re(pr1,g1);
    }
    else
    {
        printf("Time = %lld: ",r1);
        re(pr1,g1);
        printf("Distance = %lld: ",r2);
        re(pr2,g2);
    }
    return 0;
}
