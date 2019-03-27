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

const int maxn=1e5+10;
const int inf=1e9;
const double eps=1e-8;

/*
尽量莫用dfs
*/

struct node
{
    int d;
    node *to;
}*e[maxn],*p;
int dep[maxn],q[maxn];

int main()
{
    int n,d,i,root,head,tail;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&d);
        if (d==-1)
        {
            root=i;
            continue;
        }
        p=new node();
        p->d=i;
        p->to=e[d];
        e[d]=p;
    }
    head=0;
    tail=1;
    q[1]=root;
    while (head<tail)
    {
        head++;
        p=e[q[head]];
        while (p)
        {
            tail++;
            q[tail]=p->d;
            dep[p->d]=dep[q[head]]+1;
            p=p->to;
        }
    }
    ///利用队列性质
    printf("%d",dep[q[n]]+1);
    for (i=n;i>=1;i--)
        if (dep[q[n]]!=dep[q[i]])
            break;
        else
            printf("%c%d",(i==n)?'\n':' ',q[i]);
    return 0;
}
/*

*/
