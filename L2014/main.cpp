#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/*
������һ��ʼ�����⡣
����ģ���⡣

ƭ��
���1(2��) / n(4��)

��������б����⣬д��
1.�õ��󲿷ַ�
2.����

����û�б����⡣����
*/

const int maxn=1e5+10;

int a[maxn];

int main()
{
	int n,g=0,d,i,l,r,m;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
	    ///��ǰÿ�����������г����Ϊa[1]...a[g]�����Ϊd���г�������������뵽a[1]...a[g]�б��С��d�����ı�ŵ��г��ĺ��棻���û�У��¿���һ������
		scanf("%d",&d);
		l=1;
		r=g;
		while (l<=r)
		{
			m=(l+r)>>1;
			if (d>a[m])
				l=m+1;
			else
				r=m-1;
		}
		if (l==g+1)
		{
			g++;
			a[g]=d;
		}
		else
			a[l]=d;
	}
	printf("%d\n",g);
	return 0;
}

