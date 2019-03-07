#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

///O(n*m)

struct node
{
    char str[20];
    int x,y;
}per[maxn];

int main()
{
	int n,q,b,i;
	scanf("%d",&n);
    for (i=1;i<=n;i++)
	    scanf("%s%d%d",per[i].str,&per[i].x,&per[i].y);
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&b);
        for (i=1;i<=n;i++)
            if (b==per[i].x)
            {
                printf("%s %d\n",per[i].str,per[i].y);
                break;
            }

	}
	return 0;
}
