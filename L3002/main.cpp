#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

/*]
查第k大的数i：log(n)(树状数组查询小于等于i的数目)*log(n)(二分找到i)
添加：log(n) (树状数组)
删除：log(n) (树状数组)
*/

const int maxn=1e5+10;
int value=1e5;
int a[maxn];
int st[maxn];


int main()
{
	int n,d,l,r,m,i,g,c=0;
	char s[50];
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",s);
		if (strcmp(s,"Pop")==0)
		{
			if (c==0)
			{
				printf("Invalid\n");
				continue;
			}
			d=st[c];
			printf("%d\n",d);
			while (d<=value)
			{
				a[d]--;
				d+=(d & (-d));
			}
			c--;
		}
		else if (strcmp(s,"Push")==0)
		{
			scanf("%d",&d);
			c++;
			st[c]=d;
			while (d<=value)
			{
				a[d]++;
				d+=(d & (-d));
			}
		}
		else
		{
			d=(c+1)>>1;
			if (c==0)
			{
				printf("Invalid\n");
				continue;
			}
			l=1; r=value;
			while (l<=r)
			{
				m=(l+r)>>1;
				g=0;
				i=m;
				while (i>=1)
				{
					g+=a[i];
					i-=(i & (-i));
				}
				if (g>=d)
					r=m-1;
				else
					l=m+1;
			}
			printf("%d\n",l);
		}
	}
	return 0;
}
