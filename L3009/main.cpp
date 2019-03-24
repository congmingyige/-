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

const int maxn=1e5+10;
const int inf=1e9;
const double eps=1e-8;



struct node
{
    ll x,y;
    void init()
    {
        scanf("%lld%lld",&x,&y);
    }
    ///不要返回void，这妨碍了连续赋值操作(study from https://bbs.csdn.net/topics/330085641)
    node operator==(node b)
    {
        return b;
    }
}d[maxn],x,y;

bool cross(node d1,node d2,node d3)
{
    return (d2.y-d1.y)*(d2.x-d3.x) - (d2.x-d1.x)*(d2.y-d3.y) > 0;
}

int main()
{
    int n,i,g=0,w;
    scanf("%d",&n);
    d[1].init();
    x.init();
    w=1;
    for (i=3;i<=n;i++)
    {
        y.init();
        if (cross(d[w],x,y))
            g++,d[++w]=x;
        else
        {
            while (w>=2 && !cross(d[w-1],d[w],y))
                w--;
        }
        x=y;
    }
    printf("%d",g);
    return 0;
}
/*
5
5 100
4 5
3 -100
2 0
0 -6
output 1
*/
