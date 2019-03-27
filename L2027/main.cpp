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

struct node
{
    char a[20];
    int b;
    bool operator<(node y)
    {
        if (b==y.b)
            return strcmp(a,y.a)<0;
        return
            b>y.b;
    }
}per[maxn];

int main()
{
    int n,g,k,i,j,ind,money=0;
    scanf("%d%d%d",&n,&g,&k);
    for (i=1;i<=n;i++)
    {
        scanf("%s%d",per[i].a,&per[i].b);
        if (per[i].b<60)
            continue;
        else if (per[i].b<g)
            money+=20;
        else
            money+=50;
    }
    sort(per+1,per+n+1);
    printf("%d\n",money);
    ind=1;
    while (ind<=k)
    {
        j=ind;
        while (ind!=n && per[ind].b==per[ind+1].b)
            ind++;
        for (i=j;i<=ind;i++)
            printf("%d %s %d\n",j,per[i].a,per[i].b);
        ind++;
    }
    return 0;
}
/*

*/
