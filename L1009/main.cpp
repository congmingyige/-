#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

///写一个类，统一，不容易写错

///先看第二部分的题，有没有好做的，先把好做的做了
///然而它是第一部分的题目，还是二十分，很容易影响团队的第一部分总分
///若错部分点，不容易查看的话，先放一边

///多造数据(典型)
///注意错误显示：格式错误

#define ll long long

struct node
{
    ll x,y;
    node()
    {
        x=y=0;
    }
    node(ll xx,ll yy)
    {
        x=xx,y=yy;
    }
    void init()
    {
        char c;
        scanf("%c",&c);
        scanf("%lld/%lld",&x,&y);
    }
    node operator+(const node b)
    {
        node c(x,y);
        c.x=x*b.y+y*b.x;
        c.y=y*b.y;
        ll z=__gcd(c.x,c.y);///faster
        z=abs(z);///
        c.x/=z,c.y/=z;
        return c;
    }
    void print()
    {
        if (x<0)
            printf("-");
        x=abs(x);
        if (x>y)
            printf("%lld",x/y);
        if (x>y && x%y!=0)
            printf(" ");
        if (x%y!=0)
            printf("%lld/%lld",x%y,y);
        if (x==0)
            printf("0");
    }
};

int main()
{
    int n,i;
    scanf("%d",&n);
    node a(0,1);
    node b;
    for (i=1;i<=n;i++)
    {
        b.init();
        a=a+b;
    }
    a.print();
    return 0;
}
/*
1
-5/2

1
0/5

2
1/2 -2/4
*/
