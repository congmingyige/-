#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

///�о������ⶼ�ܷ��ڵ��������ˣ�����ѡ���Ӻ�����������Ԥ���㹻��ʱ���������⡣
///��һ�¶���ڶ����ֵ�������������������Ӳ��ͷƤҲҪ������

struct node
{
    int d,len;
    node *to;
}*e[maxn];

int dist[maxn],maxper[maxn],g[maxn],per[maxn],pre[maxn];

int s,t;
bool vis[maxn];

void print(int d)
{
    if (d!=s)   ///
    print(pre[d]);
    printf("%d",d);
    if (d!=t)   ///
        printf(" ");
}

int main()
{
    int n,m,d,a,b,c,i,j,dd;
    node *p;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for (i=0;i<n;i++)
        scanf("%d",&per[i]);
    while (m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        p=new node();
        p->d=b;
        p->len=c;
        p->to=e[a];
        e[a]=p;

        p=new node();
        p->d=a;
        p->len=c;
        p->to=e[b];
        e[b]=p;
    }
    memset(dist,0x7f,sizeof(dist));
    dist[n]++;///useless, promote that has solution(s)
    ///0-n-1, not use dist[0]...
    dist[s]=0;
    g[s]=1;
    for (i=1;i<=n;i++)
    {
        d=n;
        ///0-n-1
        for (j=0;j<n;j++)     ///i,j pay attention
            if (!vis[j] && dist[j]<dist[d])
                d=j;

        vis[d]=1;
        p=e[d];
        while (p)
        {
            dd=p->d;
            if (dist[dd]>dist[d]+p->len)
            {
                dist[dd]=dist[d]+p->len;///copy previous code, modify '<'
                maxper[dd]=maxper[d]+per[dd];
                pre[dd]=d;
                g[dd]=g[d];
            }
            else if (dist[dd]==dist[d]+p->len)
            {
                if (maxper[dd]<maxper[d]+per[dd])///copy
                {
                    maxper[dd]=maxper[d]+per[dd];
                    pre[dd]=d;
                }
                g[dd]+=g[d];
            }

            p=p->to;
        }
    }
    printf("%d %d\n",g[t],maxper[t]+per[s]);  ///
    print(t);
    return 0;
}
