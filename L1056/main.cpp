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
    char a[10],b;
}f[maxn];

int main()
{
    int n,i,j;
    double ave=0,cha=10000000.0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%s%d",f[i].a,&f[i].b);
        ave+=f[i].b;
    }
    ave/=n*2;
    for (i=1;i<=n;i++)
        if (fabs(f[i].b-ave)<cha)
            cha=fabs(f[i].b-ave),j=i;
    printf("%d %s",(int)ave,f[j].a);
    return 0;
}
/*

*/
