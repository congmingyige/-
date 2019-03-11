#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;

#define ll long long

/*
<=2​^31​​
maybe 2^31
long long
unsigned int
*/

struct node
{
    int x,y;
    bool operator<(node b)
    {
        return y<b.y;
    }
}f[maxn];

ll a[maxn<<2],del[maxn<<2];

void build(int ind,int l,int r)
{
    if (l==r)
        scanf("%lld",&a[ind]);
    else
    {
        int m=(l+r)>>1;
        build(ind<<1,l,m);
        build(ind<<1|1,m+1,r);
        a[ind]=min(a[ind<<1],a[ind<<1|1]);
    }
}

void push_down(int ind,int l,int r)
{
    if (l!=r)
    {
        del[ind<<1]+=del[ind];
        del[ind<<1|1]+=del[ind];
    }
    a[ind]=max(a[ind]-del[ind],0ll);    ///
    del[ind]=0;
}

int query(int ind,int l,int r,int x,int y)
{
    if (del[ind]!=0)    ///放在前面
        push_down(ind,l,r);
    if (x<=l && r<=y)
        return a[ind];
    int m=(l+r)>>1;
    if (x<=m && m<y)
        return min(query(ind<<1,l,m,x,y),query(ind<<1|1,m+1,r,x,y));
    else if (x<=m)
        return query(ind<<1,l,m,x,y);
    else
        return query(ind<<1|1,m+1,r,x,y);
}

void modify(int ind,int l,int r,int x,int y,ll z)
{
    if (x<=l && r<=y)
    {
        del[ind]+=z;
        push_down(ind,l,r);
        return;
    }
    if (del[ind]!=0)
        push_down(ind,l,r);
    int m=(l+r)>>1;
    if (x<=m)
        modify(ind<<1,l,m,x,y,z);
    if (m<y)
        modify(ind<<1|1,m+1,r,x,y,z);
    a[ind]=min(a[ind<<1],a[ind<<1|1]);///这步操作，可以做到修改所有的min，自然不用再query()中再执行一次
}

int main()
{
    int n,q,i,d;
    ll ans=0;
    scanf("%d%d",&n,&q);
    n--;
    build(1,1,n);
    for (i=1;i<=q;i++)
    {
        scanf("%d%d",&f[i].x,&f[i].y);
        if (f[i].x>f[i].y)
            swap(f[i].x,f[i].y);
        f[i].x++;
    }

    sort(f+1,f+q+1);
    for (i=1;i<=q;i++)
    {
        d=query(1,1,n,f[i].x,f[i].y);
        if (d!=0)
        {
            ans+=d;
            modify(1,1,n,f[i].x,f[i].y,d);
        }
    }
    printf("%lld",ans);
    return 0;
}
/*
5 2
3 2 4 3
1 3
2 4

5 3
3 2 4 3
1 3
2 4
0 2
*/
