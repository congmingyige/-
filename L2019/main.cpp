#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;

char str[maxn][5];

struct node
{
    char a[5];
    int b;
    bool operator<(node y)
    {
        return strcmp(a,y.a)<0;
    }
}x[maxn],y[maxn];

int cmp(const void *a,const void *b)
{
    return strcmp((char*)a,(char*)b);
}

int main()
{
    int n,m,i,j,g=0;
    double tot=0;
    bool vis=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%s",str[i]);
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
    qsort(str+1,n,sizeof(str[0]),cmp);

    j=1;
    for (i=1;i<=g;i++)
    {
        while (j!=n+1 && strcmp(str[j],y[i].a)<0)
            j++;
        if (strcmp(str[j],y[i].a)!=0)
            printf("%s\n",y[i].a),vis=1;
    }
    if (!vis)
        printf("Bing Mei You");
    return 0;
}
