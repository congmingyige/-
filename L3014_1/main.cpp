#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

/**
看清输入、输出
**/

#define ll long long

const int maxn=1e4+10;
const int maxm=1e2+10;
const int inf=1e9;
const double eps=1e-8;

struct node
{
    int d,w;
    node *to;
}*e[maxn];

struct rec
{
    int x,y,d,w;
    bool operator<(const rec &b) const  ///the second const
    {
        if (b.x==x)
            return b.y<y;
        return b.x<x;
    }
};

struct xyz
{
    int x,y;
    bool operator>(const xyz &b) const    /// > ; don't forget to change 'rec' into 'xyz'
    {
        if (b.x==x)
            return b.y<y;
        return b.x<x;
    }
}dist[maxn][maxm],pre[maxn][maxm],point[maxn],temp;

priority_queue<rec,vector<rec> >que;
int exist[maxn][maxm],step[maxn];
bool vis[maxn][maxm],pr;

int main()
{
    int n,m,q,x,y,d,w,xx,yy,dd,ww,i,j,be,en;
    node *p;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&m);
        for (j=1;j<=m;j++)
        {
            scanf("%d",&y);
            exist[y][0]++;
            exist[y][exist[y][0]]=i;

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
        memset(step,0x3f,sizeof(step));
        memset(dist,0x3f,sizeof(dist));
        memset(vis,0,sizeof(vis));
        while (!que.empty())
            que.pop();
        scanf("%d%d",&be,&en);
        for (i=1;i<=exist[be][0];i++)
            que.push({1,1,be,exist[be][i]});
        pr=0;
        while (1)
        {
            while (!que.empty() && vis[que.top().d][que.top().w])
                que.pop();
            if (que.empty())
                break;
            d=que.top().d;
            w=que.top().w;
            x=que.top().x;
            y=que.top().y;
            vis[d][w]=1;
            que.pop();
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
                xx=x+1;
                yy=y+(w!=p->w);
                temp={xx,yy};
                if ((dist[dd][ww]>temp || dist[dd][ww].x==dist[0][0].x) && xx<=step[dd])    ///优化
                {
                    step[dd]=xx;
                    pre[dd][ww]={d,w};
                    dist[dd][ww]={xx,yy};
                    que.push({xx,yy,dd,ww});
                }
                p=p->to;
            }
        }

        if (pr)
        {
            ///d,w
            point[x]={d,w};
            for (i=x-1;i>=1;i--)
                point[i]=pre[point[i+1].x][point[i+1].y];

            printf("%d\n",x-1);
            d=point[1].x,w=point[1].y;
            for (i=1;i<=x;i++)
                if (point[i].y!=w)
                {
                    printf("Go by the line of company #%d from %04d to %04d.\n",w,d,point[i-1].x);
                    d=point[i-1].x,w=point[i].y;
                }
            printf("Go by the line of company #%d from %04d to %04d.\n",w,d,point[x].x);
        }
        else
            printf("Sorry, no line is available.\n");
    }
    return 0;
}
