#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

struct node
{
    double g,p;
}f[maxn];

bool cmp(node a,node b)
{
    return a.p>b.p;
}

int main()
{
    int n,m,i;
    double ans=0;
    scanf("%d%d",&n,&m);
    ///if want to input integer, can save as real, using %lf


    for (i=1;i<=n;i++)
        scanf("%lf",&f[i].g);   ///maybe Ð¡Êý
    for (i=1;i<=n;i++)
        scanf("%lf",&f[i].p),f[i].p/=f[i].g;
    sort(f+1,f+n+1,cmp);
    i=1;
    while (i!=n+1 && m>f[i].g)
    {
        ans+=f[i].g*f[i].p;
        m-=f[i].g;
        i++;
    }
    ans+=m*f[i].p;///init 0
    printf("%.2f",ans);
    return 0;
}
