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
    char c;
    scanf("%d %c",&n,&c); ///blank is needed, since %c can read blank
    ///if 3:c then %d:c
    for (i=1;i<=(n+1)/2;i++)
    {
        for (j=1;j<=n;j++)
            printf("%c",c);
        printf("\n");
    }
    return 0;
}
