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

const int maxn=1e2+10;
const int inf=1e9;
const double eps=1e-8;

map<int,int>ma;

struct node
{
    int v,l,r,c,f;
}tr[maxn];

int i,v;

void work(int pos)
{
    if (v<tr[pos].v)
    {
        if (tr[pos].l==0)
            tr[pos].l=i,tr[i].f=pos,tr[i].c=tr[pos].c+1;
        else
            work(tr[pos].l);
    }
    else
    {
        if (tr[pos].r==0)
            tr[pos].r=i,tr[i].f=pos,tr[i].c=tr[pos].c+1;
        else
            work(tr[pos].r);
    }
}

void print(bool v)
{
    if (v)
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
{
    int n,q,a,b;
    string c,d,e,f;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&v);
        if (i!=1)
            work(1);
        tr[i].v=v;
        ma[v]=i;
    }
    if (ma.find(100)!=ma.end())
        printf("Y");

    scanf("%d",&q);
    while (q--)
    {
        cin>>a>>c;
        if (c=="is")
        {
            cin>>c>>d;
            if (d=="root")
                ///判断需写在前面
                print(ma.find(a)!=ma.end() && ma[a]==1);
            else if (d=="parent")
            {
                cin>>c>>b;
                print(ma.find(a)!=ma.end() && ma.find(b)!=ma.end() && tr[ma[b]].f==ma[a]);
            }
            else if (d=="left")
            {
                cin>>c>>d>>b;
                print(ma.find(a)!=ma.end() && ma.find(b)!=ma.end() && tr[ma[b]].l==ma[a]);
            }
            else
            {
                cin>>c>>d>>b;
                print(ma.find(a)!=ma.end() && ma.find(b)!=ma.end() && tr[ma[b]].r==ma[a]);
            }
        }
        else
        {
            cin>>b>>c>>d;
            if (d=="siblings")
                print(ma.find(a)!=ma.end() && ma.find(b)!=ma.end() && tr[ma[a]].f==tr[ma[b]].f);
            else
            {
                cin>>c>>d>>e;
                print(ma.find(a)!=ma.end() && ma.find(b)!=ma.end() && tr[ma[a]].c==tr[ma[b]].c);
            }
        }
    }
    return 0;
}
/*

*/
