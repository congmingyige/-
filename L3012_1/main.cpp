#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long
const int maxn=1e4+10;
const int inf=1e9;
const double eps=1e-8;

struct node
{
    int x,y;
}d1[maxn],d2[maxn],a[maxn];

ll cross(node c,node a,node b)
{
    ///两者相乘，也许大于int范围
    return 1ll*(c.y-a.y)*(c.x-b.x) - 1ll*(c.x-a.x)*(c.y-b.y);
}

bool cmp1(node a,node b)
{
    ll v=cross(d1[1],a,b);
    if (v==0)
        return d1[1].x-a.x<d1[1].x-b.x;
    return v<0;
}

bool cmp2(node a,node b)
{
    ll v=cross(d2[1],a,b);
    if (v==0)
        return d2[1].x-a.x<d2[1].x-b.x;
    return v>0;
}

/**
两者在v==0处无法统一
**/

int main()
{
    int n,x,ymax,ymin,i,j,ind=0,m;
    double k,b;
    d1[0].x=inf;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x,&ymax,&ymin);
        d1[i]={x,ymax},d2[i]={x,ymin};
        if (d1[i].x<d1[ind].x)
            ind=i;
    }

    if (n==1)
    {
        printf("%d %d %d %d",-1,ymax,0,ymax);
        return 0;
    }

    swap(d1[1],d1[ind]);
    sort(d1+2,d1+n+1,cmp1); ///注意是+2(对d1[2]~d1[n]排序)
    m=0;
    for (i=1;i<=n;i++)
    {
        while (m>=2 && cross(a[m],a[m-1],d1[i])<=0)
            m--;
        a[++m]=d1[i];
    }

    for (i=2;i<=m;i++)
    {
        if (a[i].x<a[i-1].x)
            break;
        k=1.0*(a[i].y-a[i-1].y)/(a[i].x-a[i-1].x);
        b=a[i].y-k*a[i].x;
        for (j=1;j<=n;j++)
            if (k*d2[j].x+b<d2[j].y-eps)
                break;
        if (j==n+1)
        {
            printf("%d %d %d %d",a[i].x,a[i].y,a[i-1].x,a[i-1].y);
            return 0;
        }
    }

    swap(d2[1],d2[ind]);
    sort(d2+2,d2+n+1,cmp2);
    m=0;
    for (i=1;i<=n;i++)
    {
        while (m>=2 && cross(a[m],a[m-1],d2[i])>=0)
            m--;
        a[++m]=d2[i];
    }
    for (i=2;i<=m;i++)
    {
        if (a[i].x<a[i-1].x)
            break;
        k=1.0*(a[i].y-a[i-1].y)/(a[i].x-a[i-1].x);
        b=a[i].y-k*a[i].x;
        for (j=1;j<=n;j++)
            if (k*d1[j].x+b>d1[j].y+eps)
                break;
        if (j==n+1)
        {
            printf("%d %d %d %d",a[i].x,a[i].y,a[i-1].x,a[i-1].y);
            return 0;
        }
    }

    return 0;
}
/*
4
-1 5 3
2 4 3
1 5 2
0 4 3
*/
