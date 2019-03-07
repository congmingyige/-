#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;


int f[maxn];
bool vis[maxn],cf[maxn],pr;///basiclly 0(false)

int main()
{
	int n,m,a;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&m);
		if (m==1)
			scanf("%d",&a);
		else
		{
			while (m--)
			{
				scanf("%d",&a);
				vis[a]=1;
			}
		}
	}
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&a);
		if (cf[a])
			continue;
		cf[a]=1;
        if (!vis[a])
        {
            if (!pr)
                pr=1;
            else
                printf(" ");
            printf("%05d",a);///
        }
	}
	if (!pr)
		printf("No one is handsome");
	return 0;
}

