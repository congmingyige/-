#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/**
y1>y2
Æ½ÐÐÏß
**/

const int maxn=1e3+10;
const int inf=1e9;


int main()
{
    int n,x,y1,y2,ymin=-inf,i;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x,&y2,&y1);
        ymin=max(ymin,y1);
    }
    printf("%d %d %d %d",-1,ymin,0,ymin);
    return 0;
}
