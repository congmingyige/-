#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long

///500*500/2=125000
const int maxn=1e6+10;
const int inf=1e9;
const double eps=1e-8;

int x[maxn],y[maxn];
ll c[maxn];
int v,e,k,i,q;
set<ll>se;  ///for safety

bool judge()
{
    memset(c,0,sizeof(c));
    se.clear();
    for (i=1;i<=v;i++)
    {
        scanf("%lld",&c[i]);
        se.insert(c[i]);
    }
    if (se.size()!=k)   ///
        return 0;
    for (i=1;i<=e;i++)
        if (c[x[i]]==c[y[i]])
            return 0;
    return 1;
}

int main()
{
    scanf("%d%d%d",&v,&e,&k);
    for (i=1;i<=e;i++)
        scanf("%d%d",&x[i],&y[i]);
    scanf("%d",&q);
    while (q--)
    {
        if (judge())    ///function
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
