#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define ll long long

const int maxn=1e4+10;
const int inf=1e9;
const double eps=1e-8;



int main()
{
    ///long long
    ll x,y=0,i;
    scanf("%lld",&x);
    for (i=1;;i++)
    {
        y=y*10+1;
        if (y%x==0)
            break;
    }
    printf("%lld %lld",y/x,i);
    return 0;
}
