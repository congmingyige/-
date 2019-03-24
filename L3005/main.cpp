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

/**
首先先读懂题
**/

const int maxn=1e3+100; ///
const int inf=1e9;
const double eps=1e-15;

struct node
{
    int d,len;
    node *to;
}*e[maxn];

int dist[maxn];
bool vis[maxn];

int main()
{
    char sa[10],sb[10],sc[10];
    node *p;
    int n,m,k,l,i,j,ds,a,b,c,rmin,rmax,rb,rx,d;
    double rave,ry;
    scanf("%d%d%d%d",&n,&m,&k,&ds);
    while (k--)
    {
        scanf("%s%s%d",sa,sb,&c);
        if (sa[0]=='G')
        {
            strncpy(sc,sa+1,strlen(sa)-1);
            sc[strlen(sa)-1]=0;
            a=atoi(sc)+n;
        }
        else
            a=atoi(sa);
        if (sb[0]=='G')
        {
            strncpy(sc,sb+1,strlen(sb)-1);
            sc[strlen(sb)-1]=0;
            b=atoi(sc)+n;
        }
        else
            b=atoi(sb);
        p=new node();
        p->d=b;
        p->len=c;
        p->to=e[a];
        e[a]=p;

        p=new node();
        p->d=a;
        p->len=c;
        p->to=e[b];
        e[b]=p;
    }
    rb=0,rx=-1;
    for (l=n+1;l<=n+m;l++)
    {
        memset(dist,0x3f,sizeof(dist));
        memset(vis,0,sizeof(vis));
        dist[l]=0;
        rmin=inf,rmax=0;
        for (i=1;i<=n+m;i++)    ///n+m
        {
            d=0;
            for (j=1;j<=n+m;j++)
                if (!vis[j] && dist[j]<dist[d])
                    d=j;
            if (d==0)
                break;
            vis[d]=1;
            p=e[d];
            while (p)
            {
                if (dist[p->d]>dist[d]+p->len)
                    dist[p->d]=dist[d]+p->len;
                p=p->to;
            }
        }
        rave=0;
        for (i=1;i<=n;i++)
            rmin=min(rmin,dist[i]),rmax=max(rmax,dist[i]),rave+=dist[i];
        rave/=n;

        if (rmax<=ds && (rmin>rx || (rmin==rx && rave<ry)))
            rb=l,rx=rmin,ry=rave;
    }
    if (rb==0)
        printf("No Solution\n");
    else
        printf("G%d\n%.1f %.1f",rb-n,(double)rx,ry);
    return 0;
}
