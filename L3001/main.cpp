#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;

//39

int a[maxn],f[maxn];

void print(int m)
{
    if (m==0)
        return;
    if (f[m]!=0)
        printf(" ");
    print(f[m]);
    printf("%d",m-f[m]);
}

int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for (i=1;i<=m;i++)
        f[i]=-1;
    f[0]=0;
    for (i=n;i>=1;i--)
        for (j=m-a[i];j>=0;j--)
            if (f[j]!=-1)
                f[j+a[i]]=j;
    print(m);
    return 0;
}
