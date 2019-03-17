#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/**
选择上凹或者下凸都可以

这里选择下凸，最多有n-1条边，
参见证明doc
**/

const int maxn=1e4+10;
const int inf=1e9;
const int eps=1e-8;

struct node
{
    int x,y,yy;
}d[maxn],a[maxn];

int cross(node c,node a,node b)
{
    return (c.y-a.y)*(c.x-b.x) - (c.x-a.x)*(c.y-b.y);
}

bool cmp(node a,node b)
{
    int v=cross(d[1],a,b);
    if (v==0)
        ///为了实现下方的"一个点被加进来，然后被另外一个点替代"
        return abs(a.x-d[1].x)<abs(b.x-d[1].x); ///dist(d[1],a)>dist(d[1],b)
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

    if (n==1)
    {
        printf("%d %d %d %d",-1,d[1].y,0,d[1].y);
        return 0;   ///两个语句不能连在一起写
    }

    m=0;
    for (i=1;i<=n;i++)
    {
        while (m>=2 && cross(a[m],a[m-1],d[i])>=0)  ///必须加上等号(这里指的是凸包，但其实这里可以省去)，三点共线，一个点被加进来，然后被另外一个点替代
            m--;
        a[++m]=d[i];
    }

    for (i=2;i<=m;i++)
    {
        if (a[i].x<a[i-1].x)
            break;

        k=1.0*(a[i].y-a[i-1].y)/(a[i].x-a[i-1].x);
        b=a[i].y-k*a[i].x;
        for (j=1;j<=n;j++)
            if (d[j].x*k+b>d[j].yy+eps)
                break;
        if (j==n+1)
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

3
0 6 0
1 6 1
2 6 2

5
0 3 0
1 2 -1
2 1 -2
3 -1 -4
4 1 -2

5
0 4 0
1 3 1
2 2 1
3 3 1
4 4 0

5
0 4 0
1 3 1
2 3 2
3 3 1
4 4 0

5
0 2 0
1 2 -1
2 1 0
3 2 1
4 3 2

1
-3 5 2

3
0 2 0
2 2 0
4 -1 -2

4
0 2 0
1 3 1
4 2 0
6 3 1

6
0 100 1
1 100 2
2 100 4
3 100 3
4 100 1
5 100 5
*/
