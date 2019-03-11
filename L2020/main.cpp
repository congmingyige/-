#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;

///同样的，理解题意后再下手，可以画画图谱，算算样例，鉴于样例并不大，这些时间不能省，如果求稳的话

struct node
{
    int d;
    node *to;
}*e[maxn];

double large[maxn],v[maxn];
int q[maxn];

int main()
{
    node *p;
    int n,d,dd,i,g,head,tail;
    double z,r,ans;
    scanf("%d%lf%lf",&n,&z,&r);
    r=1-r/100;
    for (i=0;i<n;i++)
    {
        scanf("%d",&g);
        if (g==0)
            scanf("%lf",&large[i]); ///number is show in int type, use %lf !
        else
        {
            large[i]=0;
            while (g--)
            {
                scanf("%d",&d);
                p=new node();
                p->d=d;
                p->to=e[i];
                e[i]=p;
            }
        }
    }

    ///use bfs for safety
    head=0,tail=1;

    if (large[0]!=0)
        v[0]=z*large[0],ans=v[0];
    else
        v[0]=z,ans=0;
    q[1]=0;
    while (head<tail)
    {
        head++;
        d=q[head];

        p=e[d];
        while (p)
        {
            dd=p->d;
            q[++tail]=dd;
            v[dd]=v[d]*r;
            if (large[dd]!=0)
                v[dd]*=large[dd],ans+=v[dd];
            p=p->to;
        }
    }
    printf("%lld",(long long)ans);
    return 0;
}
