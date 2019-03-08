#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

/**
even can try to use dfs
i guess it is ok if doesn't has special test data
**/

struct node
{
    int d,len;
    node *to;
}*e[maxn];

int dist[maxn],per[maxn],maxper[maxn],g[maxn],pre[maxn];
int s,t,md=1e9;

void print(int d)
{
    if (d!=s)
        print(pre[d]);
    printf("%d",d);
    if (d!=t)
        printf(" ");
}

void dfs(int d)
{
    node *p=e[d];
    int dd;
    while (p)
    {
        dd=p->d;
        if (dist[dd]>dist[d]+p->len)
        {
            dist[dd]=dist[d]+p->len;
            maxper[dd]=maxper[d]+per[dd];
            pre[dd]=d;
            g[dd]=1;
            if (dd==t)
                md=dist[dd];
            if (dist[dd]<md)
                dfs(dd);
        }
        else if (dist[dd]==dist[d]+p->len)
        {
            if (maxper[dd]<maxper[d]+per[dd])
            {
                maxper[dd]=maxper[d]+per[dd];
                pre[dd]=d;
            }
            g[dd]+=g[d];
            /**
            �𰸴�����Ϊ�ⲿ��û�и��¡������1/0->��2->��3��
            ��2���µ���3���������·������Ϊx��Ȼ����һ�ε��˵�2����·��������֮ǰ�����·����ȣ���ʱ���۱�������3�����ǲ���������3�����Ǵ���ġ���Ӧ�ü�y�������Ǽ�x+y�����߲���y��
            **/
        }
        p=p->to;
    }
}

int main()
{
    node *p;
    int n,m,i,a,b,c;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for (i=0;i<n;i++)
        scanf("%d",&per[i]);
    memset(dist,0x3f,sizeof(dist)); ///can't use 0x7f, use 0x3f, otherwise ...
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
    dist[s]=0;
    dfs(s);
    printf("%d %d\n",g[t],maxper[t]+per[s]);
    print(t);
    return 0;
}
