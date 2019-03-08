#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

/**
use Floyd to get some point if you have less time or don't know how to write Dijkstra / SPFA / BellmanFord
21 points
**/
/**
even can try to use dfs
i guess it is ok if doesn't has special test data
**/

int dist[maxn][maxn],per[maxn],pre[maxn][maxn],g[maxn][maxn],maxper[maxn][maxn];
///pre[u][v]:the last approach point from u to v
///maxper[u][v]:all the point from u to v, expect source point u. for plus operation

int s,t;

void print(int d)
{
    if (d!=s)
        print(pre[s][d]);
    printf("%d",d);
    if (d!=t)
        printf(" ");
}

int main()
{
    int n,m,i,j,k,a,b,c;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for (i=0;i<n;i++)
        scanf("%d",&per[i]);
    memset(dist,0x3f,sizeof(dist)); ///can't use 0x7f, use 0x3f, otherwise ...
    while (m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if (dist[a][b]>c)   ///include dist[a][b]==inf(dist[0][0])
        {
            dist[a][b]=dist[b][a]=c;
            g[a][b]=g[b][a]=1;
            maxper[a][b]=per[b];
            maxper[b][a]=per[a];
            pre[a][b]=a;
            pre[b][a]=b;
        }
        else if (dist[a][b]==c)
            g[a][b]++,g[b][a]++;
    }

    for (k=0;k<n;k++)
        for (i=0;i<n;i++)
            if (k!=i)
                for (j=0;j<n;j++)
                    if (k!=j && i!=j)
                    {
                        if (dist[i][j]>dist[i][k]+dist[k][j])
                        {
                            dist[i][j]=dist[i][k]+dist[k][j];
                            g[i][j]=g[i][k]*g[k][j];
                            maxper[i][j]=maxper[i][k]+maxper[k][j];
                            pre[i][j]=pre[k][j];
                        }
                        else if (dist[i][j]==dist[i][k]+dist[k][j])
                        {
                            g[i][j]+=g[i][k]*g[k][j];
                            if (maxper[i][j]<maxper[i][k]+maxper[k][j])
                            {
                                maxper[i][j]=maxper[i][k]+maxper[k][j];
                                pre[i][j]=pre[k][j];
                            }
                        }
                    }
    printf("%d %d\n",g[s][t],maxper[s][t]+per[s]);
    print(t);
    return 0;
}
