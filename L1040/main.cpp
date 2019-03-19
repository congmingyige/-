#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;
const int inf=1e9;
const double eps=1e-8;



int main()
{
    int n;
    double v;
    char c;
    scanf("%d",&n);
    while (n--) ///while 和 for 简洁，且不用变量i
    {
        scanf("\n%c %lf",&c,&v);   ///\n
        if (c=='M')
            printf("%.2f\n",v/1.09);
        else
            printf("%.2f\n",v*1.09);
    }
    return 0;
}
