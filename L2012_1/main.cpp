#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

#define ll long long

const int maxn=2e4+10;
const int inf=1e9;
const double eps=1e-8;

int z[maxn],pos[maxn];
///10000*2

void up(int i)
{
    while (i!=1 && z[i]<z[i>>1])
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
    int n,m,delta=1e4,a,f,i,x;
    char b[20],c[20],d[20],e[20];
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&x);
        z[i]=x;
        up(i);
    }
    ///negftive
    for (i=1;i<=n;i++)
        pos[z[i]+delta]=i;
    while (m--)
    {
        scanf("%d%s",&a,b);
        a+=delta;
        if (strcmp(b,"and")==0)
        {
            ///2
            scanf("%d",&f);
            f+=delta;
            fgets(c,maxn,stdin);
            print(pos[a]/2==pos[f]/2 && min(pos[a],pos[f])%2==0);
        }
        else
        {
            scanf("%s%s",c,d);
            if (strcmp(c,"a")==0)
            {
                ///4
                scanf("%s%d",e,&f);
                f+=delta;
                print(pos[a]/2==pos[f]);
            }
            else
            {
                if (strcmp(d,"root")==0)
                {
                    ///1
                    print(pos[a]==1);
                }
                else
                {
                    ///3
                    scanf("%s%d",e,&f);
                    f+=delta;
                    print(pos[f]/2==pos[a]);
                }
            }
        }
    }
    return 0;
}
