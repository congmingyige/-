#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

///no need to initialize
int a[10];

int main()
{
    int i;
    char c;
    ///not use scanf("%s",s), for safety
    while (~scanf("%c",&c))
    {
        ///actually it needs
        if (c=='\n')
            continue;
        a[c-48]++;
    }
    for (i=0;i<10;i++)
        if (a[i]>0)
            printf("%d:%d\n",i,a[i]);
    return 0;
}
