#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;

/**
�����û�п��ǵ��ַ�Ϊ�ո�
**/

/**
�����û��˵������ķǿ��ַ����ĳ��ȣ�
�ַ�����ǰ��һ�����п��������õģ����ش洢

����ķ�����ÿ�ζ�����Ϊx(x>n,x������)���ַ�����������ַ����ĳ���Ϊx����֮ǰ�����ַ���������
**/

char str[maxn],s[10],c;

int main()
{
    int n,i,j,len;
    scanf("%d",&n);
    fgets(s,10,stdin);
    for (i=0;i<n;i++)
        str[i]=s[1];
    i=0;
    while (1)
    {
        scanf("%c",&c);
        if (c=='\n')
            break;
        str[i]=c;
        i=(i+1)%n;
    }
    j=(i-1+n)%n;
    while (i!=j)
    {
        printf("%c",str[i]);
        i=(i+1)%n;
    }
    printf("%c",str[i]);
    return 0;
}
/*
15
I love GPLT
*/
