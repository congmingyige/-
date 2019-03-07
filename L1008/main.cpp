#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

int main()
{
	int a,b,g=0,i;
	scanf("%d%d",&a,&b);
	for (i=a;i<=b;i++)
	{
		printf("%5d",i);///
		g++;
		if (g%5==0 && i!=b)
			printf("\n");
	}
	printf("\nSum = %d\n",(a+b)*(b-a+1)/2);
	return 0;
}
