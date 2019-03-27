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

const int maxn=20;
const int inf=1e9;
const double eps=1e-8;

struct rec
{
    int x,y;
}q[2][1847560+1];

struct node
{
    short g,a[19];
}s[1<<19];

ll num[1<<19][19];
ll value[19];
///C(n,p)*p max  tot 2^20
int r[20][20],fan[262144+1];
bool vis[19],f[1<<19][19];

int main()
{
    ll v,num1;
    int n,i,j,k,l,x,y,sum,ii;
    int head,tail,tail2,w1,w2,d,xx,ind;
    char c;

    value[0]=1;
    for (i=1;i<=18;i++)
        value[i]=value[i-1]*i;

    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        x=(i==0)?n-1:i-1;
        scanf("%c",&c);
        for (j=0;j<n;j++)
        {
            y=(j==0)?n-1:j-1;
            scanf("%c",&c);
            if (c=='W')
                r[x][y]=1;
            else if (c=='L')
                r[y][x]=1;
        }
    }

    for (i=0;i<=18;i++)
        fan[1<<i]=i;

    sum=(1<<(n-1))-1;
    for (k=0;k<=n-2;k++)
        s[0].a[k]=k;
    for (i=1;i<=sum;i++)
    {
        j=i & (i-1);
        s[i].g=s[j].g+1;
        ///从小到大
        s[i].a[0]=fan[i-j];
        for (k=1;k<s[i].g;k++)
            s[i].a[k]=s[j].a[k-1];

        ///can choose
        l=s[i].g,j=0;
        for (k=0;k<=n-2;k++)
            if (k!=s[i].a[j])
                s[i].a[l++]=k;
            else
                j++;
    }


    w1=0,w2=1;
    head=0,tail=1;
    tail2=0;
    q[0][1]={0,n-1};
    for (ii=0;ii<n-1;ii++)
    {
        while (head<tail)
        {
            head++;
            x=q[w1][head].x;
            y=q[w1][head].y;
            for (i=s[x].g;i<=n-2;i++)
                if (r[y][s[x].a[i]])
                {
                    d=s[x].a[i];
                    xx=x|(1<<d);
                    for (l=0;l<s[x].g;l++)
                        if (s[x].a[l]>d)
                            break;
                    num1=num[x][y]+value[18-ii]*(d-l);

                    if (!f[xx][d])
                    {
                        f[xx][d]=1;
                        q[w2][++tail2]={xx,d};
                        num[xx][d]=num1;
                    }
                    else if (num1<num[xx][d])
                        num[xx][d]=num1;
                }
        }
        w1=w1^1,w2=w2^1;
        head=0,tail=tail2;
        tail2=0;
    }

    j=(1<<(n-1))-1;
    num[j][n-1]=9e18;
    ind=n-1;

    for (i=0;i<=n-2;i++)
        if (f[j][i] && r[i][n-1] && num[j][i]<num[j][ind])
            ind=i;

    if (ind==n-1)
    {
        printf("No Solution");
        return 0;
    }

    memset(vis,0,sizeof(vis));
    v=num[j][ind];
    printf("%d",1);
    for (i=18;i>=20-n;i--)
    {
        j=v/value[i];
        k=0;
        while (vis[k])
            k++;
        while (j--)
        {
            k++;
            while (vis[k])
                k++;
        }
        printf(" %d",k+2);
        vis[k]=1;
        v%=value[i];
    }

    return 0;
}
/*
20
-WWWWWWWWWWWWWWWWWWW
W-WWWWWWWWWWWWWWWWWW
WW-WWWWWWWWWWWWWWWWW
WWW-WWWWWWWWWWWWWWWW
WWWW-WWWWWWWWWWWWWWW
WWWWW-WWWWWWWWWWWWWW
WWWWWW-WWWWWWWWWWWWW
WWWWWWW-WWWWWWWWWWWW
WWWWWWWW-WWWWWWWWWWW
WWWWWWWWW-WWWWWWWWWW
WWWWWWWWWW-WWWWWWWWW
WWWWWWWWWWW-WWWWWWWW
WWWWWWWWWWWW-WWWWWWW
WWWWWWWWWWWWW-WWWWWW
WWWWWWWWWWWWWW-WWWWW
WWWWWWWWWWWWWWW-WWWW
WWWWWWWWWWWWWWWW-WWW
WWWWWWWWWWWWWWWWW-WW
WWWWWWWWWWWWWWWWWW-W
WWWWWWWWWWWWWWWWWWW-

3
-WW
W-W
WW-

3
-WD
D-W
WD-
*/
