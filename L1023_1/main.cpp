#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

/// I think it is pretty good

int g[5];
char ch[5]="GPLT";

int main()
{
    char s;
    int a=0,b=0,c=0,d=0;
    while (1)
    {
        scanf("%c",&s);
        if (s=='\n')
            break;
        if (s=='G' || s=='g')
            a++;
        else if (s=='P' || s=='p')
            b++;
        else if (s=='L' || s=='l')
            c++;
        else if (s=='T' || s=='t')
            d++;
    }
    while (a!=0 || b!=0 || c!=0 || d!=0)
    {
        if (a>0)
        {
            printf("G");
            a--;
        }
        if (b>0)
        {
            printf("P");
            b--;
        }
        if (c>0)
        {
            printf("L");
            c--;
        }
        if (d>0)
        {
            printf("T");
            d--;
        }
    }
    return 0;
}
