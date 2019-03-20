#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
const int inf=1e9;
const double eps=1e-8;

int data[maxn],nex[maxn],num[maxn];

int main()
{
    int i,j,n,a,x,y,g=0;
    scanf("%d%d",&j,&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a);
        scanf("%d%d",&data[a],&nex[a]);  ///分开写
    }
    //点的个数有可能小于n个
    while (j!=-1)
    {
        num[++g]=j;
        j=nex[j];
    }
    x=1,y=g;
    for (i=1;i<=g;i++)
        if (i%2==0)
        {
            if (i!=1)
                printf("%05d\n",num[x]);
            printf("%05d %d ",num[x],data[num[x]]);
            x++;
        }
        else
        {
            if (i!=1)
                printf("%05d\n",num[y]);
            printf("%05d %d ",num[y],data[num[y]]);
            y--;
        }
    printf("-1");
    return 0;
}
/*
00000 1
00000 5 -1

00100 5
00000 4 99999
00100 1 12309
33218 3 00000
99999 5 -1
12309 2 33218
*/
