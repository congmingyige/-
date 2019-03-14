#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;

///bfs

struct node
{
	int d;
	node *to;
}*e[maxn];  ///no need to initialize, NULL
int q[maxn],len[maxn];

int main()
{
	int n,m,k,i,a,b,head,tail,maxl,num,dd;
	node *p;
	scanf("%d%d%d",&n,&m,&k);
	while (m--)
	{
		scanf("%d%d",&a,&b);
		p=new node();
		p->d=b;
		p->to=e[a];
		e[a]=p;

		p=new node();
		p->d=a;
		p->to=e[b];
		e[b]=p;
	}
	while (k--)
	{
		///initialize!!! written in the head of the block
		for (i=1;i<=n;i++)
			len[i]=0;


		scanf("%d",&q[1]);
		head=0,tail=1;
		while (head<tail)
		{
			head++;
			p=e[q[head]];
			while (p)   ///no need to write p!=NULL NULL=0
			{
			    dd=p->d;
			    ///if wrong, think about special condition ,or think about query all points
				if (len[dd]==0 && dd!=q[1]) ///dd!=q[1], also can use boolean, but add one array
				{
					q[++tail]=dd;
					len[dd]=len[q[head]]+1;
				}
				p=p->to;
			}
		}
		num=0;
		maxl=0;
		for (i=1;i<=n;i++)
			if (maxl<len[i])
			{
				maxl=len[i];
				num=i;
			}
		printf("%d\n",num);
	}
	return 0;
}

