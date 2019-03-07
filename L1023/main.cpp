#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

int g[5];
char ch[5]="GPLT";

int main()
{
    int i;
    char c;
    while (~scanf("%c",&c))
    {
        c=toupper(c);///若忘记，自己写一个函数
        for (i=0;i<4;i++)
            if (c==ch[i])
                g[i]++;
    }
    i=0;
    while (g[0]+g[1]+g[2]+g[3])
    {
        while (!g[i])
            i=(i+1)%4;
        g[i]--;
        printf("%c",ch[i]);
        i=(i+1)%4;
    }
    return 0;
}
