//Ä£Äâ
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

const int maxn=1e3+10;
const int inf=1e9;
const double eps=1e-10;

int a[maxn],pos[maxn],f[maxn];

int main()
{
    int n,m,q,i,g,cur;
    bool r;
    scanf("%d%d%d",&n,&m,&q);
    while (q--)
    {
        g=0;
        for (i=1;i<=n;i++)
            pos[i]=-1;
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        cur=1;
        r=1;
        for (i=1;i<=n;i++)
            if (a[i]!=cur)
            {
                g++;
                pos[a[i]]=g;
                f[g]=a[i];
                if (g>m || (g!=1 && f[g]>f[g-1]))
                {
                    r=0;
                    break;
                }
            }
            else
            {
                cur++;
                while (g!=0 && pos[cur]!=-1)
                    cur++,g--;
            }
        if (r)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
/*

*/
