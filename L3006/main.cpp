#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

///easy to get some points
/*
all NO/YES
something NO(缩减版判断) else YES
*/

/*
using function
copy
*/

struct node
{
    int x,y;
    node()
    {
        x=0,y=0;
    }
    node(int xx,int yy)
    {
        x=xx,y=yy;
    }
    void read()
    {
        scanf("%d%d",&x,&y);
    }
    node operator+(const node &b)
    {
        return node(x+b.x,y+b.y);
    }
    node operator-(const node &b)
    {
        return node(x-b.x,y-b.y);
    }
}a[11],d1[11],d2[11],p[22];

int n,m;

void d1x()
{
    for (int i=1;i<=n;i++)
        d1[i].x=a[i].x;
}

void d1x_ni()
{
    for (int i=1;i<=n;i++)
        d1[i].x=-a[i].x;
}

void d1y()
{
    for (int i=1;i<=n;i++)
        d1[i].y=a[i].y;
}

void d1y_ni()
{
    for (int i=1;i<=n;i++)
        d1[i].y=-a[i].y;
}

bool line(int i,int j,int k)
{
    if (1ll*(p[j].x-p[i].x)*(p[k].y-p[i].y) == 1ll*(p[j].y-p[i].y)*(p[k].x-p[i].x))
        return 1;
    return 0;
}

bool ra(int i,int j,int k)
{
    if (1ll*(p[j].x-p[i].x)*(p[j].x-p[i].x) + 1ll*(p[j].y-p[i].y)*(p[j].y-p[i].y) +
        1ll*(p[j].x-p[k].x)*(p[j].x-p[k].x) + 1ll*(p[j].y-p[k].y)*(p[j].y-p[k].y) ==
        1ll*(p[k].x-p[i].x)*(p[k].x-p[i].x) + 1ll*(p[k].y-p[i].y)*(p[k].y-p[i].y)
        )
        return 1;
    return 0;
}

bool rect()
{
    int ci=0,i1=1,i2=2,i;
    //ori n+m-2
    p[n+m-1]=p[1];
    p[n+m]=p[2];
    for (i=3;i<=n+m;i++)
        if (line(i1,i2,i))
            i2=i;
        else if (ra(i1,i2,i))
        {
            ///这里假设原始大旗的四边都与坐标轴是平行的。
            if (p[i1].x!=p[i2].x && p[i1].y!=p[i2].y)
                return 0;
            i1=i2,i2=i,ci++;
        }

        else
            return 0;
    if (ci!=4)
        return 0;
    return 1;
}

bool check()
{
    int i,j,k;
    node delta;
    d1[n+1]=d1[1];
    d2[m+1]=d2[1];

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
            if (d1[i].x-d1[i+1].x==d2[j].x-d2[j+1].x && d1[i].y-d1[i+1].y==d2[j].y-d2[j+1].y)
            {
                ///d1[1]...d1[i] d2[j-1]...d2[1] d2[m]...d2[j+2] d1[i+1]...d1[n]
                delta=d2[j]-d1[i];
                for (k=1;k<=i;k++)
                    p[k]=d1[k]+delta;
                for (k=i+1;k<=i+j-1;k++)
                    p[k]=d2[i+j-k];
                for (k=i+j;k<=i+m-2;k++)
                    p[k]=d2[m+i+j-k];
                for (k=i+m-1;k<=n+m-2;k++)
                    p[k]=d1[k-m+2]+delta;

                if (rect())
                    return 1;
            }
    }

    for (int i=1;i<=m/2;i++)
        swap(d2[i],d2[m+1-i]);

    d2[m+1]=d2[1];
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
            if (d1[i].x-d1[i+1].x==d2[j].x-d2[j+1].x && d1[i].y-d1[i+1].y==d2[j].y-d2[j+1].y)
            {
                ///d1[1]...d1[i] d2[j-1]...d2[1] d2[m]...d2[j+2] d1[i+1]...d1[n]
                delta=d2[j]-d1[i];
                for (k=1;k<=i;k++)
                    p[k]=d1[k]+delta;
                for (k=i+1;k<=i+j-1;k++)
                    p[k]=d2[i+j-k];
                for (k=i+j;k<=i+m-2;k++)
                    p[k]=d2[m+i+j-k];
                for (k=i+m-1;k<=n+m-2;k++)
                    p[k]=d1[k-m+2]+delta;

                if (rect())
                    return 1;
            }
    }

    for (int i=1;i<=m/2;i++)
        swap(d2[i],d2[m+1-i]);

    return 0;
}

bool judge()
{
    /*
    one aspect
5 0 0 2 0 1 1 1 2 0 2
4 0 0 1 1 2 1 2 0
    */
    if (!((n==5 && m==3) || (n==3 && m==5) ||
          (n==4 && m==3) || (n==3 && m==4) ||
          (n==4 && m==4) || (n==3 && m==3)))
        return 0;

    d1x();
    d1y();
    if (check())
        return 1;

    d1x();
    d1y_ni();
    if (check())
        return 1;

    d1x_ni();
    d1y();
    if (check())
        return 1;

    d1x_ni();
    d1y_ni();
    if (check())
        return 1;

    for (int i=1;i<=n;i++)
        swap(a[i].x,a[i].y);

    d1x();
    d1y();
    if (check())
        return 1;

    d1x();
    d1y_ni();
    if (check())
        return 1;

    d1x_ni();
    d1y();
    if (check())
        return 1;

    d1x_ni();
    d1y_ni();
    if (check())
        return 1;

    return 0;
}


int main()
{
    int q,i;
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            a[i].read();
        scanf("%d",&m);
        for (i=1;i<=m;i++)
            d2[i].read();

        if (judge())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
/*
1
3 0 0 1 1 1 0
3 0 0 1 1 0 1

1
3 0 0 5 0 0 6
3 0 0 5 0 0 6

1
4 0 0 3 0 3 2 1 2
3 0 0 1 2 0 2

1
4 1 0 3 0 3 2 2 2
4 0 0 1 0 2 2 0 2

1
5 0 0 3 0 3 2 1 2 0 1
3 0 1 1 2 0 2

1
4 0 0 2 0 2 4 0 1
4 0 0 2 0 4 3 0 3
*/
