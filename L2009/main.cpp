#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;

///if no time or is not able to write compare function, just compare one dimension

struct node
{
    int v,g,num;
    bool operator<(node b)
    {
        if (v==b.v)
        {
            if (g==b.g)
                return num<b.num;
            else
                return g>b.g;
        }
        else
            return v>b.v;
    }
}f[maxn];

int main()
{
    int n,m,p,q,i;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&m);
        while (m--)
        {
            scanf("%d%d",&p,&q);
            f[p].v+=q;
            f[p].g++;
            f[i].v-=q;
        }
        f[i].num=i;
    }
    sort(f+1,f+n+1);///no default function
    for (i=1;i<=n;i++)
    //for (i=n;i>=1;i--)    ///if int/... use this, it can avoid writing extra function
        printf("%d %.2f\n",f[i].num,f[i].v/100.0);
    return 0;
}

