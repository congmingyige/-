#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/*
不建议一开始做此题。
先做模板题。

骗分
输出1(2分) / n(4分)

如果可以有暴力解，写！
1.得到大部分分
2.对拍

这题没有暴力解。。。
*/

const int maxn=1e5+10;

int a[maxn];

int main()
{
	int n,g=0,d,i,l,r,m;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
	    ///当前每个铁轨最大的列车编号为a[1]...a[g]。编号为d的列车增添进来，插入到a[1]...a[g]中编号小于d的最大的编号的列车的后面；如果没有，新开辟一个铁轨
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

