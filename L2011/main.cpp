#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define ll long long

const int maxn=1e4+10;
const int inf=1e9;
const double eps=1e-8;

/**
镜像和层次遍历共同处理
**/

map<int,int>ma1,ma2;
int a[maxn],b[maxn],l[maxn],r[maxn],root,q[maxn];

void work(int x,int y,int s,int t)
{
    int i;
    if (x>y)
        return;
    for (i=x;i<=y;i++)
        if (a[i]==b[s])
            break;
    if (i!=x)
        l[b[s]]=b[s+1];
    if (i!=y)
        r[b[s]]=b[s+i-x+1];
    ///[x,i) i [i+1,y]
    work(x,i-1,s+1,s+i-x);
    work(i+1,y,s+i-x+1,t);
}

int main()
{
    int n,s,i,head,tail,d;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&s);
        ma1[s]=i;
        ma2[i]=s;
        a[i]=i;
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&s);
        b[i]=ma1[s];
    }
    work(1,n,1,n);
    head=0,tail=1,q[1]=b[1];
    while (head<tail)
    {
        d=q[++head];

        if (head!=1)
            printf(" ");
        printf("%d",ma2[d]);
        if (r[d]!=0)
            q[++tail]=r[d];
        if (l[d]!=0)
            q[++tail]=l[d];
    }
    return 0;
}
