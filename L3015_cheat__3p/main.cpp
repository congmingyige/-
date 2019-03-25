#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

#define ll long long

const int maxn=2e1+10;
const int inf=1e9;
const double eps=1e-8;

int gx[maxn],gy[maxn];


int main()
{
    int n,i,j;
    char c;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%c",&c);
        for (j=1;j<=n;j++)
        {
            scanf("%c",&c);
            if (c=='W')
                ++gx[i],++gy[j];
        }
    }
    for (i=1;i<=n;i++)
        if (gx[i]==0 || gy[i]==0)
        {
            printf("No Solution");
            return 0;
        }
    for (i=1;i<=n;i++)
        printf("%d%c",i,i==n?'\n':' ');
    return 0;
}
/*

*/
