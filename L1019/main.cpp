#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;



int main()
{
	int p,q,n,x=0,y=0,a,b,c,d;
	scanf("%d%d",&p,&q);
	p++;
	q++;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (b==a+c)
		{
			if (d==a+c)
				continue;
			else
				x++;
		}
		else if (d==a+c)
			y++;
		if (x==p)
		{
			printf("A\n%d\n",y);
			return 0;
		}
		else if (y==q)
		{
			printf("B\n%d\n",x);
			return 0;
		}
	}
    return 0;
}
