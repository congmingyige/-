#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define ll long long

const int maxn=1e2+10;
const int inf=1e9;
const double eps=1e-8;

int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];

int main()
{
    int ax,ay,bx,by,i,j,k;
    scanf("%d%d",&ax,&ay);
    for (i=1;i<=ax;i++)
        for (j=1;j<=ay;j++)
            scanf("%d",&a[i][j]);
    scanf("%d%d",&bx,&by);
    for (i=1;i<=bx;i++)
        for (j=1;j<=by;j++)
            scanf("%d",&b[i][j]);
    if (ay==bx)
    {
        for (k=1;k<=ay;k++)
            for (i=1;i<=ax;i++)
                for (j=1;j<=by;j++)
                    c[i][j]+=a[i][k]*b[k][j];
        printf("%d %d\n",ax,by);
        for (i=1;i<=ax;i++)
            for (j=1;j<=by;j++)
                printf("%d%c",c[i][j],(j==by)?'\n':' ');
    }
    else
        printf("Error: %d != %d",ay,bx);
    return 0;
}
