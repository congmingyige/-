#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

int main()
{
    int n;
    scanf("%d",&n);
    printf("2^%d = %d",n,1<<n);///bitset operation is faster thanfour arithmetic operation
    return 0;
}
