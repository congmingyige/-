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
const double eps=1e-10;

int use[maxn],ii;
int a,b;
bool vis[maxn];

void dfs(int d,int k)
{
    if (d==1)
    {
        if (use[ii]!=-1)
            use[ii]=k;
    }
    else
    {
        int j=0;
        while (d)
        {
            j+=(d%10)*(d%10);
            d/=10;
        }

        if (j>=a && j<=b)
            use[j]=-1;

        if (!vis[j])
        {
            vis[j]=1;
            dfs(j,k+1);
            vis[j]=0;
        }
    }
}

int main()
{
    int j,k,z=0;
    scanf("%d%d",&a,&b);
    for (ii=a;ii<=b;ii++)
        dfs(ii,0);	//经过一步，小于等于w*9*9，经过的点很少

    z=0;
    for (ii=a;ii<=b;ii++)
        if (use[ii]>0)
    {
        z=1;
        k=sqrt(ii+eps);
        for (j=2;j<=k;j++)
            if (ii%j==0)
                break;
        if (j==k+1)
            use[ii]*=2;
        printf("%d %d\n",ii,use[ii]);
    }
    if (!z)
        printf("SAD");
    return 0;
}
/*

*/
