#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;



int main()
{
    int h,m,v,i;
    scanf("%d:%d",&h,&m);///format
    v=h*60+m;
    if (v<=720)
    {
        printf("Only %02d:%02d.  Too early to Dang.",h,m);///format
        return 0;
    }
    if (m!=0)
        h-=11;
    else
        h-=12;
    for (i=1;i<=h;i++)
        printf("Dang");
    return 0;
}
