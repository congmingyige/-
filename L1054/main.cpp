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

char a[maxn][maxn];
int n;

bool judge()
{
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            if (a[i][j]!=a[n-1-i][n-1-j])
                return 0;
    return 1;
}

int main()
{
    char ch;
    int i,j;
    scanf("%c%d",&ch,&n);
    fgets(a[0],maxn,stdin);
    for (i=0;i<n;i++)
        fgets(a[i],maxn,stdin);


    if (judge())
        printf("bu yong dao le\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            if (a[n-1-i][n-1-j]==' ')
                printf("%c",' ');
            else
                printf("%c",ch);
        printf("\n");
    }

    return 0;
}
/*

*/
