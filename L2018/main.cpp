#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/**
2^31����ʵ����int��Χ������û�п�����
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
/// \\�����ӷ��� ���������о��������һ�㡣copy�Ļ����������һ�С�
printf("Outgoing #: %d\n\\
Introverted #: %d\n\\
Diff = %lld",n-x,x,v);
//    printf("Outgoing #: %d\n",n-x);
//    printf("Introverted #: %d\n",x);
//    printf("Diff = %lld\n",v);
    return 0;
}
