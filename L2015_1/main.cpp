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
	�ҵĽ�����k�ĳ�q��������ʱ����i,j,k...��ʹ�ã������ظ�
	**/
	scanf("%d%d%d",&n,&m,&q);
	for (i=1;i<=n;i++)
	{
        x=inf,y=0;
        for (j=0;j<m;j++)
        {
            ///������break,continue�Ȳ������ֶ���д�������һ�к͵ڶ����ǿ��Ժϲ�д�ģ���','����
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
