#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

///Ï¸½ÚÌâ

int main()
{
    ///aim:code quantity as small as possible, way as easy as possible
    int n,m,i,j,k,x=0,y;
    scanf("%d",&n);
    m=sqrt(n);///auto:(int)() lower the time complexity
    for (i=2;i<=m;i++)
    {
        k=n;
        j=i;
        while (k%j==0)
        {
            k/=j;
            j++;
        }
        if (j-i>x)  ///i increases
            x=j-i,y=i;
    }
    if (x==0)
        x=1,y=n;///special condition
    printf("%d\n",x);
    ///a special data:2147483647, use k!=x+y rather than k=x+y, since 2147483647+1=minint=-2147483648
    for (k=y;k!=x+y;k++)
    {
        ///the first index, no need to calculate
        if (k!=y)
            printf("*");
        printf("%d",k);
    }
	return 0;
}
