#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define ll long long

const int maxn=1e2+10;
const int inf=1e9;
const double eps=1e-8;

///�������ָ����⣺���״̬���ã�����ѡ�������ڶ����ֵļ���

int g[maxn],tot[maxn],a[maxn][maxn];    ///������������*10

int main()
{
    int n,i,j,b=0,rest;

    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&tot[i]),tot[i]*=10;
    rest=n;

    ///���³�ʱ
    i=0;
    while (rest)
    {
        if (i==n)
            i=1;
        else
            i++;

        if (g[i]!=tot[i])
        {
            ///Ƕ�׵ı����������˸о���Խ�����Լ����Ժ���Խ��̣�Խ��
            ///��Ŀת��Ϊ��������ͬУ�Ķ�Ա�������ڵ�λ��
            if (b!=0 && a[i][g[i]]==b)
                b++;
            a[i][++g[i]]=++b;   ///�������Ϥ�����Ƿֿ���д
            if (g[i]==tot[i])
                rest--;
        }
    }
    for (i=1;i<=n;i++)
    {
        printf("#%d\n",i);
        for (j=1;j<=tot[i];j++)
            printf("%d%c",a[i][j],(j%10==0)?'\n':' ');

    }
    return 0;
}
/*
1
2

2
1
2
*/
