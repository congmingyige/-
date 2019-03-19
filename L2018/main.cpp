#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
const double eps=1e-8;

double a[maxn],b[maxn];
double x[maxn],p1[maxn];
int p2[maxn];


int main()
{
    int n,m,g=0,s,t,w1=0,w2=0,i,j;
    double v;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d",&s,&t);
        a[s]=t;
        w1=max(w1,s);
    }
    scanf("%d",&m);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d",&s,&t);
        b[s]=t;
        w2=max(w2,s);
    }
    for (i=w1;i>=w2;i--)
    {
        v=a[i]/b[w2];
        if (v<-0.1+eps || v>0.1-eps)	///
        {
            p1[++g]=v;
            p2[g]=i-w2;
            for (j=w2;j>=0;j--)
                a[i+j-w2]-=v*b[j];
        }

    }

    if (g==0)
        printf("0 0 0.0");
    else
    {
        printf("%d",g);
        for (i=1;i<=g;i++)
            printf(" %d %.1f",p2[i],p1[i]);
    }

    g=0;
    for (i=w2-1;i>=0;i--)
        if (a[i]<-0.1+eps || a[i]>0.1-eps)
            p1[++g]=a[i],p2[g]=i;

    if (g==0)
        printf("\n0 0 0.0");
    else
    {
        printf("\n%d",g);	///
        for (i=1;i<=g;i++)
            printf(" %d %.1f",p2[i],p1[i]);
    }
    return 0;
}
/*
1 1 2
2 1 2 2 3

1 1 2
1 1 2
*/
