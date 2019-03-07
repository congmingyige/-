#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

int main()
{
    int n,i,j,ans=0;
    scanf("%d",&n);
    j=1;
    for (i=1;i<=n;i++)
    {
        j=j*i;
        ans+=j;
    }
    printf("%d",ans);
    return 0;
}
