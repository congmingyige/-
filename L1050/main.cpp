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
    int l,n,v,z,i;
    scanf("%d%d",&n,&l);
    v=1;
    for (i=1;i<=n;i++)
        v=v*26;
    z=v;
    v=v-l;
    for (i=1;i<=n;i++)
    {
        z=z/26;
        printf("%c",v/z+97);
        v=v-v/z*z;
    }
    return 0;
}
/*

*/
