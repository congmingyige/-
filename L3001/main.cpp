#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;
const int maxm=1e2+10;

int a[maxn],f[maxn][maxm];
/**
Ӳ�ҵ���ֵ�Ӵ�С����Ȼ������ѡ��
���������µ���ʹ��֮��ʹ���ܽ�����������ø÷�������ԭ���ķ�����
f[i][j]:ʹ��ǰiöӲ�ҵ�����öӲ�ң�ʹ���ܽ��Ϊj��f[i][j]Ϊ����ʹ�õ���ֵ�ı��(��ֵ��С)��
O(nm)

also, as brave as possible to write 'wrong but sound correct' way to cheat some points,
and no to modify if get more than 20(25???) points
**/

int main()
{
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for (i=1;i<=m;i++)
        f[n+1][i]=-1;
    f[n+1][0]=0;
    for (i=n;i>=1;i--)
    {
        for (j=0;j<=m;j++)
            f[i][j]=f[i+1][j];
        for (j=m-a[i],k=m;j>=0;j--,k--)
            if (f[i+1][j]!=-1)
                f[i][k]=i;

//        for (j=0;j<=m;j++)
//            printf("%d:%d ",j,f[i][j]);
//        printf("\n");
    }
    if (f[1][m]==-1)
        printf("No Solution");
    else
    {
        i=1;
        while (m!=0)
        {
            if (i!=1)
                printf(" ");
            i=f[i][m];
            m-=a[i];
            printf("%d",a[i]);
            i++;
        }
    }
    return 0;
}
/*
8 10
1 2 3 4 2 2 3 4

6 16
7 5 3 1 2 2
*/
