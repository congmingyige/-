#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

/**
map
**/

const int maxn=1e4+10;

char str[5];
map<string,int>ma;

struct node
{
    char a[5];
    int b;
    bool operator<(node y)
    {
        return strcmp(a,y.a)<0;
    }
}x[maxn],y[maxn];

int main()
{
    int n,m,g=0,i;
    bool vis=0;
    double tot=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%s",str);
        ma[str]=1;
    }
    scanf("%d",&m);
    for (i=1;i<=m;i++)
    {
        scanf("%s%d",x[i].a,&x[i].b);
        tot+=x[i].b;
    }
    tot/=m;
    for (i=1;i<=m;i++)
        if (x[i].b>tot)
            y[++g]=x[i];
    sort(y+1,y+g+1);

    for (i=1;i<=g;i++)
        if (ma.find(y[i].a)==ma.end())
            printf("%s\n",y[i].a),vis=1;
    if (!vis)
        printf("Bing Mei You\n");
    return 0;
}
