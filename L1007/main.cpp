#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

///if meeting something complicated, copy that from website
char str[11][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","fu"};

int main()
{
	char c;
	///1,0 replace true,false. Of course, you can keep your coding habit
	bool vis=0;
	while (1)
	{
		scanf("%c",&c);
		if (c=='\n')
			break;
		if (vis==1)
			printf(" ");
		vis=1;
		if (c=='-')
			printf("%s",str[10]);
		else
			printf("%s",str[c-48]);
	}
	return 0;
}
