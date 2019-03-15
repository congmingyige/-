#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

/**
������/��ƽ�ƣ��ص�������һ���߶εĶ˵�

g++:y1�Ǳ��������������ã�
�ĳ�clang++

��������Ȼ���ˣ�
O(n*n)
**/

const int maxn=1e4+10;
const int inf=1e9;

struct node
{
    int x,y1,y2;
}d[maxn];


int main()
{
    int n,i,j,ymin=-inf,ymax=inf,xx,yy,a,b;
    double v,kmin,kmax;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d%d",&d[i].x,&d[i].y2,&d[i].y1);    ///y11<y2
        ymin=max(ymin,d[i].y1);
        ymax=min(ymax,d[i].y2);
    }
    ///��x��ƽ��(��n�ܴ󣬺���ķ����ᳬʱ������ʱ��������н⣬����ƭ����)
//    if (ymin<=ymax)
//    {
//        printf("%d %d %d %d",-1,ymin,0,ymin);
//        return 0;
//    }
    ///���߶�i���϶˵���Ϊֱ���ϵ�һ��
    for (i=1;i<=n;i++)
    {
        xx=d[i].x,yy=d[i].y2;
        kmin=-inf;
        kmax=inf;
        for (j=1;j<=n;j++)
            if (d[j].x<xx)
            {
                v=1.0*(yy-d[j].y2)/(xx-d[j].x);
                if (v>kmin)
                {
                    kmin=v;
                    a=j,b=0;
                }
    //            kmin=max(kmin,1.0*(yy-d[j].y2)/(xx-d[j].x));
                kmax=min(kmax,1.0*(yy-d[j].y1)/(xx-d[j].x));
                if (kmin>kmax)     ///!!!
                    break;
            }
            else if (d[j].x>xx)
            {
                v=1.0*(yy-d[j].y1)/(xx-d[j].x);
                if (v>kmin)
                {
                    kmin=v;
                    a=j,b=1;
                }
    //            kmin=max(kmin,1.0*(yy-d[j].y1)/(xx-d[j].x));
                kmax=min(kmax,1.0*(yy-d[j].y2)/(xx-d[j].x));
                if (kmin>kmax)
                    break;
            }
        if (kmin<=kmax)
        {
            if (n==1)
                printf("%d %d %d %d",-1,d[1].y1,0,d[1].y1);
            else if (b==0)
                printf("%d %d %d %d",d[i].x,d[i].y2,d[a].x,d[a].y2);
            else
                printf("%d %d %d %d",d[i].x,d[i].y2,d[a].x,d[a].y1);
            return 0;
        }
    }

    return 0;
}
/*
2
0 2 0
1 3 1

3
0 2 0
1 3 1
2 2 0

3
0 2 0
1 3 1
2 8 6

3
0 2 0
1 3 1
2 0 -1

5
121 123 1234
2134 12 35
123 541 21
125 125 54
54 12 35
*/
