#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;
const double eps=1e-8;

struct node
{
    int a;
    char b[10];
    bool vis;
}f[100];

int main()
{
    int n,i,j;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d%s",&f[i].a,f[i].b);
    for (i=1;i<=n/2;i++)
    {
        for (j=n;j>=1;j--)
            ///f[i].a+f[j].a==1�ù������ж�
            if (f[i].a+f[j].a==1 && f[j].vis==0)
                break;
        f[j].vis=1;
        printf("%s %s\n",f[i].b,f[j].b);
    }
    ///����С������ֱ�ӱ�������ʱ�䲻��ʱ��������С
    return 0;
}
