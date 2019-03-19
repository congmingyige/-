#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

///内存使用最少，画图分析

const int maxn=1e3+10;
const int inf=1e9;
const double eps=1e-8;

char str[maxn];

int main()
{
    int n,m,i,j,k,len;
    scanf("%d",&n);
    fgets(str,maxn,stdin);  ///\n，也可以scanf("%d\n",&n);
    fgets(str,maxn,stdin);

    len=strlen(str);
    len--;                  ///天梯赛评测系统，永远要去末尾'\n'
    //str[len]=0;

    m=len/n+(len%n!=0);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            k=(m-j)*n+i-1;
            if (k>=len)
                printf(" ");
            else
                printf("%c",str[k]);
        }
        printf("\n");
    }


    return 0;
}
