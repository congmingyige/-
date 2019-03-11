#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e6+10;
#define ll long long

char str[maxn];
ll f[maxn][4];


int main()
{
    int len,i,j,k;
    scanf("%s",str+1);
    len=strlen(str+1);
    f[0][0]=1;
    for (i=1;i<=len;i++)
    {
        f[i][0]=1;
        for (j=1;j<=min(i,3);j++)
        {
            f[i][j]=f[i-1][j-1]+f[i-1][j];
            for (k=1;k<=min(j,i-1);k++)
                if (str[i]==str[i-k])
                {
                    f[i][j]-=f[i-k-1][j-k];
                    break;
                }
        }
    }
    printf("%lld",f[len][0]+f[len][1]+f[len][2]+f[len][3]);
    return 0;
}
/*
a
ab
abc
abcd

a
aa
aaa
aaaa
aaaaa
abab
*/
