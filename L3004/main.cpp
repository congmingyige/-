#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;

///bfs!
///做题前，先明确x,y,z坐标轴的定义，n,m的定义，读入方式。

bool a[61][1287][129];
int dx[6]={0,0,-1,1,0,0};
int dy[6]={0,0,0,0,-1,1};
int dz[6]={-1,1,0,0,0,0};

struct node
{
    short z,x,y;
}q[1287*129*61];

int main()
{
    int m,n,l,t,i,j,k,head,tail,xx,yy,zz,g=0,s;
    scanf("%d%d%d%d",&m,&n,&l,&t);
    for (i=1;i<=l;i++)
        for (j=1;j<=m;j++)
            for (k=1;k<=n;k++)
                scanf("%d",&a[i][j][k]);

    for (i=1;i<=l;i++)
        for (j=1;j<=m;j++)
            for (k=1;k<=n;k++)
                if (a[i][j][k])
                {
                    head=0;
                    tail=1;
                    q[1]={i,j,k};
                    a[i][j][k]=0;
                    while (head<tail)
                    {
                        head++;
                        for (s=0;s<6;s++)
                        {
                            zz=q[head].z+dz[s];
                            xx=q[head].x+dx[s];
                            yy=q[head].y+dy[s];
                            if (xx>=1 && xx<=m && yy>=1 && yy<=n && zz>=1 && zz<=l && a[zz][xx][yy])
                                q[++tail]={zz,xx,yy},a[zz][xx][yy]=0;
                        }
                    }
                    if (head>=t)
                        g+=head;
                }
    printf("%d",g);
    return 0;
}
