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

int per[maxn],sex[maxn],g_pr1,pr1[maxn],g_pr2,pr2[maxn],f1[maxn],f2[maxn];
double rel[maxn][maxn];
char s[20];

void print(int d)
{
    if (sex[d]==1)
        printf("-");
    printf("%d",d);
}

int main()
{
    int n,m,q,i,j,k,g1,g2,a,b,d;
    double v1,v2;
    scanf("%d%d",&n,&m);
    while (m--)
    {
        scanf("%d",&q);
        g1=0,g2=0;
        for (i=1;i<=q;i++)
        {
            scanf("%s",s);
            d=abs(atoi(s));
            if (s[0]=='-')
                sex[d]=1,f1[++g1]=d;
            else
                sex[d]=0,f2[++g2]=d;
        }
        v1=1.0/q;
        for (j=1;j<=g1;j++)
            for (k=1;k<=g2;k++)
                rel[f1[j]][f2[k]]+=v1,rel[f2[k]][f1[j]]+=v1;
    }

    scanf("%s",s);
    a=abs(atoi(s));
    if (s[0]=='-')  ///也许会出现之前未曾出现过的数字
        sex[a]=1;
    else
        sex[a]=0;

    scanf("%s",s);
    b=abs(atoi(s));
    if (s[0]=='-')
        sex[b]=1;
    else
        sex[b]=0;

    v1=0;
    for (i=0;i<n;i++)
        if (sex[a]+sex[i]==1)
        {
            if (rel[a][i]>v1+eps)
                v1=rel[a][i],g_pr1=1,pr1[1]=i;
            else if (fabs(rel[a][i]-v1)<eps)
                pr1[++g_pr1]=i;
        }

    v2=0;
    for (i=0;i<n;i++)
        if (sex[b]+sex[i]==1)
        {
            if (rel[b][i]>v2+eps)
                v2=rel[b][i],g_pr2=1,pr2[1]=i;
            else if (fabs(rel[b][i]-v2)<eps)
                pr2[++g_pr2]=i;
        }
    sort(pr1+1,pr1+g_pr1+1);
    sort(pr2+1,pr2+g_pr2+1);

    if (fabs(v1-rel[a][b])<eps && fabs(v2-rel[b][a])<eps)
        print(a),printf(" "),print(b);
    else
    {
        for (i=1;i<=g_pr1;i++)
            print(a),printf(" "),print(pr1[i]),printf("\n");
        for (i=1;i<=g_pr2;i++)
            print(b),printf(" "),print(pr2[i]),printf("\n");
    }
    return 0;
}
/*
2 1
2 -0 1
1 -0

2 1
2 -0 1
-0 1

*/
