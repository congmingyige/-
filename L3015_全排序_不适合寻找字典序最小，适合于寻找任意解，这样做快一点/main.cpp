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

const int maxn=1e2+10;
const int inf=1e9;
const double eps=1e-8;

int f[maxn][maxn],a[maxn],n;
bool vis[maxn];

void dfs(int k)
{
    int i;
    if (k==n)
    {
        if (f[a[n]][a[1]])
        {
            for (int j=1;j<=n;j++)
                printf("%d%c",a[j],j==n?'\n':' ');
            exit(0);
        }
        return;
    }
    for (i=k;i<=n;i++)
    {
        swap(a[k],a[i]);
        if (f[a[k]][a[k+1]])
            dfs(k+1);
        swap(a[k],a[i]);    ///Ctrl+D
    }
}

int main()
{
    int i,j;
    char c;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%c",&c);
        for (j=1;j<=n;j++)
        {
            scanf("%c",&c);
            f[i][j]=f[i][j] || (c=='W');
            f[j][i]=f[j][i] || (c=='W');
        }
    }
    if (n==2)
    {
        if (f[1][2] && f[2][1])
            printf("1 2");
        else
            printf("No Solution");
        return 0;
    }
    for (i=1;i<=n;i++)
        a[i]=i;
    for (i=2;i<=n;i++)
        if (f[1][i])
        {
            swap(a[2],a[i]);    ///a[i]=i,a[2]=2;
            dfs(3);
            swap(a[2],a[i]);
        }

    printf("No Solution");
    return 0;
}
/*

*/
