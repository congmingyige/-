#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/**
不能按照index[son]=index[father]*2(+1)的方式编号
**/

const int maxn=1e3+10;
const double eps=1e-8;

int n,s,i,q[maxn];
bool vis=1;

struct node
{
    int s,l,r;
}tr[maxn];

void work(int d,int ind)
{
    if (s>tr[d].s)
    {
        ind<<=1;
        if (tr[d].l==0)
            tr[d].l=i,vis=vis && (ind<=n);
        else
            work(tr[d].l,ind);
    }
    else
    {
        ind=ind<<1|1;
        if (tr[d].r==0)
            tr[d].r=i,vis=vis && (ind<=n);
        else
            work(tr[d].r,ind);
    }
}

int main()
{
    int head,tail,d;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&s);
        tr[i].s=s;
        if (i!=1)
            work(1,1);
    }

    q[1]=1;
    head=0,tail=1;
    while (head<tail)
    {
        head++;
        d=q[head];
        if (head!=1)
            printf(" ");
        printf("%d",tr[d].s);
        if (tr[d].l!=0)
            q[++tail]=tr[d].l;
        if (tr[d].r!=0)
            q[++tail]=tr[d].r;
    }
    printf("\n");
    if (vis)
        printf("YES");
    else
        printf("NO");
    return 0;
}
