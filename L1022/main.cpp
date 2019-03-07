#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

int a[2];///basiclly,zero

int main()
{
    int n,d;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&d);
        a[d&1]++;
    }
    printf("%d %d\n",a[1],a[0]);
    return 0;
}
