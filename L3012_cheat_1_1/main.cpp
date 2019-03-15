#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/**
y1>y2

假设只有一个点
**/

const int maxn=1e3+10;
const int inf=1e9;


int main()
{
    int n,x,y1,y2,i;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d%d%d",&x,&y2,&y1);
    printf("%d %d %d %d",-1,y1,0,y1);
    return 0;
}
