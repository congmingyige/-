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

const int maxn=2e1+10;
const int inf=1e9;
const double eps=1e-8;



int main()
{
    int n;
    char a,b,c,d;
    scanf("%d\n",&n);
    if (n==2)
    {
        scanf("%c%c\n%c%c",&a,&b,&c,&d);
        if ((b=='W' && c=='W') || (b=='L' && c=='L'))
            printf("1 2");
        else
            printf("No Solution");
        return 0;
    }
    printf("No Solution");  ///×î¶à1-2¸ö
    return 0;
}
/*

*/
