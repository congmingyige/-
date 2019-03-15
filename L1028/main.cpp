#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;



int main()
{
    int q,n,m,i;
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d",&n);
        m=sqrt(n)+0.00001;
        for (i=2;i<=m;i++)
            if (n%i==0)
                break;
        if (i==m+1 && n!=1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
