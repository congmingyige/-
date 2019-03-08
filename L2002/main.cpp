#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;

bool vis[maxn],del[maxn];
int nex[maxn],v[maxn],pr1[maxn],pr2[maxn];

int main()
{
    int i,j,n,a,g1=0,g2=0;
    scanf("%d%d",&j,&n);
    for (i=1;i<=n;i++)
    {
//        scanf("%d%d%d",&a,&v[a],&nex[a]); ///not ok or first read a, then read v[a],nex[a]
        scanf("%d",&a);
        scanf("%d%d",&v[a],&nex[a]);
        ///not write vis here
    }
    while (j!=-1)
    {
        if (!vis[abs(v[j])])    ///abs
            pr1[++g1]=j,vis[abs(v[j])]=1;
        else
            pr2[++g2]=j;
        j=nex[j];
    }
    for (i=1;i<=g1;i++)
        if (i==g1)
            printf("%05d %d -1\n",pr1[i],v[pr1[i]]);    ///copy
        else
            printf("%05d %d %05d\n",pr1[i],v[pr1[i]],pr1[i+1]);
    for (i=1;i<=g2;i++)
        if (i==g2)
            printf("%05d %d -1\n",pr2[i],v[pr2[i]]);
        else
            printf("%05d %d %05d\n",pr2[i],v[pr2[i]],pr2[i+1]);
    return 0;
}
