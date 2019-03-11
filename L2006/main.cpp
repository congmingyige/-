#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int maxn=1e3+10;

///数字：不确定大小。可以开一个足够大的数组，一般没问题。更保险：map。

map<int,int> ma,fan_ma;

struct node
{
	int l,r;
}tr[31];

int a[31],b[31];

//void work(int l,int r,int p,int q,int fa,int cond)
//{
//	int root=a[r],pos;
//	for (pos=p;pos<=q;pos++)
//		if (b[pos]==root)
//			break;
//	if (cond==1)
//		tr[fa].l=root;
//	else
//		tr[fa].r=root;
//	if (p<=pos-1)
//		work(l,l+pos-1-p,p,pos-1,root,1);
//	if (pos+1<=q)
//		work(l+pos-p,r-1,pos+1,q,root,2);
//}

void work(int s,int t,int x,int y)
{
    int i;
    for (i=x;i<=y;i++)
        if (b[i]==a[t])
            break;
    ///i-x+1,y-i
    if (i!=x)
    {
        tr[a[t]].l=a[s+i-x-1];
        work(s,s+i-x-1,x,i-1);
    }

    if (i!=y)
    {
        tr[a[t]].r=a[t-1];
        work(s+i-x,t-1,i+1,y);
    }
}

int main()
{
	int i,head,tail,n,s;
	int q[31];
	scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&s);
        a[i]=i;
        ma[s]=i;
        fan_ma[i]=s;
    }
	for (i=1;i<=n;i++)
    {
        scanf("%d",&s);
        b[i]=ma[s];
    }
	work(1,n,1,n);

	head=0;
	tail=1;
	q[1]=a[n];
	while (head<tail)
	{
		head++;
        if (head!=1)
            printf(" ");
		printf("%d",fan_ma[q[head]]);
		if (tr[q[head]].l!=0)
			q[++tail]=tr[q[head]].l;
		if (tr[q[head]].r!=0)
			q[++tail]=tr[q[head]].r;
	}
	return 0;
}
