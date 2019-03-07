#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

int a[3];

int main()
{
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    if (a[0]>a[1])
        swap(a[0],a[1]);
    if (a[0]>a[2])
        swap(a[0],a[2]);
    ///a[0] smallest
    if (a[1]>a[2])
        swap(a[1],a[2]);
    printf("%d->%d->%d",a[0],a[1],a[2]);
    return 0;
}
