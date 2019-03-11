#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

int v,pr[maxn],a[maxn],g=0;

void work(int x,int y)
{
    if (x>y)
        return;
    if (x==y)
    {
        pr[++g]=a[x];
        return;
    }
    int i,j;
    if (v==1)
    {
        for (i=x+1;i<=y;i++)
            if (a[i]>=a[x])
                break;
        if (i+1<=y)
            for (j=i+1;j<=y;j++)
                if (a[j]<a[x])
                {
                    printf("NO");
                    exit(0);
                }
        work(x+1,i-1);
        work(i,y);
    }
    else
    {
        for (i=x+1;i<=y;i++)
            if (a[i]<a[x])
                break;
        if (i+1<=y)
            for (j=i+1;j<=y;j++)
                if (a[j]>=a[x])
                {
                    printf("NO");
                    exit(0);
                }
        work(x+1,i-1);
        work(i,y);
    }
    pr[++g]=a[x];
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    ///好好审题，< / >= 唯一性
    if (n==1 || a[2]<a[1])
        v=1;
    else
        v=0;
    work(1,n);
    printf("YES\n");
    for (i=1;i<=n;i++)
        printf("%d%c",pr[i],i==n?'\n':' ');
    return 0;
}

