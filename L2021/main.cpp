#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

///输出要求复杂：看清求的是啥再下手

const int maxn=1e3+10;
const int inf=1e9;
const double eps=1e-8;

struct node
{
    char a[10];
    int b;
    double c;
    bool operator<(node y)
    {
        if (b==y.b)
            return c>y.c;   ///一旦发现不对，可以选择取反，不再看题
        return b>y.b;
    }
}f[maxn];

int a[maxn];

int main()
{
    int n,m,i,j,g;
    a[0]=-1;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%s",f[i].a);
        scanf("%d",&m);
        for (j=1;j<=m;j++)
            scanf("%d",&a[j]);
        sort(a+1,a+m+1);
        g=0;
        for (j=1;j<=m;j++)
            if (a[j]!=a[j-1])
                g++;
        f[i].b=g;
        f[i].c=1.0*g/m;
    }
    sort(f+1,f+n+1);
    for (i=1;i<=3;i++)
    {
        if (i!=1)
            printf(" ");
        if (i>n)
            printf("-");
        else
            printf("%s",f[i].a);
    }
    return 0;
}
/*
造n=2的数据，取前两个行
*/
