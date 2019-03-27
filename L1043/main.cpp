#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

#define ll long long

const int maxn=1e3+10;
const int inf=1e9;
const double eps=1e-8;

int x[maxn];

int main()
{
    int n,pa=0,pb=0,a,c,d,i;
    char b;
    scanf("%d",&n);
    while (n--)
    {
        for (i=1;i<=1000;i++)
            x[i]=-1;
        pa=0,pb=0;
        while (1)
        {
            scanf("%d %c %d:%d",&a,&b,&c,&d);
            if (a==0)
            {
                if (pa==0)
                    printf("0 0\n");
                else
                    printf("%d %.0f\n",pa,1.0*pb/pa);
                break;
            }
            if (b=='S')
                x[a]=c*60+d;
            else if (b=='E')
            {
                if (x[a]!=-1)
                {
                    pa++;
                    pb+=c*60+d-x[a];
                    x[a]=-1;
                }
            }
        }
    }
    return 0;
}
/*

*/
