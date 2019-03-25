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

int z[maxn];
map<int,int> ma;

void push(int i)
{
    while (i!=1 && z[i>>1]>z[i])
    {
        swap(z[i],z[i>>1]);
        i>>=1;
    }
}

void print(bool v)
{
    if (v)
        printf("T\n");
    else
        printf("F\n");
}

int main()
{
    int n,m,i,a,b;
    string c,d;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&z[i]);
        push(i);
    }
    for (i=1;i<=n;i++)
        ma[z[i]]=i;
    while (m--)
    {
        cin>>a>>c;
        if (c=="is")
        {
            cin>>c>>d;
            if (d=="root")
                print(ma[a]==1);
            else if (d=="parent")
            {
                cin>>c>>b;
                print(ma[a]==ma[b]/2);
            }
            else
            {
                cin>>c>>b;
                print(ma[a]/2==ma[b]);
            }
        }
        else
        {
            cin>>b>>c>>d;
            print(ma[a]/2==ma[b]/2 && min(ma[a],ma[b])%2==0);
        }
    }
    return 0;
}
/*

*/
