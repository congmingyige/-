/**
**/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/**
cheat_pass:
非常好的优化：https://blog.csdn.net/foreyes_1001/article/details/52208749

另外的方法：
选择上凹或者下凸都可以

这里选择下凸，最多有n-1条边，
最多判断(n-1)(n-2)/2次，
参见证明doc
**/

const int maxn=1e3+10;
const int inf=1e9;

struct node
{
    int x,y,yy;
}d[maxn],a[maxn];

int cross(node c,node a,node b)
{
    ///都以c开头
    return (c.y-a.y)*(c.x-b.x) - (c.x-a.x)*(c.y-b.y);
}

bool cmp(node a,node b)
{
    int v=cross(d[1],a,b);
    if (v==0)
        return a.x<b.x;
    return v>0;
}

bool cmp1(node c,node a,node b)
{
    int v=cross(d[0],a,b);
    if (v==0)
        return a.x<b.x;
    return v>0;
}

int main()
{
    int n,m,ind=0,i,j;
    double k,b;
    d[0].x=inf;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d%d",&d[i].x,&d[i].yy,&d[i].y);
        if (d[i].x<d[ind].x)
            ind=i;
    }
    swap(d[1],d[ind]);
    sort(d+2,d+n+1,cmp);

    a[1]=d[1],a[2]=d[2];
    m=2;
    for (i=3;i<=n;i++)
    {
        while (m>=2 && cmp1(a[m],a[m-1],d[i])==0)
            m--;
        a[++m]=d[i];
    }

    for (i=2;i<=m;i++)
    {
        k=1.0*(a[i].y-a[i-1].y)/(a[i].x-a[i-1].x);
        b=a[i].y-k*a[i].x;
        for (j=i+1;j<=m;j++)
            if (a[j].yy-a[j].x*k-b<-1e8)
                break;
        if (j==m+1)
        {
            printf("%d %d %d %d",a[i-1].x,a[i-1].y,a[i].x,a[i].y);
            return 0;
        }
    }
    return 0;
}
/*
5
0 6 0
1 6 1
2 6 3
3 6 4
4 6 5
*/
