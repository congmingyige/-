#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

///min,max function
///better way:马拉车算法

char str[maxn];

int main()
{
	int i,j,len,r=0;
	gets(str);
	len=strlen(str);
	for (i=0;i<len;i++)
	{
		//mid
		for (j=0;j<=min(i,len-1-i);j++)
			if (str[i-j]!=str[i+j])
				break;
		r=max(r,j*2-1);
		//left
		for (j=0;j<=min(i,len-1-i-1);j++)
			if (str[i-j]!=str[i+j+1])
				break;
		r=max(r,j*2);
	}
	printf("%d\n",r);
	return 0;
}
