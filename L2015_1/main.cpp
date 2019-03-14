#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;
const int inf=1e9;
double s[maxn]; ///no need to initialize

int main()
{
	int n,m,q,i,j,x,y,a;
	/**
	我的建议是k改成q，避免有时变量i,j,k...的使用，导致重复
	**/
	scanf("%d%d%d",&n,&m,&q);
	for (i=1;i<=n;i++)
	{
        x=inf,y=0;
        for (j=0;j<m;j++)
        {
            ///当遇到break,continue等操作，分多行写；这里第一行和第二行是可以合并写的，用','隔开
            scanf("%d",&a);
            s[i]+=a;
            x=min(x,a);
            y=max(y,a);
        }

		s[i]=(s[i]-x-y)/(m-2);
	}
	sort(s+1,s+n+1);
	for (i=n-q+1;i<=n;i++)
	{
		printf("%.3f",s[i]);
		if (i!=n)
			printf(" ");
	}
	return 0;
}
