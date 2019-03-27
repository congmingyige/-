#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

#define ll long long

const int maxn=1e4+10;
const int inf=1e9;
const double eps=1e-8;

int x[maxn],y[maxn];
bool vis[maxn],v;

int main()
{
    int n,m,p,i,k,d;
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
        scanf("%d%d",&x[i],&y[i]);
    scanf("%d",&k);
    while (k--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&p);
        for (i=1;i<=p;i++)
        {
            scanf("%d",&d);
            vis[d]=1;
        }
        v=1;
        for (i=1;i<=m;i++)
            if (!vis[x[i]] && !vis[y[i]])
            {
                v=0;
                break;
            }
        if (v)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
/*

*/
