#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define ll long long

const int maxn=1e4+10;
const int inf=1e9;
const double eps=1e-8;

/**
高精度除法
**/

int a[maxn];

int main()
{
    int x,w,v,i,ww;
    scanf("%d",&x);
    for (w=1;;w++)
    {
        v=0;
        for (i=w;i>=1;i--)
            a[i]=(v*10+1)/x,v=(v*10+1)%x;
        if (v==0)
            break;
    }
    ww=w;
    while (a[w]==0)
        w--;
    for (i=w;i>=1;i--)
        printf("%d",a[i]);
    printf(" %d",ww);
    return 0;
}
