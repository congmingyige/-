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

const int maxn=1e4+10;
const int inf=1e9;
const double eps=1e-8;



int main()
{
    int a,b,c,d,e,x,y;
    cin>>a>>b>>c>>d>>e;
    y=c+d+e;
    x=3-y;
    if ((a>b && x>0) || (a<b && x==3))
        printf("The winner is a: %d + %d",a,x);
    else
        printf("The winner is b: %d + %d",b,y);
}
/*

*/
