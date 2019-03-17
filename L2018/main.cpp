#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/**
2^31，其实超过int范围，但是没有坑数据
1
2147483648
**/

const int maxn=1e5+10;

int a[maxn];

int main()
{
    int n,x,i;
    long long v=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    x=n/2;
    for (i=1;i<=x;i++)
        v-=a[i];
    for (i=x+1;i<=n;i++)
        v+=a[i];
/// \\行连接符。 这样做：感觉这样会快一点。copy的话，会调到下一行。
printf("Outgoing #: %d\n\\
Introverted #: %d\n\\
Diff = %lld",n-x,x,v);
//    printf("Outgoing #: %d\n",n-x);
//    printf("Introverted #: %d\n",x);
//    printf("Diff = %lld\n",v);
    return 0;
}
