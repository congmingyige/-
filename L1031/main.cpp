#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;
const double eps=1e-8;

///造特殊数据，刚好10%

int main()
{
    int q;
    double a,b,c,d;
    scanf("%d",&q);
    while (q--)
    {
        scanf("%lf%lf",&a,&b);
        a=(a-100)*0.9*2;
        c=a*0.9;
        d=a*1.1;
        if (b>c+eps && b<d-eps)
            printf("You are wan mei!\n");
        else if (b>d-eps)
            printf("You are tai pang le!\n");
        else
            printf("You are tai shou le!\n");
    }
    return 0;
}
