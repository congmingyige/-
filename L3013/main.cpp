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
const int maxm=1e2+10;
const int inf=1e9;
const double eps=1e-8;

/**
最短路的题，如果复杂，请看一下其它题是否更简洁，先做其他题；
或者请配备足够的时间；
或者骗点分，考虑n=1；全输出'Sorry, no line is available.'
**/

struct node
{
    int d,w;
    node *to;
}*e[maxn];

struct rec
{
    int x,y;
}dist[maxn][maxm],que[maxn*maxm],pre[maxn][maxm],point[maxn];

int exist[maxn][maxm];

int main()
{
    int n,m,q,x,y,i,j,be,en,head,tail,d,w,s,dd,ww,ss;
    node *p;
    bool pr;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&m);
        for (j=1;j<=m;j++)
        {
            scanf("%d",&y);
            if (j!=1)
            {
                p=new node();
                p->d=y;
                p->w=i;
                p->to=e[x];
                e[x]=p;

                p=new node();
                p->d=x;
                p->w=i;
                p->to=e[y];
                e[y]=p;
            }

            x=y;
        }
    }
    scanf("%d",&q);
    while (q--)
    {
        memset(dist,0x3f,sizeof(dist));
        head=0,tail=0;
        scanf("%d%d",&be,&en);
        for (i=1;i<=exist[be][0];i++)
            que[++head]={be,exist[be][i]};
        pr=0;
        while (head<tail)
        {
            head++;
            d=que[head].x;
            w=que[head].y;
            s=dist[d][w].y;
            if (d==en)
            {
                pr=1;
                break;
            }
            p=e[d];
            while (p)
            {
                dd=p->d;
                ww=p->w;
                ss=s+(w!=ww);

                if (dist[dd][ww].x==dist[0][0].x)
                {
                    que[++tail]={dd,ww};
                    dist[dd][ww]={dist[d][w].x+1,ss};
                    pre[dd][ww]={d,w};
                }
                else if (dist[dd][ww].y>ss)
                {
                    dist[dd][ww]={dist[d][w].x+1,ss};
                    pre[dd][ww]={d,w};
                }
                p=p->to;
            }
        }
        if (pr)
        {
            m=dist[d][w].x;
            point[m]=pre[d][w];
            for (i=m-1;i>=1;i--)
                point[i]=pre[point[i+1].x][point[i+1].y];
            printf("%d\n",m-1);
            x=point[1].x,y=point[1].y;
            for (i=1;i<=m;i++)
                if (y!=point[i].y)
                {
                    printf("Go by the line of company #%d from %04d to %04d.\n",y,w,point[i-1].x);
                    x=point[i-1].x,y=point[i].y;
                }
            printf("Go by the line of company #%d from %04d to %04d.\n",y,w,point[n].x);
        }
        else
            printf("Sorry, no line is available.\n");
    }
    return 0;
}
