#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;
const int inf=1e9;
const double eps=1e-8;

int g[maxn];

int main()
{
    int n,m,x=0,y=1001,i,j,a;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&m);
        for (j=1;j<=m;j++)
        {
            scanf("%d",&a);
            g[a]++;
        }
    }
    for (i=1;i<=1000;i++)
        if (g[i]>x || (g[i]==x && i>y))
            x=g[i],y=i;
    printf("%d %d",y,x);
    return 0;
}
