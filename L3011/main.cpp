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

const int maxn=2e2+10;
const int inf=1e9;
const double eps=1e-8;

map<string,int>ma1;
map<int,string>ma2;

struct node
{
    int d,len;
    node *to;
}*e[maxn];

struct rec
{
    int x,y,z;
    bool operator>(rec b)
    {
        if (x==b.x)
        {
            if (y==b.y)
                return z<b.z;
            return y<b.y;
        }
        return x>b.x;
    }
}dist[maxn],temp;

int pre[maxn],g[maxn],tot[maxn];
bool vis[maxn];

void print(int d)
{
    if (d==1)
        cout<<ma2[1];
    else
    {
        print(pre[d]);
        cout<<"->"<<ma2[d];
    }
}

int main()
{
    node *p;
    char s1[5],s2[5];
    int n,m,en,d,k,i,j,x,y,z;
    scanf("%d%d%s%s",&n,&m,s1,s2);
    ma1[s1]=1;
    ma2[1]=s1;

    for (i=2;i<=n;i++)
    {
        scanf("%s%d",s1,&g[i]);
        ma1[s1]=i;
        ma2[i]=s1;
    }
    en=ma1[s2];
    while (m--)
    {
        scanf("%s%s%d",s1,s2,&z);
        x=ma1[s1],y=ma1[s2];
        p=new node();
        p->d=y;
        p->len=z;
        p->to=e[x];
        e[x]=p;

        p=new node();
        p->d=x;
        p->len=z;
        p->to=e[y];
        e[y]=p;
    }
    memset(dist,0x3f,sizeof(dist));
    dist[1]={0,0,0};
    tot[1]=1;
    for (i=1;i<=n;i++)
    {
        d=0;
        for (j=1;j<=n;j++)
            if (!vis[j] && dist[d]>dist[j])
                d=j;
        if (d==en)
            break;
        vis[d]=1;
        p=e[d];
        while (p)
        {
            k=p->d;
            temp={dist[d].x+p->len,dist[d].y+1,dist[d].z+g[k]};
            if (dist[k].x>dist[d].x+p->len)
                tot[k]=tot[d];
            else if (dist[k].x==dist[d].x+p->len)
                tot[k]+=tot[d];
            if (dist[k]>temp)
                dist[k]=temp,pre[k]=d;
            p=p->to;
        }
    }
    print(en);
    printf("\n%d %d %d",tot[en],dist[en].x,dist[en].z);
    return 0;
}
