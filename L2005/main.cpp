#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2e3+10;

int y[maxn],a[51][maxn],g[51];

int main()
{
    int n,k,x,g1,s,t,i,j;
    scanf("%d",&n);
    y[0]=-1;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&x);
        for (j=1;j<=x;j++)
            scanf("%d",&y[j]);
        sort(y+1,y+x+1);///
        for (j=1;j<=x;j++)
            if (y[j]!=y[j-1])
                a[i][++g[i]]=y[j];
        ///先去除重复元素：不容易出错
    }
    scanf("%d",&k);
    while (k--)
    {
        scanf("%d%d",&s,&t);
        i=1,j=1,g1=0;
        while (i<=g[s] && j<=g[t])
        {
            if (a[s][i]==a[t][j])
                i++,j++,g1++;
            else if (a[s][i]<a[t][j])
                i++;
            else
                j++;
        }
        printf("%.2f%%\n",100.0*g1/(g[s]+g[t]-g1));
    }
    return 0;
}
